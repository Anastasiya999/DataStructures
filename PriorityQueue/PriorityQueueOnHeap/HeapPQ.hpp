#pragma once
#include"PriorityQ.hpp"
#include"HeapCell.hpp"
#include <iostream>
using namespace std;
template<typename T,size_t SIZE_OF_QUEUE>
class HeapPQ :public PriorityQ<T,SIZE_OF_QUEUE>{
public:
    HeapPQ();
    void Enqueue(T element, int priority);
    T DequeueMax();
    T FindMax();
    int Count()const;
    void MakeNull();
    bool isFull()const;
    int get_capacity();
private:
    int capacity;
    HeapCell<T,SIZE_OF_QUEUE> elements;
};
template<typename T, size_t SIZE_OF_QUEUE>
HeapPQ<T, SIZE_OF_QUEUE>::HeapPQ():capacity(0) {

}


template<typename T, size_t SIZE_OF_QUEUE>
void HeapPQ<T, SIZE_OF_QUEUE>::Enqueue(T element, int priority) {
    ++(this->capacity);
    elements.add(Cell<T>{element,priority});
}

template<typename T, size_t SIZE_OF_QUEUE>
T HeapPQ<T, SIZE_OF_QUEUE>::DequeueMax() {
    --(this->capacity);
    T max=this->elements[0].element;
    this->elements[0]=this->elements[this->elements.getCapacity()];
    this->elements.setCapacity(this->elements.getCapacity()-1);
    this->elements.downHeap(0);

    return max;
}

template<typename T, size_t SIZE_OF_QUEUE>
T HeapPQ<T, SIZE_OF_QUEUE>::FindMax() {
    if(elements.getCapacity()!=-1)
      return this->elements[0].element;
    else
        return -100;

}

template<typename T, size_t SIZE_OF_QUEUE>
int HeapPQ<T, SIZE_OF_QUEUE>::Count() const {
    return this->capacity;
}

template<typename T, size_t SIZE_OF_QUEUE>
void HeapPQ<T, SIZE_OF_QUEUE>::MakeNull() {
    this->capacity=0;
    this->elements=HeapCell<T, SIZE_OF_QUEUE>{};
}

template<typename T, size_t SIZE_OF_QUEUE>
bool HeapPQ<T, SIZE_OF_QUEUE>::isFull() const {
    return this->capacity == SIZE_OF_QUEUE;
}

template<typename T, size_t SIZE_OF_QUEUE>
int HeapPQ<T, SIZE_OF_QUEUE>::get_capacity() {
    return SIZE_OF_QUEUE;
}
