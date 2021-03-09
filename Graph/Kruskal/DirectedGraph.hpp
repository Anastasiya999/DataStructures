#pragma once
#include"List.hpp"
#include "Graph.hpp"
#include "Queue.hpp"
#include"Stack.hpp"
#include<vector>
#include<limits>
#include "PriorityQueue.hpp"
#include <stdlib.h>

//double MAX=std::numeric_limits<double>::max();
double MAX=100;
template <typename T>
class DirectedGraph:public Graph<T>{
private:
    bool *visited;
    List<T> *adjLists;
    double **edgeValues;
    int edgeCount;
    Queue<T>queue;
    int capacity=0;
    void print_path(T*,T value);
    void print_path_Fl(int,int);
    static int compare(const void* a, const void* b);


    int **path;
    class Forest{
    public:
        int root;
        int level;
    };
    int findRoot(Forest*,int);
    void MergeForest(Forest*,int,int);


public:

    DirectedGraph();
    vector<Node<T>>getNeighbours(T value);
    vector<Node<T>>getIsNeighbour(T value);
    bool addEdge(Node<T>, Node<T>,double);
    int getInDegree(T);
    int getOutDegree(T);
    void Kruskal();
    ~DirectedGraph(){
        delete[]adjLists;
        for(int i=0;i<capacity;i++)
        {
            delete[] edgeValues[i];
            delete[]path[i];

        }
        delete[]edgeValues;
        delete[]path;
        edgeValues=NULL;
    }
    void topolRecurs(Node<T> value, bool *,Stack<T> &stack);
    void TopolSort();
    int BFS_count(Node<T>);
    void print_BFS(Node<T>);
    bool isConnected();
    void Dikstry(T value);
    void Floyd_Warschal();
};

