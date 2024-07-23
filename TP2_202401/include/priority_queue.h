// include/priority_queue.h
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <cstddef>
#include <algorithm>

template <typename T>
class PriorityQueue
{
public:
    PriorityQueue();
    ~PriorityQueue();

    void push(const T &value);
    void pop();
    const T &top() const;
    bool empty() const;

private:
    void bubble_up(size_t index);
    void bubble_down(size_t index);
    void resize(size_t new_capacity);

    size_t size_;
    size_t capacity_;
    T *data_;
};

template <typename T>
PriorityQueue<T>::PriorityQueue() : size_(0), capacity_(10), data_(new T[10]) {}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
    delete[] data_;
}

template <typename T>
void PriorityQueue<T>::push(const T &value)
{
    if (size_ == capacity_)
    {
        resize(capacity_ * 2);
    }
    data_[size_++] = value;
    bubble_up(size_ - 1);
}

template <typename T>
void PriorityQueue<T>::pop()
{
    if (size_ == 0)
        return;
    data_[0] = data_[--size_];
    bubble_down(0);
}

template <typename T>
const T &PriorityQueue<T>::top() const
{
    return data_[0];
}

template <typename T>
bool PriorityQueue<T>::empty() const
{
    return size_ == 0;
}

template <typename T>
void PriorityQueue<T>::bubble_up(size_t index)
{
    while (index > 0)
    {
        size_t parent = (index - 1) / 2;
        if (data_[index] < data_[parent])
        {
            std::swap(data_[index], data_[parent]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

template <typename T>
void PriorityQueue<T>::bubble_down(size_t index)
{
    while (index * 2 + 1 < size_)
    {
        size_t left = index * 2 + 1;
        size_t right = left + 1;
        size_t min_index = index;

        if (left < size_ && data_[left] < data_[min_index])
        {
            min_index = left;
        }

        if (right < size_ && data_[right] < data_[min_index])
        {
            min_index = right;
        }

        if (min_index != index)
        {
            std::swap(data_[index], data_[min_index]);
            index = min_index;
        }
        else
        {
            break;
        }
    }
}

template <typename T>
void PriorityQueue<T>::resize(size_t new_capacity)
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

#endif // PRIORITY_QUEUE_H
