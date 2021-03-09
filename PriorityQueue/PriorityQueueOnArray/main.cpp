#include <iostream>
#include"ArrayPQ.hpp"
using namespace std;
int main() {
    cout<<"Kolejka priorytetowa. Implementacja tablicowa"<<endl;
    ArrayPQ<int, 20>arrayPq;
    cout<<"isEmpty():"<<arrayPq.isEmpty()<<endl;

    arrayPq.Enqueue(3,9);
    cout<<"dodanie (elem:3, priority:9)"<<endl;

    arrayPq.Enqueue(8,2);
    cout<<"dodanie (elem:8, priority:2)"<<endl;

    arrayPq.Enqueue(4,10);
    cout<<"dodanie (elem:4, priority:10)"<<endl;

    cout<<"isEmpty():"<<arrayPq.isEmpty()<<endl;


    cout<<"Count(): "<<arrayPq.Count()<<endl;
    cout<<"FindMax(): "<<arrayPq.FindMax()<<endl;
    cout<<endl;

    cout<<"DequeueMax(): "<<arrayPq.DequeueMax()<<endl;
    cout<<"FindMax(): "<<arrayPq.FindMax()<<endl;
    cout<<endl;

    cout<<"DequeueMax(): "<<arrayPq.DequeueMax()<<endl;
    cout<<"FindMax(): "<<arrayPq.FindMax()<<endl;
    cout<<endl;

    arrayPq.Enqueue(8,2);
    cout<<"dodanie (elem:8, priority:2)"<<endl;
    arrayPq.Enqueue(4,10);
    cout<<"dodanie (elem:4, priority:10)"<<endl;

    cout<<"FindMax(): "<<arrayPq.FindMax()<<endl;
    arrayPq.Enqueue(5,11);
    cout<<"dodanie (elem:5, priority:11)"<<endl;
    cout<<endl;
    cout<<"FindMax(): "<<arrayPq.FindMax()<<endl;
    cout<<"DequeueMax(): "<<arrayPq.DequeueMax()<<endl;
    cout<<endl;

    cout<<"FindMax(): "<<arrayPq.FindMax()<<endl;
    cout<<"isFull() "<<arrayPq.isFull()<<endl;
    cout<<"Makenull"<<endl;
    arrayPq.MakeNull();
    cout<<"isEmpty(): "<<arrayPq.isEmpty()<<endl;

    return 0;
}
