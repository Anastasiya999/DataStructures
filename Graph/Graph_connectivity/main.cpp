#include <iostream>
#include"UndirectedGraph.hpp"
#include "DirectedGraph.hpp"
using namespace std;
int main() {
    cout<<"Directed graph"<<endl;
    DirectedGraph<int>graph_a;
    cout<<"connected: "<<graph_a.isConnected()<<endl;

    cout<<"Undirected graph"<<endl;
    UndirectedGraph<int>graph_b;
    cout<<"connected: "<<graph_b.isConnected()<<endl;
    

    return 0;
}
