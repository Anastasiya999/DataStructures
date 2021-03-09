#pragma once
const int maxlegth = 50;
typedef int position;
template<typename T>
class Stack
{
    T S[maxlegth];
    position Top;//szczyt stosu
    int capacity;
public:
    Stack() {
        Top = -1;
        capacity=0;
    }
    int length(){
        return capacity;
    }
    void push(T x) {
        if (Top < maxlegth) {
            Top++;
            S[Top] = x;
            ++capacity;
        }
    }
    void pop() {
        if (Top != -1) {
            Top--;
            --capacity;
        }

    }
    bool empty() {
        if (Top == -1)return true;
        else return false;
    }
    T TopElem() {
        if (Top != -1)return S[Top];
        else return (T)"";
    }
    void Makenull() {
        Top = -1;
        capacity=0;
    }
};
