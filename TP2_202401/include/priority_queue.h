// include/priority_queue.h
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

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

#endif // PRIORITY_QUEUE_H
