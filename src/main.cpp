// #include <iostream>
#include <vector>
#include <init/node/node.hpp>

using namespace std;

int main () {
    Node a(0.5, 0.6, Type::anchor);
    cout << a.get(Axis::x) << endl;

    a.setType(Type::placed);
    cout << a.getType() << endl;
    return 0;
}
