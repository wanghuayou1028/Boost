#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <iostream>

boost::mutex io_mutex;

void count()    // worker function
{
    for (int i = 0; i < 10; ++i)
    {
        boost::mutex::scoped_lock lock(io_mutex);
        std::cout << i << std::endl;
    }
}

struct count1
{
    count1(int id) : id(id) { }

    void operator()()
    {
        for (int i = 0; i < 10; ++i)
        {
            boost::mutex::scoped_lock lock(io_mutex);        // lock io, will be explained soon.
            std::cout << id << ": " << i << std::endl;
        }
    }

    int id;
};

struct count2
{
    static int num;
    int id;

    count2() : id(num++) {}

    int do_count(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            boost::mutex::scoped_lock lock(io_mutex);
            std::cout << id << ": " << i << std::endl;
        }
        return id;
    }
};
int count2::num = 1;



int main(int argc, char* argv[])
{
    // create a working thread by transferring a working function
    boost::thread thrd1(&count);
    boost::thread thrd2(&count);
    thrd1.join();
    thrd2.join();

    // create a working thread by transferring a functor object
    boost::thread thrd3(count1(1));
    boost::thread thrd4(count1(2));
    thrd3.join();
    thrd4.join();

    // boost bind
    count2 c1;
    boost::thread thrd5(boost::bind(&count2::do_count, &c1, 10));
    thrd5.join();

    return 0;
}
