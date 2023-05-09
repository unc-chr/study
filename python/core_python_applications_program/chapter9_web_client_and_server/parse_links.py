#!usr/bin/env python
# -*- coding:utf-8 -*-

#================================================================
#   Copyright (C) 2021 Goldman Ltd. All rights reserved.
#   
#   File：parse_links.py
#   Author：leekaihua
#   Date：2021年10月28日
#   Brife：
#
#================================================================

import sys
from HTMLParser import HTMLParser
from cStringIO import StringIO
from urllib2 import urlopen
from urlparse import urljoin

from BeautifulSoup import BeautifulSoup, SoupStrainer
from html5lib import parse, treebuilders

reload(sys)
sys.setdefaultencoding("utf-8")

URL2file = {
    "https://www.znlzd.com/bqg/1403/": "santi"
}

def output(x):
    """
    """
    print "\n".join(sorted(set(x)))


def simpleBS(url, f):
    """
    """
    print "fuck"
    print type(f)
    output(urljoin(url, x["href"]) for x in BeautifulSoup(f).findAll("a") if x.get("href"))


def fasterBS(url, f):
    """
    """
    output(urljoin(url, x["href"]) \
            for x in BeautifulSoup(f, parseOnlyThese=SoupStrainer("a")) \
            if "href" in x)


def htmlparser(url, f):
    """
    """
    class AnchorParser(HTMLParser):
        def handle_starttag(self, tag, attrs):
            if tag != "a":
                return
            if not hasattr(self, "data"):
                self.data = []
            for attr in attrs:
                if attr[0] == "href":
                    self.data.append(attr[1])
    
    parser = AnchorParser()
    parser.feed(f.read())
    output(urljoin(url, x) for x in parser.data)


def html5libparse(url, f):
    """
    """
    output(urljoin(url, x.attributes["href"]) \
            for x in parse(f) \
            if isinstance(x, treebuilders.simpletree.Element) and x.name == "a")


def process(url, data):
    """
    """
    print "\n *** simple BS"
    simpleBS(url, data)
    data.seek(0)

    print "\n *** faster BS"
    fasterBS(url, data)
    data.seek(0)

    print "\n *** HTMLParser"
    htmlparser(url, data)
    data.seek(0)

    print "\n *** HTML5lib"
    html5libparse(url, data)


def main():
    """
    """
    for url, fname in URL2file.iteritems():
        print url, fname
        f = urlopen(url)
        page_content = f.read()
        data = StringIO(page_content)
        with open(fname, "w") as f_writer:
            f_writer.write(page_content)
        f.close()

        process(url, data)


if __name__ == "__main__":
    main()