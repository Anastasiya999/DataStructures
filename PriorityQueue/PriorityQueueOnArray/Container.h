template <typename T>
class Container{
public:
    virtual ~Container(){};
    virtual int Count()const=0;
    virtual bool isEmpty()const{
        return Count()==0;
    }
    virtual bool isFull()const{
        return false;
    }

    virtual void MakeNull()=0;
};