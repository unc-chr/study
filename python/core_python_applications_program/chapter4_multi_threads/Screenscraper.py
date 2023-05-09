#!usr/bin/env python
# -*- coding:utf-8 -*-

import re
import random
import time
from atexit import register
import threading
import urllib2

REGEX = re.compile('#([\d,]+) in Books ')
AMZN = 'https://www.amazon.com/dp/'
ISBNs = {
	'0132269937': 'Core Python Programming',
	'0132356139': 'Python Web Development with Django',
	'0137143419': 'Python Fundamentals'
}

user_agent_list = [
    {"User-Agent": ("Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.1"
        " (KHTML, like Gecko) Chrome/14.0.835.163 Safari/535.1")},
    {"User-Agent": ("Mozilla/5.0 (Windows NT 6.1; WOW64; rv:6.0)" 
        " Gecko/20100101 Firefox/6.0")},
    {"User-Agent": ("Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/534.50"
        " (KHTML, like Gecko) Version/5.1 Safari/534.50")},
    {"User-Agent": ("Opera/9.80 (Windows NT 6.1; U; zh-cn)"
        " Presto/2.9.168 Version/11.50")}
]

def get_ranking(isbn):
    ua = random.choice(user_agent_list)
    url = "%s%s" % (AMZN, isbn)
    print "url:%s" % url
    request = urllib2.Request(url, headers = ua)
    page = urllib2.urlopen(request)
    data = page.read()
    page.close()
    return REGEX.findall(data)[0]


def _show_ranking(isbn):
	print "- %r ranked %s" % (ISBNs[isbn], get_ranking(isbn))


def main():
	print 'At', time.ctime(), ' on Amazon...'
	for isbn in ISBNs:
		_show_ranking(isbn)


@register
def _atexit():
	print 'all DONE at:', time.ctime()


if __name__ == "__main__":
	main()
