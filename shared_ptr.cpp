#include <iostream>
#include <boost/shared_ptr.hpp>

using std::cout;
using std::endl;
using boost::shared_ptr;

class implementation{
    public:
    ~implementation(){ 
        cout << "destroying implementation " << endl;
    }
    void do_something() {
        cout << "did something" << endl;
    }
};

void test(){
    boost::shared_ptr<implementation> sp1(new implementation());
    cout << "the sample now has " << sp1.use_count() << " references" << endl;
    boost::shared_ptr<implementation> sp2 = sp1;
    cout << "the smaple now has " << sp2.use_count() << " references" << endl;

    sp1.reset();
    cout << "after reset sp1, the sample now has " << sp2.use_count() << " references" << endl;

    sp2.reset();
    cout << "after reset sp2 " << endl;
}

int main()
{
    test();
    return 0;
}
