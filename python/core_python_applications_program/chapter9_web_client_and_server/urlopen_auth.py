#!usr/bin/env python
# -*- coding:utf-8 -*-

#================================================================
#   Copyright (C) 2021 Goldman Ltd. All rights reserved.
#   
#   File：urlopen_auth.py
#   Author：leekaihua
#   Date：2021年10月28日
#   Brife：
#
#================================================================

import urllib2
import sys

reload(sys)
sys.setdefaultencoding("utf-8")


LOGIN = "wesley"
PASSWORD = "you'll Never Guess"
URL = "http://localhost"
REALM = "Secure Archive"


def handler_version(url):
    """
    """
    print "handler_version"
    from urlparse import urlparse
    hdlr = urllib2.HTTPBasicAuthHandler()
    hdlr.add_password(REALM, urlparse(url)[1], LOGIN, PASSWORD)
    opener = urllib2.build_opener(hdlr)
    urllib2.install_opener(opener)
    return url


def request_version(url):
    """
    """
    from base64 import encodestring
    req = urllib2.Request(url)
    b64str = encodestring("%s:%s" % (LOGIN, PASSWORD))[:-1]
    print "b64str content: %s" % b64str
    req.add_header("Authorization", "Basic %s" % b64str)
    return req


def main():
    """
    """
    for func_type in ("handler", "request"):
        print "*** Using %s:" % func_type.upper()
        url = eval("%s_version" % func_type)(URL)
        f = urllib2.urlopen(url)
        print f.readline()
        f.close()


if __name__ == "__main__":
    main()
