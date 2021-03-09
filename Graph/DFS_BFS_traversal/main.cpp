#include <iostream>
#include"UndirectedGraph.hpp"
using namespace std;
int main() {

    UndirectedGraph<int>graph;
    cout<<"BFS"<<endl;
    graph.print_BFS(1);
    cout<<endl;
    cout<<"DFS"<<endl;
    graph.print_DFS(1);
    return 0;
}

