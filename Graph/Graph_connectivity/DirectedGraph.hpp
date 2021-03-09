#pragma once
#include"List.hpp"
#include "Graph.hpp"
#include "Queue.hpp"
#include"Stack.hpp"
#include<vector>
template <typename T>
class DirectedGraph:public Graph<T>{
private:
    bool *visited;
    List<T> *adjLists;
    double **edgeValues;
    Queue<T>queue;
    int capacity=0;

public:
    DirectedGraph();
    vector<Node<T>>getNeighbours(T value);
    vector<Node<T>>getIsNeighbour(T value);
    bool addEdge(Node<T>, Node<T>,double);
    int getInDegree(T);
    int getOutDegree(T);
    ~DirectedGraph(){
    delete[]adjLists;
        for(int i=0;i<capacity;i++)
        {
            delete[] edgeValues[i];

        }
        delete[]edgeValues;
        edgeValues=NULL;
    }
    void topolRecurs(Node<T> value, bool *,Stack<T> &stack);
    void TopolSort();
    int BFS_count(Node<T>);
    void print_BFS(Node<T>);
    bool isConnected();
};

template<typename T>
DirectedGraph<T>::DirectedGraph() {
    cout<<"Podaj liczbe wezlow: ";
    int liczba;
    cin>>liczba;
    adjLists=new List<T>[liczba];
    this->capacity=liczba;
    edgeValues=new double*[capacity];
    for(int i=0;i<capacity;i++)
    {
        edgeValues[i]=new double[capacity];
        for(int j=0;j<capacity;j++)edgeValues[i][j]=-1.0;
    }
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
    cout<<"Podaj pary wezlow: w1 w2 waga"<<endl;
    for(int i=0;i<liczba2;i++)
    {
        T v1,v2;
        double waga;
        cin>>v1>>v2>>waga;
        this->addEdge(v1,v2,waga);
    }
}

template<typename T>
bool DirectedGraph<T>::addEdge(Node<T>v1, Node<T>v2,double waga) {
    if(Graph<T>::addEdge(v1,v2)){
     adjLists[Graph<T>::getIdByValue(v1.value)].push_front(v2.value);
      edgeValues[v1.value][v2.value]=waga;
    }
}

template<typename T>
int DirectedGraph<T>::getOutDegree(T value) {
    int index=Graph<T>::getIdByValue(value);
    int degree=0;
    auto tmp=adjLists[index].first();

    while(tmp!=adjLists[index].end())
    {
        tmp=adjLists[index].next(tmp);
        ++degree;
    }
    return degree;
}

template<typename T>
int DirectedGraph<T>::getInDegree(T value) {
    int degree =0;
    for(int i=0;i<capacity;i++)
    {
        if(Graph<T>::getIdByValue(value)!=i)
        {
            auto tmp=adjLists[i].first();
            while(tmp!=adjLists[i].end())
            {
                if(adjLists[i].retrieve(tmp)==value)++degree;
                tmp=adjLists[i].next(tmp);

            }
        }
    }
    return degree;
}

template<typename T>
vector<Node<T>> DirectedGraph<T>::getNeighbours(T value) {
    vector<Node<T>>neighbours;

    int index=Graph<T>::getIdByValue(value);
    auto tmp=adjLists[index].first();
   while(tmp!=adjLists[index].end())
    {
        neighbours.push_back(adjLists[index].retrieve(tmp));
        tmp=adjLists[index].next(tmp);
    }
   return neighbours;
}

template<typename T>
vector<Node<T>> DirectedGraph<T>::getIsNeighbour(T value) {
    bool exist=false;
    vector<Node<T>>isNeighbour;
    int index=Graph<T>::getIdByValue(value);
    cout<<"index"<<index<<endl;
    for(int i=0;i<capacity;i++)
    {
        if(i!=index)
        {
            auto tmp=adjLists[i].first();
            while(tmp!=adjLists[i].end())
            {
                if(adjLists[i].retrieve(tmp)==value) {
                    exist=true;
                    isNeighbour.push_back(Graph<T>::getNodes()[i].value);
                }
                tmp=adjLists[i].next(tmp);
            }
        }
    }
    if(exist)return isNeighbour;
    else
        return vector<Node<T>>{};

}

template<typename T>
void DirectedGraph<T>::print_BFS(Node<T> value) {
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
    delete []visited;
}

template<typename T>
bool DirectedGraph<T>::isConnected() {
    for(auto node:Graph<T>::getNodes())
    {
        if(BFS_count(node)!=capacity)return false;
    }
    return true;
}

template<typename T>
int DirectedGraph<T>::BFS_count(Node<T> value) {
    visited=new bool[capacity];
    for(int i=0;i<capacity;i++)visited[i]=false;
    int licznik=0;
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
    delete []visited;
    return licznik;
}

template<typename T>
void DirectedGraph<T>::topolRecurs(Node<T> value, bool *visited,Stack<T> &stack) {
    int id=Graph<T>::getIdByValue(value.value);
    visited[id]=true;
    auto tmp=adjLists[id].first();
    auto end=adjLists[id].end();
    while(tmp!=end)
    {
        T v=adjLists[id].retrieve(tmp);
        int i=Graph<T>::getIdByValue(v);
        if(!visited[i]) {
            topolRecurs(v,visited,stack);
        }
        tmp = adjLists[id].next(tmp);
    }
    stack.push(value.value);
}

template<typename T>
void DirectedGraph<T>::TopolSort() {
    visited=new bool[capacity];
    for(int i=0;i<capacity;i++)visited[i]=false;
    Stack<T>stack;
    for(auto elem:Graph<T>::getNodes())
    {
        if(visited[Graph<T>::getIdByValue(elem.value)]==false)
        topolRecurs(elem,visited,stack);
    }
    while(stack.empty()==false)
    {
        cout<<stack.TopElem()<<" ";
        stack.pop();
    }
    delete []visited;
}
