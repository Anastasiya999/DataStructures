#include <iostream>
#include "DirectedGraph.hpp"
using namespace std;
int main() {
    cout<<"Directed graph"<<endl;
    DirectedGraph<int>graph;
    graph.TopolSort();

    return 0;
}
