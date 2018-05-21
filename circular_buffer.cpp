#include <iostream>
#include <boost/circular_buffer.hpp>

using std::cout;
using std::endl;
using boost::circular_buffer;

int main(){
    boost::circular_buffer<int> cb(3);

    // insert some elements into the buffer
    cb.push_back(1);
    cb.push_back(2);
    cb.push_back(3);
    
    int a = cb[0];
    int b = cb[1];
    int c = cb[2];
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    // the buffer is full now, pushing subsequent
    // elements will overwrite the front-most elements
    cb.push_back(4);
    cb.push_back(5);

    a = cb[0]; // a == 3
    b = cb[1]; // b == 4
    c = cb[2]; // c == 5
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    // elements can be popped from either the front or the back
    cb.pop_back(); // 5 is removed
    cb.pop_front(); // 3 is removed

    int d = cb[0]; // d == 4
    cout << "d = " << d << endl;

    return 0;
}