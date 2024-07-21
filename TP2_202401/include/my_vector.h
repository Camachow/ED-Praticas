// include/my_vector.h
#ifndef MY_VECTOR_H
#define MY_VECTOR_H

template <typename T>
class MyVector
{
public:
    MyVector();
    ~MyVector();

    void push_back(const T &value);
    T &operator[](size_t index);
    const T &operator[](size_t index) const;
    size_t size() const;

private:
    void resize(size_t new_capacity);

    size_t size_;
    size_t capacity_;
    T *data_;
};

#endif // MY_VECTOR_H
