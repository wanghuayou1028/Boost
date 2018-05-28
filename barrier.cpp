
#include <boost/thread/thread.hpp>
#include <boost/thread/barrier.hpp>

int i = 0;
boost::barrier barr(3); // call barr.wait 3*n times will release all threads in waiting

void thread()
{
    ++i;
    std::cout << "i = " << i << std::endl;
    barr.wait();
}

int main(){
    boost::thread thrd1(&thread);
    boost::thread thrd2(&thread);
    boost::thread thrd3(&thread);

    thrd1.join();
    thrd2.join();
    thrd3.join();

    return 0;
}