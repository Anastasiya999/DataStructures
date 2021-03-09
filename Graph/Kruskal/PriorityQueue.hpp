#pragma once
#include "HeapCell.hpp"
using namespace std;
template <typename T,size_t SIZE_OF_QUEUE>
class PriorityQueue{
public:
    PriorityQueue();
    void Enqueue(T element, int priority);
    T DequeueMax();
    T FindMax();
    int getCounter();
private:
    HeapCell<T,SIZE_OF_QUEUE> elements;

};

template<typename T, size_t SIZE_OF_QUEUE>
PriorityQueue<T, SIZE_OF_QUEUE>::PriorityQueue() {

}

template<typename T, size_t SIZE_OF_QUEUE>
void PriorityQueue<T, SIZE_OF_QUEUE>::Enqueue(T element, int priority) {
   elements.add(Cell<T>{element,priority});
}

template<typename T, size_t SIZE_OF_QUEUE>
T PriorityQueue<T, SIZE_OF_QUEUE>::FindMax() {
    return elements[0].element;
}

template<typename T, size_t SIZE_OF_QUEUE>
T PriorityQueue<T, SIZE_OF_QUEUE>::DequeueMax() {
    T max=this->elements[0].element;

    this->elements[0]=elements[elements.getCapacity()-1];
    elements.setCapacity(elements.getCapacity()-1);
    elements.downHeap(0);
    return max;
}

template<typename T, size_t SIZE_OF_QUEUE>
int PriorityQueue<T, SIZE_OF_QUEUE>::getCounter() {
    return elements.Counter();
}
