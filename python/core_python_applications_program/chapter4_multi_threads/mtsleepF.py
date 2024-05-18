#!usr/bin/env python
# -*- coding:utf-8 -*-

import time
from random import randrange
import threading
from atexit import register

loops = (randrange(2, 6) for x in xrange(randrange(3, 7)))

class CleanOutputSet(set):
    def __str__(self):
        return ', '.join(x for x in self)

remain_thread = CleanOutputSet()

def loop(pause):
    """ loop
    """
    my_name = threading.currentThread().name
    remain_thread.add(my_name)
    print "[%s] start %s" % (time.ctime(), my_name)
    time.sleep(pause)
    remain_thread.remove(my_name)
    print "[%s] end %s %d secs" % (time.ctime(), my_name, pause)
    print "remaining:%s" % (remain_thread or "None")
    

def main():
    print "all begin at:", time.ctime()
    for item in loops:
        threading.Thread(target=loop, args=(item,)).start()
    

@register
def _atexit():
   print "all DONE at:", time.ctime()


if __name__ == "__main__":
    main()
