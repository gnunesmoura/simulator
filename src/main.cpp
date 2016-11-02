#include <iostream>
#include <vector>
#include <init/node.hpp>
#include <init/vector.hpp>

using namespace std;

int main () {
    cout << "\n\n";
    
    Node a(0, 0, Type::anchor);
    Node b(2, 0, Type::anchor);

    Vector v1 (a, b, 2);
    v1.print();
    Vector v2 (0, 2);
    v2.print();
    Vector v3;
    v3 = v1 + v3;
    v3 = v3*8;
    v3.print();
    return 0;
}
