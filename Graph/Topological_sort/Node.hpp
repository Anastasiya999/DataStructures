#pragma onceonce
using namespace std;
template<typename T>
class Node{
public:
    int id=-1;
    T value;
    Node(T value):value(value){

    }

    bool operator==(Node<T>node)
    {
        return value==node.value;
    }
    int& operator [](T elem)
    {
        int exception=-1;
        if(elem==value) {
            return id;
        } else
        {
            cout<<"nie ma elementu"<<endl;
            return id;
        }
    }

};