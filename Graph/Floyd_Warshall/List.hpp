#pragma once
#include<cstdio>
#include<cstdlib>
#include <iostream>
using namespace std;
template<typename T>

class List{
    struct cell{
        T element;
        cell * next;
    };
    using position=cell*;
protected:
    position head;  //glowa
public:
    List();
    ~List();
    void insert(T element, position pos);
    void remove(T element, position pos);
    T retrieve(position pos);
    position first();
    position locate(T element);
    void push_front(T element);
    position next(position pos);
    position prev(position pos);
    position end();

};
template<typename T>
List<T>::List() {
head=new cell;
head->next=nullptr;
}

template<typename T>
void List<T>::insert(T element, List::position p) {
    position tmp=p->next;
    p->next=new cell;
    p->next->element=element;
    p->next->next=tmp;
}

template<typename T>
List<T>::~List() {
delete head;
}

template<typename T>
T List<T>::retrieve(List::position pos) {
    if(pos->next!=nullptr)  //to nie jest głowa, lub koniec
        return pos->next->element;
    else {
        cout<<"nie ma elementu"<<endl;
        return 0;
    }
}

template<typename T>
typename List<T>::position List<T>::locate(T element) {
    position current=head;
    while(current->next!= nullptr)
    {
        if(current->next->element==element)return current;
        current=current->next;
    }
    return current;  //koniec listy
}

template<typename T>
typename List<T>::position List<T>::next(List::position pos) {
    return pos->next;
}

template<typename T>
typename List<T>::position List<T>::prev(List::position pos) {
    position current=head;
    while(current->next!=pos)
    {
        current=current->next;
    }
    return current;
}

template<typename T>
typename List<T>::position List<T>::end() {
    position current=head;
    while(current->next!= nullptr)
    {
        current=current->next;
    }
    return current;
}

template<typename T>
typename List<T>::position List<T>::first() {
    return head;
}

template<typename T>
void List<T>::remove(T element, List::position pos) {


    position tmp=pos->next;
    pos->next=pos->next->next;
    delete tmp;

}

template<typename T>
void List<T>::push_front(T element) {
this->insert(element,this->first());
}
