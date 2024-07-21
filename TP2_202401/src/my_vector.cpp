// src/my_vector.cpp
#include "../include/my_vector.h"
#include <cstdlib>

template <typename T>
MyVector<T>::MyVector() : size_(0), capacity_(1), data_(new T[1]) {}

template <typename T>
MyVector<T>::~MyVector()
{
    delete[] data_;
}

template <typename T>
void MyVector<T>::push_back(const T &value)
{
    if (size_ == capacity_)
    {
        resize(capacity_ * 2);
    }
    data_[size_++] = value;
}

template <typename T>
T &MyVector<T>::operator[](size_t index)
{
    return data_[index];
}

template <typename T>
const T &MyVector<T>::operator[](size_t index) const
{
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
    for (size_t i = 0; i < size_; ++i)
    {
        new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}
