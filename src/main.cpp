#include <iostream>
#include <vector>
#include <init/movement.hpp>
#include <init/system.hpp>
#include <init/dataaccess/instance_read.hpp>
#include <init/test.hpp>

using namespace std;


int main () {
    cout << "\n\n";
    
    Instance instance = readInstance("4.2_loc.txt");

    System s(instance);

    s.solve();
    
    // instance.printNodes();
    vector<Node*> a = instance.getAnchors();
    for(int i = 0; i <a.size(); i++) {
        a[i]->printGeo();
    }
    vector<Node*> anchors = instance.getNodes();

    vector<Node> result = readResult("4.2_sol.txt");
    int cont = 0;
    cout << "Id\ttype\tplaceds\tanchors\terro\n";
    for (int i = 0; i < anchors.size(); ++i) {
        Vector v (anchors[i], &(result[i]));
        if(v.getNorm() < 0.01) cont ++;
        else {
            // cout << anchors[i]->getId() << "\t" << anchors[i]->getType() << "\t" << anchors[i]->getNPlaceds() << "\t" << anchors[i]->getNAnchors() << "\t" << v.getNorm() <<"\n";
            anchors[i]->printEdgesGeo();
            // wait;
        }
    }

    cout << "\nNós corretos " << cont << "\n\n";

    // anchors[77]->inRange(anchors[89], 0. );
    // anchors[79]->printEdgesGeo();
    // anchors[70]->printEdgesGeo();
    
    printResult (anchors, "resultado-4.2.txt");

    return 0;
}
