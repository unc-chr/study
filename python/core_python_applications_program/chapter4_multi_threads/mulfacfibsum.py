#!usr/bin/env python
# compare single thread to multiple threads performance in sum, fac, fib functions.

import threading
from myThread import MyThread
from time import sleep, ctime

def fib(x):
	""" fib
	"""
	if x < 2:
		return 1
	return fib(x-1) + fib(x-2)


def fac(x):
	""" fac
	"""
	if x < 2:
		return 1
	return x * fac(x-1)


def sum_diy(x):
	""" sum
	"""
	if x < 2:
		return 1
	return x + sum_diy(x-1)


def single_thread():
	"""
	"""
	print 'single thread start...'
	for i in range(len(func)):
		print 'starting ', func[i].__name__, ' at: ', ctime()
		print func[i](n)
		print 'end ', func[i].__name__, ' at: ', ctime()
	print 'single thread end!!!'
	

def multi_thread():
	"""
	"""
	threads = []
	for i in range(len(func)):
		t = MyThread(func[i], (n,), func[i].__name__)
		threads.append(t)

	for i in range(len(threads)):
		threads[i].start()

	for i in range(len(threads)):
		threads[i].join()
		print threads[i].get_result()
		

def main():
	""" main
	"""
	# single_thread()	
	multi_thread()


func = [fib, fac, sum_diy]
n = 40


if __name__ == "__main__":
	main()
