#pragma once
#include"PriorityQ.hpp"
#include <array>
#include "Cell.hpp"
using namespace std;
template<typename T,size_t SIZE_OF_QUEUE>
class ArrayPQ:public PriorityQ<T,SIZE_OF_QUEUE>
{

private:
    int counter=0;
    int indexOfMaxPriority=0;
    int maxPriority=0;
    int capacity;
    array<Cell<T>, SIZE_OF_QUEUE>elements;
    void setIndexOfMaxPriority();
public:
    ArrayPQ();
    void Enqueue(T element, int priority );
    T DequeueMax();
    T FindMax();
    void MakeNull();
    int getCounter();
    int Count()const;
    bool isFull()const;
};

template<typename T, size_t SIZE_OF_QUEUE>
ArrayPQ<T, SIZE_OF_QUEUE>::ArrayPQ():capacity(0),counter(0){
    for(int i=0;i<SIZE_OF_QUEUE;i++)
    {
        elements[i]=Cell<T>{0,-1};
    }
}

template<typename T, size_t SIZE_OF_QUEUE>
void ArrayPQ<T, SIZE_OF_QUEUE>::Enqueue(T element, int priority) {
    Cell<T>newCell={element,priority};
if(!isFull()) {
    if (maxPriority < priority) {
        maxPriority = priority;
        indexOfMaxPriority = capacity;

        ++counter;
    }
    ++capacity;
    elements[capacity - 1] = newCell;
}else{
    cout<<"Bład: kolejka juz pełna"<<endl;
}
}

template<typename T, size_t SIZE_OF_QUEUE>
T ArrayPQ<T, SIZE_OF_QUEUE>::FindMax() {
    return this->elements[indexOfMaxPriority].element;
}

template<typename T, size_t SIZE_OF_QUEUE>
T ArrayPQ<T, SIZE_OF_QUEUE>::DequeueMax() {
    if(!this->isEmpty())
    {
        int max=elements[indexOfMaxPriority].element;
        ++counter;
        for(int i=indexOfMaxPriority;i<capacity;i++)
        {
            elements[i]=elements[i+1];
        }
        --(capacity);

        setIndexOfMaxPriority();
        return max;
    }else{
        cout<<"Bład usuwania: nie znaleziono elementa"<<endl;
        return -1;
    }
}

template<typename T, size_t SIZE_OF_QUEUE>
void ArrayPQ<T, SIZE_OF_QUEUE>::setIndexOfMaxPriority() {

    indexOfMaxPriority=0;
    maxPriority=elements[0].priority;
    for(int i=0;i<capacity;i++)
    {

        if(elements[i].priority<elements[i+1].priority)
        {
            ++(counter);
            indexOfMaxPriority=i+1;
            maxPriority=elements[i+1].priority;
        }

    }
}

template<typename T, size_t SIZE_OF_QUEUE>
int ArrayPQ<T, SIZE_OF_QUEUE>::getCounter() {
    return this->counter;
}

template<typename T, size_t SIZE_OF_QUEUE>
void ArrayPQ<T, SIZE_OF_QUEUE>::MakeNull() {
    capacity=0;
for(int i=0;i<capacity;i++)
{
    elements[i]=Cell<T>{0,-1};
}
}

template<typename T, size_t SIZE_OF_QUEUE>
int ArrayPQ<T, SIZE_OF_QUEUE>::Count() const {
    return capacity;
}

template<typename T, size_t SIZE_OF_QUEUE>
bool ArrayPQ<T, SIZE_OF_QUEUE>::isFull() const {
    return capacity==SIZE_OF_QUEUE;
}
