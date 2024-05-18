/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：bank.cpp
*   Author：leekaihua
*   Date：2023年03月19日
*   Brife：
*



*/

#include <cstdlib>
#include <ctime>
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    std::srand(std::time(0));

    // 初始化银行顾客的等待队列
    cout << "Case Study: Bank of Heather Automatic Teller" << endl;
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);

    // 初始化模拟时间：指定小时数，对应的分钟数就是模拟的次数。
    // 模拟的粒度是分钟。
    cout << "Enter the number of simulation hours: ";
    in hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;

    // 顾客到达的平均时间间隔
    // 用于模拟每间隔指定时间，大约有一位顾客到达
    cout << "Enter the average number of customer per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;

    for (int cycle = 0; cycle < cyclelimit; cycle++) {
        // 以 分钟 为粒度进行队列消费模拟，当前分钟开始
        if (newcustomer(min_per_cust)) {
            // 客户来到，但是队列已满，客户离开
            if (line.isfull()) {
                turnaways++;
            // 客户来到，队列有空间，客户排队。记录到达时间（分钟）
            } else {
                customers++;
                temp.set(cycle);
                line.enqueue(temp);
            }
        }
        // 判断在这一分钟时，队首的客户是否应该出队了
        // 如果等待时间已到，那么应该出队，记录客户的等待时间即：当前分钟 - 客户到达的时间
        // 并将等待时间计入队列总的等待时间
        // 下一位客户的等待时间是：当前客户交易花费的时间
        // 服务客户数量+1
        if (wait_time <= 0 && !line.isempty()) {
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        // 当前分钟过完了，等待时间-1
        if (wait_time > 0) {
            wait_time--;
        }
        sum_line += line.queuecount();
    }

    if (customers > 0) {
        cout << "customers accepted: " << customers << endl;
        cout << " customers served: " << served << endl;
        cout << "      turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << " average wait time: " 
            << (double) line_wait / served <<  "minutes" << endl;
    } else {
        cout << "No customers!" << endl;
    }

    cout << "Done!" << endl;
    return 0;
}

// 通过概率判断，在某一分钟内是否有顾客到来
bool newcustomer(double x) {
    return (std::rand() * x / RAND_MAX < 1);
}