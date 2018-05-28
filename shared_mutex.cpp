#include <boost/ref.hpp>
#include <boost/thread/thread.hpp>  
#include <string>  
#include <iostream>
#include <stdio.h>
using namespace boost;  
  
int g_num = 10;      //全局变量，写者改变该全局变量，读者读该全局变量  
shared_mutex s_mu;   //全局shared_mutex对象  
  
//读线程  
void read_(std::string &str)  
{  
    const char* c = str.c_str();  
    while (1)  
    {  
        {  
            shared_lock<shared_mutex> m(s_mu);    //读锁定，shared_lock  
            printf("线程%s进入临界区，global_num = %d\n", c, g_num);  
            boost::this_thread::sleep(boost::posix_time::seconds(1));    //sleep 1秒，给足够的时间看其他线程是否能进入临界区  
            printf("线程%s离开临界区...\n", c);  
        }  
        boost::this_thread::sleep(boost::posix_time::seconds(1));   //读线程离开后再slpp 1秒（改变这个值可以看到不一样的效果）  
    }  
}  
  
//写线程  
void writer_(std::string &str)  
{  
    const char* c = str.c_str();  
    while (1)  
    {  
        {  
            unique_lock<shared_mutex> m(s_mu);    //写锁定，unique_lock  
            ++g_num;  
            printf("线程%s进入临界区，global_num = %d\n", c, g_num);  
            boost::this_thread::sleep(boost::posix_time::seconds(1));    //sleep 1秒，让其他线程有时间进入临界区  
            printf("线程%s离开临界区...\n", c);  
        }  
        boost::this_thread::sleep(boost::posix_time::seconds(2));   //写线程离开后再slpp 2秒，这里比读线程多一秒是因为如果这里也是1秒，那两个写线程一起请求锁时会让读线程饥饿  
    }  
}  
int main()  
{  
    std::string r1 = "read_1";  
    std::string r2 = "read_2";  
    std::string w1 = "writer_1";  
    std::string w2 = "writer_2";  
  
    boost::thread_group tg;  
    tg.create_thread(bind(read_, boost::ref(r1)));   //两个读者  
    tg.create_thread(bind(read_, boost::ref(r2)));  
  
    tg.create_thread(bind(writer_, boost::ref(w1)));  //两个写者  
    tg.create_thread(bind(writer_, boost::ref(w2)));  
    tg.join_all();  
  
    return 0;  
} 