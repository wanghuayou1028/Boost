// compile command: 
// g++ -I /usr/include -L /usr/lib boost_thread.cpp -lboost_system -lboost_thread -o boost_thread

#include <boost/thread.hpp>
#include <iostream>

void hello(){
    std::cout << "Hello world, I'm a thread!" << std::endl;
    for(int i = 0; i < 10; i++)
        std::cout << "i = " << i << std::endl;
}

void thread1(){
    std::cout << "thread1 is working!" << std::endl;
    for(int j = 0; j < 10; j++)
        std::cout << "j = " << j << std::endl;
}
void thread2(){
    std::cout << "thread2 is working!" << std::endl;
    for(int k = 0; k < 10; k++)
        std::cout << "k = " << k << std::endl;
}
 
int main()
{
    boost::thread thrd(&hello); // create a thread
    boost::thread thread_1(&thread1);
    boost::thread thread_2(&thread2);
    thrd.join(); // wait for the end of the thread
    thread_1.join();
    thread_2.join();

    return 0;
}
