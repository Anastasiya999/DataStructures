#pragma once
#include<vector>
#include"Edge.hpp"

using namespace std;
template<typename T>
class Graph{
private:
    int countId=0;
    vector<Node<T>> nodes;
    vector<Edge<T>>edges;
public:
   bool addNode(Node<T>);
   virtual bool addEdge(Node<T>,Node<T>,T);
   virtual vector<Node<T>> getNeighbours(T)=0;
   vector<Node<T>>&getNodes();
   int getIdByValue(T);
   int getIndex(T);

};

template<typename T>
bool Graph<T>::addNode(Node<T>a) {
    bool add=true;
    for (Node<T> elem:nodes)
    {
        if(elem==a)add=false;
    }
    if(add) {
        a.id=countId;
        //cout<<"count: "<<countId<<endl;
        nodes.push_back(a);
        ++countId;
    }
    return add;

}

template<typename T>
bool Graph<T>::addEdge(Node<T>node1, Node<T>node2, T waga) {
    bool add1=false;
    bool add2=false;
    for(auto elem:nodes)
    {
        if(elem==node1)add1=true;
        if(elem==node2)add2=true;
    }
    if(add1&&add2) {
        edges.push_back(Edge<T>{node1, node2,waga});

    }
    return add1&&add2;
}

template<typename T>
vector<Node<T>> &Graph<T>::getNodes() {
    return nodes;
}

template<typename T>
int Graph<T>::getIdByValue(T value) {
    int index=-1;
    for(auto elem: nodes)
    {
        if(elem.value==value)
        {index=elem[value];
        //cout<<"index:"<<index<<endl;
         }
    }
    return index;
}

template<typename T>
int Graph<T>::getIndex(T value) {
    int index=-1;
    int i=0;
    for(auto elem: nodes)
    {
        if(elem.value==value) {
           return i;
        }
        ++i;
    }
    return index;
}

