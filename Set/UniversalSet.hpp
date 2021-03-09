//
// Created by www on 03.03.2020.
//

#ifndef SET_UNIVERSALSET_HPP
#define SET_UNIVERSALSET_HPP
#include <cstdint>
#include <array>
#include <bitset>
#include <algorithm>
template<typename T, std::size_t UNIVERSE_SIZE>
class UniversalSet
{
public:
    class Vector
    {
    public:
        class Iterator
        {
        private:
            explicit Iterator(const Vector *vector_ptr);
            Iterator(const Vector *vector_ptr, std::size_t index);

        public:
            Iterator(const Iterator&) = default;
            Iterator& operator=(const Iterator&) = default;
            Iterator(Iterator&&) noexcept = default;
            Iterator& operator=(Iterator&&) noexcept = default;

            friend class Vector;

        private:
            const Vector * vector_ptr;
            std::size_t index;

        public:
            bool operator==(const Iterator &it) const;
            bool operator!=(const Iterator &it) const;
            Iterator& operator++();
            const Iterator operator++(int);
            const T& operator*() const;
            const T* operator->() const;
            explicit operator bool() const;
        };

    public:
        explicit Vector(const UniversalSet *universe_ptr);
        Vector(const UniversalSet *universe_ptr, const std::bitset<UNIVERSE_SIZE> & bits);
        Vector(const Vector&) = default;
        Vector& operator=(const Vector &universe) = default;
        Vector(Vector &&universe) noexcept = default;
        Vector& operator=(Vector &&universe) noexcept = default;

       // friend class Iterator;

    private:
        std::bitset<UNIVERSE_SIZE> bits;
        const UniversalSet<T, UNIVERSE_SIZE> *universe_ptr;

    public:
/// Zwraca liczbe elementów reprezentowanych przez "Vector"
        std::size_t count() const;
/// Jezeli element o indeksie "i" nie nalezy do "Vector" to dodaje ten element oraz zwraca
/// "Iterator" do dodanego elementu i "true", w przeciwnym razie zwraca samo co "end()"
/// i "false"
        std::pair<Iterator, bool> insert(std::size_t index);
/// Jezeli element o indeksie "i" nalezy do "Vector" to zwraca "true", w przeciwnym razie
/// zwraca "false"
        bool isMember(std::size_t i) const;
/// Jeżeli element o indeksie "i" należy do "Vector" to zwraca "Iterator" do tego elementu,
/// w przeciwnym razie zwraca to samo co "end()"
        Iterator elemIterator(std::size_t i) const;
/// Jezeli element o indeksie "i" nalezy do "Vector" to usuwa ten element i zwraca "true",
/// w przeciwnym razie zwraca "false"
        bool remove(std::size_t i);
/// Zwraca "true" jeżeli obiekt "v2" reprezentuje ten sam zestaw elementow z tego samego
/// uniwersum, w przeciwnym razie zwraca "false"
        bool operator==(const Vector &v2) const;
        bool operator!=(const Vector &v2) const;
/// Zwraca sume zbiorow
        Vector operator+(const Vector &v2) const;
/// Zwraca roznice zbiorow
        Vector operator-(const Vector &v2) const;
/// Zwraca czesc wspolna zbiorow
        Vector operator*(const Vector &v2) const;
/// Zwraca roznice symetryczna zbiorow
        Vector operator/(const Vector &v2) const;
/// Zwraca "Iterator" na poczatek
        Iterator begin() const;
/// Zwraca "Iterator" za koniec
        Iterator end() const;
    };

public:
    explicit UniversalSet(const std::array<T, UNIVERSE_SIZE> & elements);
    UniversalSet(const UniversalSet&) = default;
    UniversalSet& operator=(const UniversalSet&) = default;
    UniversalSet(UniversalSet&&) noexcept = default;
    UniversalSet& operator=(UniversalSet&&) noexcept = default;

private:
    std::array<T, UNIVERSE_SIZE> elements;

public:
    constexpr std::size_t universeSize() const { return UNIVERSE_SIZE; }
    const T& elem(std::size_t i) const;
    const T& operator[](std::size_t i) const;
/// Zwraca pusty "Vector"
    Vector makeVector() const;
};


