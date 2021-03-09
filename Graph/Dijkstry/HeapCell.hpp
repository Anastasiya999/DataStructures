#pragma once
#include"Cell.hpp"
#include <limits>
using namespace std;
double MAX_H=std::numeric_limits<double>::max();
template <typename T,size_t SIZE_OF_HEAP>
class HeapCell{
private:
    int counter=0;
    size_t size{};
    int capacity;
    Cell<T>nodes[SIZE_OF_HEAP];
    size_t parent(int pos);
    size_t rightChild(int pos);
    size_t leftChild(int pos);
    void swap(size_t pos1, size_t pos2);
    bool isLeaf(size_t pos);
public:
    Cell<T>& operator[](int  pos);
    HeapCell();
    void upheap(size_t pos);
    void downHeap(size_t pos);
    void add(Cell<T> element);
    int getCapacity();
    void setCapacity(int i);
    int Counter();

};

template<typename T, size_t SIZE_OF_HEAP>
HeapCell<T, SIZE_OF_HEAP>::HeapCell():capacity(0) {
for(int i=0;i<SIZE_OF_HEAP;i++)
    this->nodes[i]=Cell<T>{0,MAX_H};

}

template<typename T, size_t SIZE_OF_HEAP>
size_t HeapCell<T, SIZE_OF_HEAP>::parent(int pos) {
    return (pos-1)/2;
}

template<typename T, size_t SIZE_OF_HEAP>
size_t HeapCell<T, SIZE_OF_HEAP>::rightChild(int pos) {
    return 2*pos+2;
}

template<typename T, size_t SIZE_OF_HEAP>
size_t HeapCell<T, SIZE_OF_HEAP>::leftChild(int pos) {
    return 2*pos+1;
}

template<typename T, size_t SIZE_OF_HEAP>
void HeapCell<T, SIZE_OF_HEAP>::swap(size_t pos1, size_t pos2) {
    Cell<T> tmp=this->nodes[pos1];
    nodes[pos1]=nodes[pos2];
    nodes[pos2]=tmp;
}

template<typename T, size_t SIZE_OF_HEAP>
bool HeapCell<T, SIZE_OF_HEAP>::isLeaf(size_t pos) {
    return pos >= (capacity / 2) && pos < size;
}

template<typename T, size_t SIZE_OF_HEAP>
Cell<T> &HeapCell<T, SIZE_OF_HEAP>::operator[](int pos) {
    return nodes[pos];
}

template<typename T, size_t SIZE_OF_HEAP>
void HeapCell<T, SIZE_OF_HEAP>::upheap(size_t pos) {
    int current=pos;
    while (nodes[current].priority < nodes[parent(current)].priority) {
        ++counter;
        swap(current, parent(current));
        current = parent(current);
    }

}

template<typename T, size_t SIZE_OF_HEAP>
void HeapCell<T, SIZE_OF_HEAP>::add(Cell<T> element) {
    ++(this->capacity);
    this->nodes[this->capacity - 1] = element;
    upheap(this->capacity - 1);
}

template<typename T, size_t SIZE_OF_HEAP>
void HeapCell<T, SIZE_OF_HEAP>::downHeap(size_t pos) {
    int l=leftChild(pos);
    int r=rightChild(pos);
    int min=pos;
    if (l < capacity && nodes[l].priority< nodes[pos].priority)
        min = l;
    if (r < capacity && nodes[r].priority < nodes[min].priority)
        min= r;
    if (min!= pos)
    {
        swap(pos, min);
        downHeap(min);
    }

/*
    if(isLeaf(pos))   //warunek stopu
        return;
    if(nodes[pos].priority>nodes[leftChild(pos)].priority||nodes[pos].priority>nodes[rightChild(pos)].priority)
    {
        ++counter;
        if(nodes[leftChild(pos)].priority<nodes[rightChild(pos)].priority)
        {
            ++counter;
            swap(leftChild(pos),pos) ;
            downHeap(leftChild(pos));
        }else{
            swap(rightChild(pos),pos);
            downHeap(rightChild(pos));
        }
    }*/
}

template<typename T, size_t SIZE_OF_HEAP>
int HeapCell<T, SIZE_OF_HEAP>::getCapacity() {
    return capacity;
}

template<typename T, size_t SIZE_OF_HEAP>
void HeapCell<T, SIZE_OF_HEAP>::setCapacity(int i) {
this->capacity=i;
}

template<typename T, size_t SIZE_OF_HEAP>
int HeapCell<T, SIZE_OF_HEAP>::Counter() {
    return counter;
}
