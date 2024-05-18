#!usr/bin/env python
# -*- coding:utf-8 -*-

import time
from random import randrange
from atexit import register
import threading

MAX = 5
lock = threading.Lock()
candytray = threading.BoundedSemaphore(MAX)

def refill():
    lock.acquire()
    print "refilling candy..."
    try:
        candytray.release()
    except ValueError:
        print "full, skipping"
    else:
        print 'OK'
    lock.release()


def buy():
    lock.acquire()
    print 'Buying candy...'
    if candytray.acquire(False):
        print "OK"
    else:
        print "empty, skipping"
    lock.release()


def producer(loops):
    for i in xrange(loops):
        refill()
        time.sleep(randrange(3))


def costumer(loops):
    for i in xrange(loops):
        buy()
        time.sleep(randrange(3))


def main():
    print "starting at:", time.ctime()
    nloops = randrange(2, 6)
    num_costumer = randrange(nloops, nloops+MAX+2)
    print "%d candy is needed!" % num_costumer
    print 'THE CANDY MACHINE (full with %d bars)!' % MAX
    threading.Thread(target=costumer, args=(num_costumer,)).start()
    print "%d candy is ready to support!" % nloops
    threading.Thread(target=producer, args=(nloops,)).start()


@register
def _atexit():
    print "all DONE at:", time.ctime()


if __name__ == "__main__":
    main()
