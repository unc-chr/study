#!usr/bin/env python
# -*- coding:utf-8 -*-

#================================================================
#   Copyright (C) 2021 Goldman Ltd. All rights reserved.
#   
#   File：crawl.py
#   Author：leekaihua
#   Date：2021年10月28日
#   Brife：
#
#================================================================

import cStringIO
import sys
import formatter
import httplib
import os
import urllib
import urlparse
from htmllib import HTMLParser
import logging

reload(sys)
sys.setdefaultencoding("utf-8")

logging.basicConfig(
    level = logging.DEBUG,
    format = '%(asctime)s %(filename)s [line:%(lineno)d] %(levelname)s %(message)s'
    )

class Retrieve(object):
    """
    """
    def __init__(self, url):
        """ init
        """
        self.url, self.file = self.get_file(url)
    
    def get_file(self, url, default_type="index.html"):
        """ create usable local filename from URL
        """
        parsed = urlparse.urlparse(url)
        host = parsed.netloc.split("@")[-1].split(":")[0]
        filepath = "%s%s" % (host, parsed.path)
        # 解析文件类型, 如果没有则使用默认的类型
        if not os.path.splitext(parsed.path)[1]:
            filepath = os.path.join(filepath, default_type)
        linkdir = os.path.dirname(filepath)
        # 非目录，可能是目录不存在，或者是文件类型
        if not os.path.isdir(linkdir):
            if os.path.exists(linkdir):
                os.unlink(linkdir)
            os.makedirs(linkdir)
        return url, filepath

    def download(self):
        """ download url to specific named file
        """
        try:
            retval = urllib.urlretrieve(self.url, self.file)
        except (IOError, httplib.InvalidURL) as e:
            retval = (('*** ERROR: bad URL "%s":%s' % (self.url, e)),)
        return retval

    def parse_link(self):
        """ parsed out the links found in downloaded HTML file
        """
        f = open(self.file, "r")
        data = f.read()
        f.close()

        parser = HTMLParser(formatter.AbstractFormatter(formatter.DumbWriter(cStringIO.StringIO())))
        parser.feed(data)
        parser.close()
        return parser.anchorlist


class Crawler(object):
    """
    """
    count = 0
    def __init__(self, url):
        """
        """
        self.seen = set()
        self.q = [url]
        parsed = urlparse.urlparse(url)
        host = parsed.netloc.split("@")[-1].split(":")[0]
        self.dom = '.'.join(host.split(".")[-2:])

    def _is_proper_link(self, link, url, media=False):
        """ is proper url to add wait queue or not 
        """
        if link.startswith("mailto"):
            print "... discarded, mailto link"
            return False
        if not media:
            ftype = os.path.splitext(link)[1]
            if ftype in (".mp3", ".mp4", ".m4v", ".wav"):
                print "... discarded, media file"
                return False
        if not link.startswith("http://"):
            link = urlparse.urljoin(url, link)
        print "*", link,
        if link not in self.seen:
            if self.dom not in link:
                print '... discarded, not in domain'
            else:
                if link not in self.q:
                    self.q.append(link)
                    print '.. new, add to Q'
                    return False
                else:
                    print '... discarded, already in Q'
        else:
            print '... discard, already processed'
        return False

    def get_page(self, url, media=False):
        """
        """
        r = Retrieve(url)
        fname = r.download()[0]
        if fname[0] == "*":
            print fname, "... skipping parse"
            return

        Crawler.count += 1
        print "\n(%d)" % Crawler.count
        print "URL:%s" % url
        print "FILE:%s" % fname
        self.seen.add(url)

        # 只处理在web页面中发现的链接，非web页面跳过
        ftype = os.path.splitext(fname)[1]
        if ftype not in (".htm", ".html"):
            return 
        for link in r.parse_link():
            logging.debug("try link in web:%s" % link)        
            if not self._is_proper_link(link, url, media=False):
                continue

    def go(self, media=False):
        """
        """
        while self.q:
            url = self.q.pop()
            self.get_page(url, media)
            # 成功处理完100个链接，就停止
            if len(self.seen) > 2000:
                break

def main():
    if len(sys.argv) > 1:
        url = sys.argv[1]
    else:
        try:
            url = raw_input('Enter starting URL:')
        except (KeyboardInterrupt, EOFError):
            url = ""

    if not url:
        return
    if not url.startswith('http://') \
            and not url.startswith("ftp://") \
            and not url.startswith("https://"):
        url = "http://%s/" % url

    robot = Crawler(url)
    robot.go()

if __name__ == "__main__":
    main()