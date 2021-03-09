#pragma once
#include"Cell.hpp"
using namespace std;
template <typename T,size_t SIZE_OF_HEAP>
class HeapCell{
private:

    int capacity;
    Cell<T>nodes[SIZE_OF_HEAP];
    size_t parent(int pos);
    size_t rightChild(int pos);
    size_t leftChild(int pos);
    void swap(size_t pos1, size_t pos2);

public:
    Cell<T>& operator[](int  pos);
    HeapCell();
    void upheap(size_t pos);
    void downHeap(size_t pos);
    void add(Cell<T> element);
    int getCapacity();
    void setCapacity(int i);


};

template<typename T, size_t SIZE_OF_HEAP>
HeapCell<T, SIZE_OF_HEAP>::HeapCell():capacity(-1) {

}

template<typename T, size_t SIZE_OF_HEAP>
size_t HeapCell<T, SIZE_OF_HEAP>::parent(int pos) {
    return (pos-1)/2;
}

template<typename T, size_t SIZE_OF_HEAP>
size_t HeapCell<T, SIZE_OF_HEAP>::rightChild(int pos) {
    return (2*pos)+2;
}

template<typename T, size_t SIZE_OF_HEAP>
size_t HeapCell<T, SIZE_OF_HEAP>::leftChild(int pos) {
    return (2*pos)+1;
}

template<typename T, size_t SIZE_OF_HEAP>
void HeapCell<T, SIZE_OF_HEAP>::swap(size_t pos1, size_t pos2) {
    Cell<T> tmp=nodes[pos1];
    nodes[pos1]=nodes[pos2];
    nodes[pos2]=tmp;
}



template<typename T, size_t SIZE_OF_HEAP>
Cell<T> &HeapCell<T, SIZE_OF_HEAP>::operator[](int pos) {
    return nodes[pos];
}

template<typename T, size_t SIZE_OF_HEAP>
void HeapCell<T, SIZE_OF_HEAP>::upheap(size_t pos) {
    int current=pos;
    while (nodes[current].priority > nodes[parent(current)].priority && current>0) {

        swap( current,parent(current));
        current = parent(current);
    }

}

template<typename T, size_t SIZE_OF_HEAP>
void HeapCell<T, SIZE_OF_HEAP>::add(Cell<T> element) {
    ++(this->capacity);
    this->nodes[this->capacity] = element;
    upheap(this->capacity);


}

template<typename T, size_t SIZE_OF_HEAP>
void HeapCell<T, SIZE_OF_HEAP>::downHeap(size_t pos) {


    int max = pos;
    int left = leftChild(pos);
    if(left<=capacity && nodes[left].priority>nodes[max].priority)
    {
        max = left;
    }
    int right = rightChild(pos);
    if(right<=capacity && nodes[right].priority>nodes[max].priority)
    {
        max=right;
    }
    if (pos!=max)
    {
        swap(pos, max);
        downHeap(max);
    }
}

template<typename T, size_t SIZE_OF_HEAP>
int HeapCell<T, SIZE_OF_HEAP>::getCapacity() {
    return this->capacity;
}

template<typename T, size_t SIZE_OF_HEAP>
void HeapCell<T, SIZE_OF_HEAP>::setCapacity(int i) {
this->capacity=i;
}

