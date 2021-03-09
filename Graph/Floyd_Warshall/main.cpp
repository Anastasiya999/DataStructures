#include <iostream>
#include"DirectedGraph.hpp"
using namespace std;

int main() {

   DirectedGraph<int>graph;
   cout<<"Algorytm Floyda Warshalla"<<endl;
   graph.Floyd_Warschal();

    return 0;
}   
