#include <iostream>
#include <vector>
// #include <init/node.hpp>
// #include <init/vector.hpp>
// #include <init/edge.hpp>
#include <init/movement.hpp>

using namespace std;

int main () {
    cout << "\n\n";
    
    Node a(0, 0, Type::anchor);
    Node b(2, 0, Type::anchor);
    Node c(0, 2, Type::anchor);
    Node d(0, -2, Type::anchor);

    a.addEdge(&b, 3);
    a.addEdge(&c, 3);
    a.addEdge(&d, 3);
    
    Movement m(&a);

    double move;
    int cont = 0;
    a.print();
    do {
        move = m.move();
        a.print();
        cout << cont << endl;
        cont++;
    } while (move > 0.00000001);
    

    return 0;
}
