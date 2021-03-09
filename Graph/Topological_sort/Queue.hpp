#pragma once
#include <iostream>
using namespace std;
const int maxlength = 50;
typedef int position;
template <typename T>
class Queue
{
protected:
    T queue[maxlength];
    position Front; // Indeks elementu czołowego
    position Rear; // Indeks ostatniego elementu
public:
    Queue() {
        Front = 0;
        Rear = maxlength - 1;
    }
    int AddOne(int i) {
        return (i + 1) % maxlength;
    }
    void enqueue(T x) {
        if (AddOne(AddOne(Rear)) != Front)
        {
            Rear = AddOne(Rear);
            queue[Rear] = x;
        }
    }
    void dequeue() {
        if (AddOne(Rear) != Front) {
            Front = AddOne(Front);
        }
    }
    T FrontElem() {

        if (!empty()) {
            return queue[Front];
        }
        else return NULL;
    }
    void Makenull() {
        Front = 0;
        Rear = maxlength - 1;
    }
    bool empty() {
        if (AddOne(Rear) != Front)return false;
        else return true;
    }
};
