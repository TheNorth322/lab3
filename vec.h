#include <string>
#include <cstring>
#include <iostream>
#include "commission_wage_worker.h"
#include "hourly_wage_worker.h"

#ifndef LAB3_VECTOR_H
#define LAB3_VECTOR_H

template<typename T>
class Vector {
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

template<typename T>
inline std::ostream &operator<<(std::ostream &, const Vector<T> &);

#endif //LAB3_VECTOR_H
