#pragma once
#include <cstdint>
#include <array>
#include <bitset>
#include <algorithm>
using namespace std;
template <typename T, std::size_t SIZE_OF_SET>
class Set
{
public:
    explicit Set(const array<T,SIZE_OF_SET>&);
    Set(const Set&)= default;
    Set(Set&&)noexcept = default;
    Set&operator=(const Set&)= default;
    Set&operator=(Set&&)noexcept = default;

    class Vector
    {
    private:
        const Set *set_ptr;
        bitset<SIZE_OF_SET> bitSet;
    public:
        Vector(const Vector&)= default;
        Vector(Vector&&)noexcept = default;
        explicit Vector(const Set *set);
        Vector(const Set*, bitset<SIZE_OF_SET>);
        Vector&operator=(const Vector&)= default;
        Vector&operator=(Vector&&)noexcept = default;
        Vector operator+(const Vector&);
        Vector operator*(const Vector&);
        bool isMember(std::size_t element);
        bool remove(std:: size_t element);
        bool insert(size_t element);
        std::size_t count();
        class Iterator{
        private:
            explicit Iterator(const Vector *);
            Iterator(Vector*, std::size_t);
            Vector *vector_ptr;
            size_t index;//na co teraz wskazuje

        public:
            Iterator(const Iterator&)= default;
            Iterator (Iterator&&)noexcept =default;
            Iterator&operator=(const Iterator&)=default;
            Iterator&operator=(Iterator&&)noexcept = default;
            Iterator&operator++();
            const Iterator operator++(int);
            const T& operator*()const;
            T* operator->();
            bool operator!=(const Iterator&)const;
            friend class Vector;
        };
        Iterator begin();
        Iterator end();
        Iterator itByIndex(size_t index);


    };
private:
    array<T,SIZE_OF_SET> elements;
public:
    Vector makeVector();

};

template<typename T, std::size_t SIZE_OF_SET>
Set<T, SIZE_OF_SET>::Vector::Iterator::Iterator(const Set::Vector *vector_ptr):vector_ptr(vector_ptr) {

}

template<typename T, std::size_t SIZE_OF_SET>
Set<T, SIZE_OF_SET>::Vector::Iterator::Iterator(Set::Vector *vector_ptr, std::size_t index) :vector_ptr(vector_ptr),index(index){

}

template<typename T, std::size_t SIZE_OF_SET>
typename Set<T,SIZE_OF_SET>::Vector::Iterator &Set<T, SIZE_OF_SET>::Vector::Iterator::operator++() {
    do{
        ++index;
    }while(!vector_ptr->bitSet[index]&&index<vector_ptr->bitSet.size()); //stop kiedy bitset[index]=1;jezeli 0 to przechodzimy dalej, bo puste elementy
    return *this;
}

template<typename T, std::size_t SIZE_OF_SET>
const typename Set<T,SIZE_OF_SET>::Vector::Iterator Set<T, SIZE_OF_SET>::Vector::Iterator::operator++(int) {
    Iterator it(*this);
    ++(*this);
    return it;
}

template<typename T, std::size_t SIZE_OF_SET>
const T &Set<T, SIZE_OF_SET>::Vector::Iterator::operator*()const {

    return vector_ptr->set_ptr->elements[index];
}

template<typename T, std::size_t SIZE_OF_SET>
T *Set<T, SIZE_OF_SET>::Vector::Iterator::operator->() {
    return &vector_ptr->set_ptr->elements[index];

}

template<typename T, std::size_t SIZE_OF_SET>
bool Set<T, SIZE_OF_SET>::Vector::Iterator::operator!=(const Set::Vector::Iterator &it) const {
    return index!=it.index;
}

template<typename T, std::size_t SIZE_OF_SET>
Set<T, SIZE_OF_SET>::Vector::Vector(const Set *set):set_ptr(set) {

}

template<typename T, std::size_t SIZE_OF_SET>
std::size_t Set<T, SIZE_OF_SET>::Vector::count() {
    return bitSet.size();
}

template<typename T, std::size_t SIZE_OF_SET>
bool Set<T, SIZE_OF_SET>::Vector::isMember(std::size_t element) {
    return bitSet.test(element);
}

template<typename T, std::size_t SIZE_OF_SET>
bool Set<T, SIZE_OF_SET>::Vector::insert(size_t element) {
    if(bitSet.test(element))
    {
        return false;
    }else{
        bitSet[element]=1;
        return true;
    }
}

template<typename T, std::size_t SIZE_OF_SET>
bool Set<T, SIZE_OF_SET>::Vector::remove(std::size_t element) {
    if(bitSet.test(element)){
        bitSet[element]=0;
        return true;
    }else{
        return false;
    }
}

template<typename T, std::size_t SIZE_OF_SET>
typename Set<T,SIZE_OF_SET>::Vector Set<T, SIZE_OF_SET>::Vector::operator+(const Set::Vector &v1) {
    bitset<SIZE_OF_SET>sum(bitSet|v1.bitSet);
    return Vector(set_ptr,sum);
}

template<typename T, std::size_t SIZE_OF_SET>
Set<T, SIZE_OF_SET>::Vector::Vector(const Set *set_ptr, bitset<SIZE_OF_SET>bits):set_ptr(set_ptr),bitSet(bits) {

}

template<typename T, std::size_t SIZE_OF_SET>
typename Set<T,SIZE_OF_SET>::Vector Set<T, SIZE_OF_SET>::Vector::operator*(const Set::Vector &v1) {
    bitset<SIZE_OF_SET>product(bitSet^v1.bitSet);
    return Vector(this,product);
}

template<typename T, std::size_t SIZE_OF_SET>
typename Set<T,SIZE_OF_SET>::Vector::Iterator Set<T, SIZE_OF_SET>::Vector::begin() {
    size_t index_first=0;
    while(!bitSet.test(index_first))
    {
        ++index_first;
    }
    return Iterator(this,index_first);
}

template<typename T, std::size_t SIZE_OF_SET>
typename Set<T, SIZE_OF_SET>::Vector::Iterator Set<T, SIZE_OF_SET>::Vector::end() {
    return Iterator(this,bitSet.size());
}

template<typename T, std::size_t SIZE_OF_SET>
typename Set<T,SIZE_OF_SET>::Vector::Iterator Set<T, SIZE_OF_SET>::Vector::itByIndex(size_t index) {
    if(bitSet[index])
    return Iterator(this,index);
    else{
        return Iterator(this,bitSet.set());
    }
}

template<typename T, std::size_t SIZE_OF_SET>
Set<T, SIZE_OF_SET>::Set(const array<T,SIZE_OF_SET>&elements): elements(elements){

}

template<typename T, std::size_t SIZE_OF_SET>
typename Set<T, SIZE_OF_SET>::Vector Set<T, SIZE_OF_SET>::makeVector() {
    return Vector(this);
}
