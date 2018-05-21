/**
 * author: wanghuayou
 * email: upcwanghy@163.com
 * 
 * the core implementation of lexical_cast
 * int d = boost::lexical_cast<int>("123")
 * the implementation:
 *  int d;
 *  std::stringstream s;
 *  s << "123";
 *  s >> d;
 */

#include <iostream>
#include <boost/lexical_cast.hpp>

int main(){
    // in c: atoi, atod, atol, atold
    using boost::lexical_cast;
    int a = boost::lexical_cast<int>("123456");
    std::cout << "a = " << a << std::endl;
    double b = boost:: lexical_cast<double>("123.12");
    std::cout << "b = " << b << std::endl;
    long double c = lexical_cast<long double>("123.12");
    std::cout << "c = " << c << std::endl;

    // in c: sprintf
    using std::string;
    const double d = 123.12;
    string s = boost::lexical_cast<string>(d);
    std::cout << "d = " << d << std::endl;

    // boost: exception: try, catch
    using std::cout;
    using std::endl;
    int i;
    try{
        i = boost::lexical_cast<int>("abc");
    }
    catch(boost::bad_lexical_cast & e){
        cout << e.what() << endl;
        return 1;
    }
    cout << "i = " << i << endl;

    return 0;
}

