#pragma once
#include <string>
#include <cstring>
#include <iostream>
template <typename T>
class Vector
{
public:
    // Vector(std::size_t size, T defaultValue);
    Vector();
    Vector(const Vector<T> &);
    Vector(Vector<T> &&);
    Vector &operator=(const Vector<T> &);
    Vector &operator=(Vector<T> &&);
    ~Vector();

    T &operator[](std::size_t);
    const T &operator[](std::size_t) const;
    std::size_t getSize() const;
    void push(T);
    void del(std::size_t);

private:
    std::size_t m_size;
    T *m_data;
};
template <typename T>
inline Vector<T>::Vector()
    : m_size(0), m_data(new T[m_size])
{}

template <typename T>
inline Vector<T>::Vector(const Vector<T> &other)
    : m_size(other.m_size), m_data(new int[other.m_size])
{
    std::memcpy(m_data, other.m_data, sizeof(int) * other.m_size);
}

template <typename T>
inline Vector<T>::~Vector()
{
    if (m_data != nullptr) delete[] m_data;
}

template <typename T>
inline Vector<T>::Vector(Vector<T> &&other)
    : m_size(other.m_size), m_data(other.m_data)
{
    other.m_size = 0u;
    other.m_data = nullptr;
}

template <typename T>
inline std::size_t Vector<T>::getSize() const
{
    return m_size;
}