#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <cstddef>
#include <algorithm>
#include <stdexcept>

template <typename T>
class MyVector
{
public:
    MyVector();
    MyVector(size_t size, const T &value = T());
    MyVector(const MyVector &other);            // Construtor de cópia
    MyVector &operator=(const MyVector &other); // Operador de atribuição
    ~MyVector();

    void push_back(const T &value);
    T &operator[](size_t index);
    const T &operator[](size_t index) const;
    size_t size() const;

private:
    void resize(size_t new_capacity);
    void free_memory();

    size_t size_;
    size_t capacity_;
    T *data_;
};

// Implementação
template <typename T>
MyVector<T>::MyVector() : size_(0), capacity_(0), data_(nullptr) {}

template <typename T>
MyVector<T>::MyVector(size_t size, const T &value) : size_(size), capacity_(size), data_(new T[size])
{
    std::fill(data_, data_ + size_, value);
}

template <typename T>
MyVector<T>::MyVector(const MyVector &other) : size_(other.size_), capacity_(other.capacity_), data_(new T[other.capacity_])
{
    std::copy(other.data_, other.data_ + other.size_, data_);
}

template <typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector &other)
{
    if (this != &other)
    {
        free_memory();
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new T[capacity_];
        std::copy(other.data_, other.data_ + other.size_, data_);
    }
    return *this;
}

template <typename T>
MyVector<T>::~MyVector()
{
    free_memory();
}

template <typename T>
void MyVector<T>::push_back(const T &value)
{
    if (size_ == capacity_)
    {
        resize(capacity_ == 0 ? 1 : 2 * capacity_);
    }
    data_[size_++] = value;
}

template <typename T>
T &MyVector<T>::operator[](size_t index)
{
    if (index >= size_)
    {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template <typename T>
const T &MyVector<T>::operator[](size_t index) const
{
    if (index >= size_)
    {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template <typename T>
size_t MyVector<T>::size() const
{
    return size_;
}

template <typename T>
void MyVector<T>::resize(size_t new_capacity)
{
    T *new_data = new T[new_capacity];
    std::copy(data_, data_ + size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}

template <typename T>
void MyVector<T>::free_memory()
{
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

#endif // MY_VECTOR_H
