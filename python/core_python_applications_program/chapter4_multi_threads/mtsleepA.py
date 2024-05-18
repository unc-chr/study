#!/usr/bin/env python

import thread
from time import sleep, ctime


def loop0():
	print 'start loop 0 at:', ctime()
	sleep(4)
	print 'loop 0 done at:', ctime()
	print


def loop1():
	print 'start loop 1 at:', ctime()
	sleep(2)
	print 'loop 1 done at:', ctime()
	print


def main():
	print 'starting at:', ctime()
	thread.start_new_thread(loop0, ())
	thread.start_new_thread(loop1, ())
	# here sleep 6s to wait all threads execute completely, 
	# or threads maybe exit accidently.
	sleep(6)
	print 'all DONE at:', ctime()
	print
	

if __name__ == "__main__":
	main()
