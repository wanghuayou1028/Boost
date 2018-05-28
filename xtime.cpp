// g++ -I /usr/include -L /usr/lib xtime.cpp -lboost_system -lboost_thread -o xtime
#include <boost/thread/thread.hpp>
#include <boost/thread/xtime.hpp>
#include <iostream>

int main()
{
    boost::xtime xt;
    boost::xtime_get(&xt, boost::TIME_UTC_);    // initialize xt with current time
    xt.sec += 1;    // change xt to next second
    boost::thread::sleep(xt);    // do sleep

    std::cout << "1 second sleep over." << std::endl;

    return 0;
}