template<typename T, size_t UNIVERSE_SIZE>
UniversalSet<T, UNIVERSE_SIZE>::Vector::Iterator::Iterator(
        const UniversalSet::Vector * vector_ptr) : vector_ptr(vector_ptr), index(0) { /**/ }

template<typename T, size_t UNIVERSE_SIZE>
UniversalSet<T, UNIVERSE_SIZE>::Vector::Iterator::Iterator(
        const UniversalSet::Vector *vector_ptr, std::size_t index)
        : vector_ptr(vector_ptr), index(index) { }

template<typename T, size_t UNIVERSE_SIZE>
bool UniversalSet<T, UNIVERSE_SIZE>::Vector::Iterator::operator==(
        const UniversalSet::Vector::Iterator &it) const {

    return index == it.index;
}

template<typename T, size_t UNIVERSE_SIZE>
bool UniversalSet<T, UNIVERSE_SIZE>::Vector::Iterator::operator!=(
        const UniversalSet::Vector::Iterator &it) const {

    return index != it.index;
}

template<typename T, size_t UNIVERSE_SIZE>
typename UniversalSet<T, UNIVERSE_SIZE>::Vector::Iterator &
UniversalSet<T, UNIVERSE_SIZE>::Vector::Iterator::operator++() {

    do {
        ++index;
    } while (!vector_ptr->bits[index] && index < vector_ptr->bits.size());

    return *this;
}

template<typename T, size_t UNIVERSE_SIZE>
const typename UniversalSet<T, UNIVERSE_SIZE>::Vector::Iterator
UniversalSet<T, UNIVERSE_SIZE>::Vector::Iterator::operator++(int) {

    Iterator it(*this);
    ++(*this);
    return it;
}

template<typename T, size_t UNIVERSE_SIZE>
const T & UniversalSet<T, UNIVERSE_SIZE>::Vector::Iterator::operator*() const {
    return vector_ptr->universe_ptr->elements[index];
}

template<typename T, size_t UNIVERSE_SIZE>
const T *UniversalSet<T, UNIVERSE_SIZE>::Vector::Iterator::operator->() const {
    return &vector_ptr->universe_ptr->elements[index];
}

template<typename T, size_t UNIVERSE_SIZE>
UniversalSet<T, UNIVERSE_SIZE>::Vector::Iterator::operator bool() const {
    return index < UNIVERSE_SIZE;
}

template<typename T, size_t UNIVERSE_SIZE>
UniversalSet<T, UNIVERSE_SIZE>::Vector::Vector(const UniversalSet *universe_ptr)
        : universe_ptr(universe_ptr) { }

template<typename T, size_t UNIVERSE_SIZE>
UniversalSet<T, UNIVERSE_SIZE>::UniversalSet(const std::array<T, UNIVERSE_SIZE> & elements)
        : elements(elements) { }

template<typename T, size_t UNIVERSE_SIZE>
UniversalSet<T, UNIVERSE_SIZE>::Vector::Vector(const UniversalSet *universe_ptr,
                                               const std::bitset<UNIVERSE_SIZE> & bits) : universe_ptr(universe_ptr), bits(bits) { }

template<typename T, size_t UNIVERSE_SIZE>
std::size_t UniversalSet<T, UNIVERSE_SIZE>::Vector::count() const {
    return bits.count();
}

template<typename T, size_t UNIVERSE_SIZE>
std::pair<typename UniversalSet<T, UNIVERSE_SIZE>::Vector::Iterator, bool>
UniversalSet<T, UNIVERSE_SIZE>::Vector::insert(std::size_t index) {

    if (bits.test(index)) {
        return std::make_pair(Iterator(this, bits.size()), false);
    } else {
        bits[index] = 1;
        return std::make_pair(Iterator(this, index), true);
    }
}

