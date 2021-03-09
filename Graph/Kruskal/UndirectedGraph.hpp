#pragma once
#include"Graph.hpp"
#include "Lista.hpp"
#include "Stack.hpp"
#include"Queue.hpp"
#include <map>
#include <iostream>
using namespace std;
template <typename T>
class UndirectedGraph:public Graph<T>
{
private:

    Lista<T> *adjLists;
    bool *visited;
    Stack<T>stack;
    Queue<T>queue;
    int capacity=0;
public:
    UndirectedGraph();
    vector<Node<T>>getNeighbours(T value);
    bool addEdge(Node<T>, Node<T>);
    int getDegree(T);
    ~UndirectedGraph(){
        delete [] adjLists;
    }
    void print_DFS(Node<T>);
    void DFS(bool*,T);
    void print_BFS(Node<T>);
    bool isConnected();
};

template<typename T>
UndirectedGraph<T>::UndirectedGraph() {
    cout<<"Podaj liczbe wezlow: ";
    int liczba;
    cin>>liczba;
    adjLists=new Lista<T>[liczba];
    this->capacity=liczba;
    cout<<"Podaj wartosci wierzcholkow: "<<endl;
    for(int i=0;i<liczba;i++)
    {
        T element;
        cin>>element;
        this->addNode(Node<T>{element});
    }
    cout<<"podaj liczbe krawedzi:"<<endl;
    int liczba2;
    cin>>liczba2;
    cout<<"Podaj pary wezlow: w1 w2"<<endl;
    for(int i=0;i<liczba2;i++)
    {
        T v1,v2;
        cin>>v1>>v2;
        this->addEdge(v1,v2);
    }
}

template<typename T>
int UndirectedGraph<T>::getDegree(T value) {
    int index = Graph<T>::getIdByValue(value);
    int degree = 0;
    if (index >= 0) {
        auto tmp=adjLists[index].first();
        auto end=adjLists[index].end();
        while(tmp!=end)
        {
            tmp=adjLists[index].next(tmp);
            ++degree;
        }
}
   return degree;
}

template<typename T>
bool UndirectedGraph<T>::addEdge(Node<T>v1, Node<T>v2) {

   if(Graph<T>::addEdge(v1,v2)) {
       int id1, id2;
       id1=Graph<T>::getIdByValue(v1.value);
       id2=Graph<T>::getIdByValue(v2.value);
       adjLists[id1].push_front(v2.value);
       adjLists[id2].push_front(v1.value);
       return true;
   }else
       return false;
}



template<typename T>
 vector<Node<T>> UndirectedGraph<T>::getNeighbours(T value) {
     int id=Graph<T>::getIdByValue(value);

     auto tmp=adjLists[id].first();
     auto end=adjLists[id].end();
    vector<Node<T>>neighbours;
    while(tmp!=end)
    {
        neighbours.push_back(adjLists[id].retrieve(tmp));
        tmp=adjLists[id].next(tmp);
    }
  return neighbours;

}

template<typename T>
void UndirectedGraph<T>::print_DFS(Node<T> value) {
visited=new bool[capacity];
for(int i=0;i<capacity;i++)visited[i]=false;
    DFS(visited,value.value);
    delete []visited;

}

template<typename T>
void UndirectedGraph<T>::DFS(bool *,  T value) {

    T elem;
    int i=0;
    stack.push(value);
    while(!stack.empty())
    {
        elem=stack.TopElem();
        int id=Graph<T>::getIdByValue(elem);
        stack.pop();
        if(!visited[id])
        {
            visited[id]=true;
            cout<<elem<<" ";
        }
        auto tmp=adjLists[id].first();
        auto end=adjLists[id].end();
        while(tmp!=end)
        {
            i=Graph<T>::getIdByValue(adjLists[id].retrieve(tmp));
            if(!visited[i])
                DFS(visited,adjLists[id].retrieve(tmp));
            tmp=adjLists[id].next(tmp);
        }
    }

}

template<typename T>
void UndirectedGraph<T>::print_BFS(Node<T> value) {
    visited=new bool[capacity];
    for(int i=0;i<capacity;i++)visited[i]=false;
    queue.enqueue(value.value);
    visited[Graph<T>::getIdByValue(value.value)]=true;
    while(!queue.empty())
    {
        T elem=queue.FrontElem();
        int id=Graph<T>::getIdByValue(elem);
        cout<<elem<<" ";
        queue.dequeue();
        auto tmp=adjLists[id].first();
        auto end=adjLists[id].end();
        while(tmp!=end)
        {
            T v=adjLists[id].retrieve(tmp);
            int i=Graph<T>::getIdByValue(v);
            if(!visited[i]) {
                queue.enqueue(v);
                visited[i]=true;
            }
            tmp = adjLists[id].next(tmp);
        }
    }
}

template<typename T>
bool UndirectedGraph<T>::isConnected() {
    int licznik =0;
    visited=new bool[capacity];
    for(int i=0;i<capacity;i++)visited[i]=false;
    auto value=Graph<T>::getNodes()[0];
    queue.enqueue(value.value);
    visited[Graph<T>::getIdByValue(value.value)]=true;
    while(!queue.empty())
    {
        T elem=queue.FrontElem();
        int id=Graph<T>::getIdByValue(elem);
        ++licznik;
        queue.dequeue();
        auto tmp=adjLists[id].first();
        auto end=adjLists[id].end();
        while(tmp!=end)
        {
            T v=adjLists[id].retrieve(tmp);
            int i=Graph<T>::getIdByValue(v);
            if(!visited[i]) {
                queue.enqueue(v);
                visited[i]=true;
            }
            tmp = adjLists[id].next(tmp);
        }
    }

    return licznik==this->capacity;
}


