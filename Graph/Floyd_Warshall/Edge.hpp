#pragma once
#include"Node.hpp"
template <typename T>
class Edge{
   Node<T> node1;
   Node<T> node2;
public:
    Edge(Node<T>a, Node<T>b):node1(a),node2(b)
    {}
    bool operator==(Edge<T>edge){
        return (node1==edge.node1)&&(node2==edge.node2);
    }
};