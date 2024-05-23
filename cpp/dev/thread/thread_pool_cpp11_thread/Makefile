

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：Makefile
#   Author：leekaihua
#   Date：2024年03月28日
#   Brife：
#
#================================================================


main: main.cpp
	g++ main.cpp -std=c++11 -Wl,--no-as-needed -lpthread -o main.out
test_param: test_param.cpp
	g++ test_param.cpp -std=c++11 -Wl,--no-as-needed -lpthread -o test_param.out
test_join: test_join.cpp
	g++ test_join.cpp -std=c++11 -Wl,--no-as-needed -lpthread -o test_join.out
test_detach: test_detach.cpp
	g++ test_detach.cpp -std=c++11 -Wl,--no-as-needed -lpthread -o test_detach.out
test_joinable: test_joinable.cpp
	g++ test_joinable.cpp -std=c++11 -Wl,--no-as-needed -lpthread -o test_joinable.out
test_multi_thread_print: test_multi_thread_print.cpp
	g++ test_multi_thread_print.cpp -std=c++11 -Wl,--no-as-needed -lpthread -o test_multi_thread_print.out
test_errors: test_errors.cpp
	g++ test_errors.cpp -std=c++11 -Wl,--no-as-needed -lpthread -o test_errors.out
test_mutex: test_mutex.cpp
	g++ test_mutex.cpp -std=c++11 -Wl,--no-as-needed -lpthread -o test_mutex.out
test_dead_mutex: test_dead_mutex.cpp
	g++ test_dead_mutex.cpp -std=c++11 -Wl,--no-as-needed -lpthread -o test_dead_mutex.out
test_lock_guard: test_lock_guard.cpp
	g++ test_lock_guard.cpp -std=c++11 -Wl,--no-as-needed -lpthread -o test_lock_guard.out
log: log.cpp
	g++ log.cpp -std=c++11 -Wl,--no-as-needed -lpthread -o log.out
test_condition_variable: test_condition_variable.cpp
	g++ test_condition_variable.cpp -std=c++11 -Wl,--no-as-needed -lpthread -o test_condition_variable.out
test_thread_pool: test_thread_pool.cpp
	g++ test_thread_pool.cpp -std=c++11 -Wl,--no-as-needed -lpthread -o test_thread_pool.out
thread_pool: thread_pool.cpp
	g++ thread_pool.cpp -std=c++11 -Wl,--no-as-needed -lpthread -o thread_pool.out
test_async_future: test_async_future.cpp
	g++ test_async_future.cpp -std=c++11 -Wl,--no-as-needed -lpthread -o test_async_future.out
test_async_promise: test_async_promise.cpp
	g++ test_async_promise.cpp -std=c++11 -Wl,--no-as-needed -lpthread -o test_async_promise.out
test_atomic: test_atomic.cpp
	g++ test_atomic.cpp -std=c++11 -Wl,--no-as-needed -lpthread -o test_atomic.out

.PHONY: clean
clean:
	rm *.out