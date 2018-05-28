#include <boost/bind.hpp>
void ThreadGroup()
{
    boost::thread_group grp;
    grp.create_thread( boost::bind(Func, 10));
    A a;
    grp.add_thread(new boost::thread(&A::Func, &a, 100));
    grp.add_thread(new boost::thread(B(100)));
    grp.join_all();
}