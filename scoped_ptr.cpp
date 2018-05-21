#include <iostream>
#include <boost/scoped_ptr.hpp>

#include <string>
#include <boost/scoped_array.hpp>

#include <boost/config.hpp>
#include <boost/detail/lightweight_test.hpp>

using std::cout;
using std::endl;
using boost::scoped_ptr;

// noncopyable
class implementation{
public:
    ~implementation(){ cout << "destroying implementation" << endl;}
    void do_something() { cout << "did something " << endl;}
};

void test(){
    boost::scoped_ptr<implementation> impl(new implementation());
    impl->do_something();
}

void test1(){
    // test scoped_ptr with a built-in type
    long* lp = new long;
    boost::scoped_ptr<long> sp(lp);
    BOOST_TEST( sp.get() == lp );
    BOOST_TEST( lp == sp.get() );
    BOOST_TEST( &*sp == lp );

    *sp = 1234568901L;
    BOOST_TEST( *sp == 1234568901L );
    BOOST_TEST( *lp == 1234568901L );

    long* lp2 = new long;
    boost::scoped_ptr<long> sp2(lp2);

    sp.swap(sp2);
    BOOST_TEST( sp.get() == lp2 );
    BOOST_TEST( sp2.get() == lp );

    sp.reset(NULL);
    BOOST_TEST( sp.get() == NULL);
}

int main()
{
    cout << "test begin..." << endl;
    test();

    test1();
    cout << "test end." << endl;
    return 0;
}