template<typename T>
DirectedGraph<T>::DirectedGraph() {
    cout<<"Podaj liczbe wezlow: ";
    int liczba;
    cin>>liczba;
    adjLists=new List<T>[liczba];
    this->capacity=liczba;
    edgeValues=new double*[capacity];
    path=new int*[capacity];
    for(int i=0;i<capacity;i++)
    {
        edgeValues[i]=new double[capacity];
        path[i]=new int[capacity];

        for(int j=0;j<capacity;j++)
        {
            edgeValues[i][j]=MAX;
            path[i][j]=0;
        }
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
    this->edgeCount=liczba2;
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
    if(Graph<T>::addEdge(v1,v2,waga)){
        adjLists[Graph<T>::getIdByValue(v1.value)].push_front(v2.value);
        edgeValues[Graph<T>::getIdByValue(v1.value)][Graph<T>::getIdByValue(v2.value)]=waga;
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

template<typename T>
void DirectedGraph<T>::Dikstry(T value) {

    PriorityQueue<T,30>priorityQueue;
    int id=Graph<T>::getIdByValue(value);
    T poprzednik[capacity];
    double distance[capacity];
    for(int i=0;i<capacity;i++)
    {
        distance[i]=MAX;
    }
    distance[id]=0.0;
    poprzednik[id]=value;
    for(auto elem:getNeighbours(value))
    {
        poprzednik[Graph<T>::getIdByValue(elem.value)]=value;
    }
    auto tmp=adjLists[id].first();   ///odleglosc dla zrodla
    auto end=adjLists[id].end();
    while(tmp!=end)
    {
        T v=adjLists[id].retrieve(tmp);
        int i=Graph<T>::getIdByValue(v);
        distance[i]=edgeValues[id][i];
        tmp = adjLists[id].next(tmp);
    }
    int k=0;

    for(auto elem:Graph<T>::getNodes())
    {

        if(k<capacity) {

            priorityQueue.Enqueue(elem.value, distance[k]);     ///ustawiamy kolejke
        }
        k++;
    }


    for(int j=0;j<4;j++)                          ///przechodzimy kazdy wierzcholek odpowiednio do priorytetu
    {
        auto v1=priorityQueue.DequeueMax();

        int id1=Graph<T>::getIdByValue(v1);

        auto tmp1=adjLists[id1].first();          ///przechodzimy sasiadow wybranego wierzcholka
        auto end1=adjLists[id1].end();
        while(tmp1!=end1)
        {
            T v=adjLists[id1].retrieve(tmp1);

            int i=Graph<T>::getIdByValue(v);

            if((distance[id1]+edgeValues[id1][i])<distance[i])     ///relaksacja
            {
                distance[i]=distance[id1]+edgeValues[id1][i];      ///aktualizujemy wartosci w  tablice odleglosci i poprzednikow
                priorityQueue.Enqueue(v,distance[i]);
                poprzednik[i]=v1;
            }
            tmp1 = adjLists[id1].next(tmp1);
        }

    }

    ///wypisywanie
    for(auto elem:Graph<T>::getNodes())
    {
        cout<<elem.value;
        print_path(poprzednik,elem.value);
        cout<<endl;
    }


}

template<typename T>
void DirectedGraph<T>::print_path(T * poprzednik, T value) {
    while(value!=poprzednik[0])
    {
        T u=poprzednik[Graph<T>::getIdByValue(value)];
        cout<<"<--"<<u;
        value=u;
    }


}

template<typename T>
void DirectedGraph<T>::Floyd_Warschal() {

    double D[capacity][capacity];
    vector<Node<T>>values=Graph<T>::getNodes();

    for( int i=0;i<capacity;i++)
    {
        for( int j=0;j<capacity;j++)
            D[i][j]=edgeValues[i][j] ;
    }
    for( int i=0;i<capacity;i++)
        D[i][i]=0.0;


    for(int k=1;k<capacity;k++)
        for( int i=0;i<capacity;i++)
            for( int j=0;j<capacity;j++)
            {
                if( D[i][j]>D[i][k]+D[k][j])
                {
                    this->path[i][j]=k;
                }
                D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
            }

    ///wypisywaniie///
    for( int i=0;i<capacity;i++)
        for( int j=0;j<capacity;j++)
        {
            if(D[i][j]==MAX)
            {
                cout<<"no path:"<<values[i].value<<"-->"<<values[j].value<<endl;
            } else{
                if(i!=j)
                {
                    cout<<"path "<<values[i].value<<"-->";
                    print_path_Fl(i,j);
                    cout<<""<<values[j].value<<" cost:"<<D[i][j]<<endl;
                }
            }

        }



}

template<typename T>
void DirectedGraph<T>::print_path_Fl( int i, int j) {
    int v=path[i][j];
    if(v!=0.0)
    {
        print_path_Fl(i,v);
        cout<<Graph<T>::getNodes()[v].value<<"-->";
        print_path_Fl(v,j);
    }
}

template<typename T>
void DirectedGraph<T>::Kruskal() {
///tworzymy las
    vector<Edge<T>>resultEdge;
    auto trees=Graph<T>::getNodes();
    Forest *forests=new Forest[(capacity* sizeof(Forest))];
    for(int i=0;i<capacity;i++)
    {
        forests[i].root=trees[i].id;
        forests[i].level=0;
    }
///wstawiamy krawedzi do kolejki///
    Edge<T>*edges=new Edge<T>[(edgeCount*sizeof(Edge<T>))];
    int j=0;
    for(int i=0;i<capacity;i++)
    {
        auto tmp=adjLists[i].first();
        auto end=adjLists[i].end();

        while(tmp!=end)
        {
            auto elem=adjLists[i].retrieve(tmp);
            int id=Graph<T>::getIdByValue(elem);
            edges[j++]=Edge<T>{trees[i],trees[id],(int)edgeValues[i][id]};
            tmp=adjLists[i].next(tmp);
        }

    }
    qsort(edges,(size_t)edgeCount, sizeof(edges[0]),compare);

///pobieramy z kolejki o najmniejszej wadze///
    for(int i=0;i<capacity;i++)
    {
        Edge<T>edge=edges[i];
        int src_id=edge.src.id;
        int id_u=findRoot(forests,src_id);
        int id_v=findRoot(forests,edge.dest.id);
        if(id_u!=id_v)
        {
            MergeForest(forests,id_u,id_v);
            resultEdge.push_back(edge);
        }
    }
///wypisywanie//
    for(Edge<T> edge:resultEdge)
    {
        cout<<edge.src.value<<"->"<<edge.dest.value<<":"<<edge.value<<endl;
    }
    delete []edges;
    delete []forests;
}


template<typename T>
int DirectedGraph<T>::findRoot(DirectedGraph::Forest * forests, int u_id) {
    if(forests[u_id].root!=u_id)
        forests[u_id].root=findRoot(forests,forests[u_id].root);
    return forests[u_id].root;
}

template<typename T>
void DirectedGraph<T>::MergeForest(DirectedGraph::Forest * forest, int u, int v) {
    int v_root=findRoot(forest,v);
    int u_root=findRoot(forest,u);
    if(forest[u_root].level<forest[v_root].level)
    {
        forest[u_root].root=v_root;
    }
    else if(forest[u_root].level>forest[v_root].level)
    {
        forest[v_root].root=u_root;
    } else{
        forest[v_root].root=u_root;
        forest[u_root].level++;
    }
}

template<typename T>
int DirectedGraph<T>::compare(const void *a, const void *b) {
    Edge<T>* u = (Edge<T>*)a;
    Edge<T>* v = (Edge<T>*)b;
    return u->value > v->value;
}