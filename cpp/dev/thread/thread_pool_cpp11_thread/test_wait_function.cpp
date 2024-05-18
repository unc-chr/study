/*================================================================
*   Copyright (C) 2024 Goldman Ltd. All rights reserved.
*   
*   File：test1.cpp
*   Author：leekaihua
*   Date：2024年03月30日
*   Brife：
*



*/

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
 
std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

using std::cout;
using std::endl;
 
void worker_thread()
{
    // wait until main() sends data
    std::unique_lock<std::mutex> lk(m);
    cout << "worker_thread get mutex" << endl;
    cv.wait(lk, []{ cout << "working waitting..." << endl; return ready; });
    cout << "worker wait done" << endl;
 
    // after the wait, we own the lock
    std::cout << "Worker thread is processing data\n";
    data += " after processing";
 
    // send data back to main()
    processed = true;
    std::cout << "Worker thread signals data processing completed\n";
 
    // manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for details)
    lk.unlock();
    cout << "worker thread release mutex" << endl;
    cv.notify_one();
    cout << "worker thread notify one" << endl;
}
 
int main()
{
    std::thread worker(worker_thread);
 
    data = "Example data";
    // send data to the worker thread
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::lock_guard<std::mutex> lk(m);
        cout << "main thread get mutex" << endl;
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }
    cout << "main thread release mutex" << endl;
    cv.notify_one();
    cout << "notify done" << endl;
 
    // wait for the worker
    {
        std::unique_lock<std::mutex> lk(m);
        cout << "main thread get mutex again" << endl;
        cv.wait(lk, []{ cout << "main thread 2 waitting..." << endl; return processed; });
        cout << "main wait done" << endl;
    }
    cout << "main thread release mutex again" << endl;
    std::cout << "Back in main(), data = " << data << '\n';
 
    worker.join();
}