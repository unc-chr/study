#!usr/bin/env python
# -*- coding:utf-8 -*-

import time
import random
import threading
import Queue
import myThread


store_queue = Queue.Queue(32)
goods = "iphone"

def write_queue():
    """ write_queue
    """
    store_queue.put(goods)
    print "store now has %d %s" % (store_queue.qsize(), goods)


def read_queue():
    """
    """
    try:
        store_queue.get(timeout=3)
    except Exception as e:
        print "sorry no %s is available!" % goods
    print "store now has %d %s " % (store_queue.qsize(), goods)

def writer(goods_num):
    """ writer
    """
    for i in xrange(goods_num):
        write_queue()
        time.sleep(random.randrange(1,4))


def reader(goods_num):
    """ reader
    """
    for i in xrange(goods_num):
        read_queue()
        time.sleep(random.randrange(1,4))

def main():
    """ main
    """
    print "trade begin at:", time.ctime()
    write_good_num = random.randint(2, 5)
    read_good_num = random.randint(1, 4)
    print "%d %s is needed!" % (read_good_num, goods)
    print "%d %s is ready to produce!" % (write_good_num, goods)

    write_thread = myThread.MyThread(writer, args=(write_good_num,), name=writer.__name__)
    read_thread = myThread.MyThread(reader, args=(read_good_num,), name=reader.__name__)
    thread_list = []
    thread_list.append(write_thread)
    thread_list.append(read_thread)

    for item in thread_list:
        item.start()

    for item in thread_list:
        item.join()

    print "trade end at:", time.ctime()


if __name__ == "__main__":
    main()
