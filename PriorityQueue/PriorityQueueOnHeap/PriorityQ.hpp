#pragma once
#include"Container.h"
using namespace std;
template<typename T,size_t SIZE_OF_QUEUE>
class PriorityQ:public Container<T>{
public:
   virtual void Enqueue(T element, int priority)=0;
   virtual  T DequeueMax()=0;
   virtual T FindMax()=0;

};