template<typename T, size_t UNIVERSE_SIZE>
bool UniversalSet<T, UNIVERSE_SIZE>::Vector::isMember(std::size_t i) const {
    return bits.test(i);
}

template<typename T, size_t UNIVERSE_SIZE>
typename UniversalSet<T, UNIVERSE_SIZE>::Vector::Iterator
UniversalSet<T, UNIVERSE_SIZE>::Vector::elemIterator(std::size_t index) const {
    return bits[index] ? Iterator(this, index) : Iterator(this, bits.size());
}

template<typename T, size_t UNIVERSE_SIZE>
bool UniversalSet<T, UNIVERSE_SIZE>::Vector::remove(std::size_t i) {
    if (bits.test(i)) {
        bits[i] = 0;
        return true;
    } else {
        return false;
    }
}

template<typename T, size_t UNIVERSE_SIZE>
bool UniversalSet<T, UNIVERSE_SIZE>::Vector::operator==(const UniversalSet::Vector &v2)
const {
    return (bits == v2.bits) && (*universe_ptr == v2);
}

template<typename T, size_t UNIVERSE_SIZE>
bool UniversalSet<T, UNIVERSE_SIZE>::Vector::operator!=(const UniversalSet::Vector &v2)
const {

    return bits != v2.bits && (*universe_ptr != v2);
}

template<typename T, size_t UNIVERSE_SIZE>
typename UniversalSet<T, UNIVERSE_SIZE>::Vector
UniversalSet<T, UNIVERSE_SIZE>::Vector::operator+(const UniversalSet::Vector &v2) const {
    std::bitset<UNIVERSE_SIZE> result(bits | v2.bits);

    return Vector(universe_ptr, result);
}

template<typename T, size_t UNIVERSE_SIZE>
typename UniversalSet<T, UNIVERSE_SIZE>::Vector
UniversalSet<T, UNIVERSE_SIZE>::Vector::operator-(const UniversalSet::Vector &v2) const {
    std::bitset<UNIVERSE_SIZE> result(bits & ~v2.bits);

    return Vector(universe_ptr, result);
}

template<typename T, size_t UNIVERSE_SIZE>
typename UniversalSet<T, UNIVERSE_SIZE>::Vector
UniversalSet<T, UNIVERSE_SIZE>::Vector::operator*(const UniversalSet::Vector &v2) const {
    std::bitset<UNIVERSE_SIZE> result(bits & v2.bits);

    return Vector(universe_ptr, result);
}

template<typename T, size_t UNIVERSE_SIZE>
typename UniversalSet<T, UNIVERSE_SIZE>::Vector
UniversalSet<T, UNIVERSE_SIZE>::Vector::operator/(const UniversalSet::Vector &v2) const {
    std::bitset<UNIVERSE_SIZE> result(bits ^ v2.bits);

    return Vector(universe_ptr, result);
}

template<typename T, size_t UNIVERSE_SIZE>
typename UniversalSet<T, UNIVERSE_SIZE>::Vector::Iterator
UniversalSet<T, UNIVERSE_SIZE>::Vector::begin() const {
    int first = 0;
    while (!bits[first]) {
        ++first;
    }

    return Iterator(this, first);
}

template<typename T, size_t UNIVERSE_SIZE>
typename UniversalSet<T, UNIVERSE_SIZE>::Vector::Iterator
UniversalSet<T, UNIVERSE_SIZE>::Vector::end() const {

    return Iterator(this, bits.size());
}

template<typename T, size_t UNIVERSE_SIZE>
const T &UniversalSet<T, UNIVERSE_SIZE>::elem(std::size_t i) const {
    return elements[i];
}

template<typename T, size_t UNIVERSE_SIZE>
const T &UniversalSet<T, UNIVERSE_SIZE>::operator[](std::size_t i) const {
    return elements[i];
}

template<typename T, size_t UNIVERSE_SIZE>
typename UniversalSet<T, UNIVERSE_SIZE>::Vector UniversalSet<T, UNIVERSE_SIZE>::makeVector()
const {

    return Vector(this);
}




#endif //SET_UNIVERSALSET_HPP
