#include <iostream>
#include "HeapPQ.hpp"
using namespace std;

int main(){
    cout<<"Kolejka priorytetowa. Implementacja tablicowa"<<endl;
    HeapPQ<int, 20>heapPq;
    cout<<"isFull(): "<< heapPq.isFull()<<endl;

    heapPq.Enqueue(3,9);
    cout<<"dodanie (elem:3, priority:9)"<<endl;

    heapPq.Enqueue(8,2);
    cout<<"dodanie (elem:8, priority:2)"<<endl;

    heapPq.Enqueue(4,10);
    cout<<"dodanie (elem:4, priority:10)"<<endl;

    heapPq.Enqueue(1,20);
    cout<<"dodanie (elem:1, priority:20)"<<endl;

    cout<<"isFull():"<<heapPq.isFull()<<endl;
    cout<<"Count(): "<<heapPq.Count()<<endl;
    cout<<endl;

    cout<<"Capacity: "<<heapPq.get_capacity()<<endl;
    cout<<"FindMax(): "<<heapPq.FindMax()<<endl;
    cout<<endl;

    cout<<"DequeueMax(): "<<heapPq.DequeueMax()<<endl;
    cout<<"FindMax(): "<<heapPq.FindMax()<<endl;
    cout<<endl;

    cout<<"DequeueMax(): "<<heapPq.DequeueMax()<<endl;
    cout<<"FindMax(): "<<heapPq.FindMax()<<endl;
    cout<<endl;

    cout<<"DequeueMax(): "<<heapPq.DequeueMax()<<endl;
    cout<<"FindMax(): "<<heapPq.FindMax()<<endl;
    cout<<endl;

    cout<<"DequeueMax(): "<<heapPq.DequeueMax()<<endl;
    cout<<"isEmpty(): "<<heapPq.isEmpty()<<endl;
    cout<<"FindMax(): "<<heapPq.FindMax()<<endl;
    cout<<endl;

    heapPq.Enqueue(8,2);
    cout<<"dodanie (elem:8, priority:2)"<<endl;
    heapPq.Enqueue(4,10);
    cout<<"dodanie (elem:4, priority:10)"<<endl;

    cout<<"FindMax(): "<<heapPq.FindMax()<<endl;
    heapPq.Enqueue(5,11);
    cout<<"dodanie (elem:5, priority:11)"<<endl;
    cout<<endl;
    cout<<"FindMax(): "<<heapPq.FindMax()<<endl;
    cout<<"DequeueMax(): "<<heapPq.DequeueMax()<<endl;
    cout<<endl;

    cout<<"FindMax(): "<<heapPq.FindMax()<<endl;
    cout<<"isFull(): "<<heapPq.isFull()<<endl;
    cout<<"Makenull"<<endl;
    heapPq.MakeNull();
    cout<<"isEmpty(): "<<heapPq.isEmpty()<<endl;
    return 0;
}
