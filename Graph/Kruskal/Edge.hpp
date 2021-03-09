#pragma once
#include"Node.hpp"
template <typename T>
class Edge{
public:
    Node<T> src;
    Node<T> dest;
    T value;
    Edge()
    {
        this->src=Node<T>(0);
        this->dest=Node<T>(0);
        this->value=250;
    }
    Edge(Node<T>a, Node<T>b, T value): src(a),dest(b),value(value)
    {}
    bool operator==(Edge<T>edge){
        return ( src==edge. src)&&(dest==edge.dest);
    }
};