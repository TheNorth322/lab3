#pragma once

#include <cstring>
#include <iostream>

// Могут возникать проблемы при копировании массива классов с помощью
// std::memcpy. Поэтому для копирования используется данная функция.
template <typename T> void copy(T *dest, T *src, std::size_t count) {
  if (src == nullptr || dest == nullptr)
    return;

  for (std::size_t i = 0; i < count; i++)
    dest[i] = src[i];
}

template <typename T> class Vector {
public:
  Vector() : size(0), data(nullptr) {}

  Vector(const Vector<T> &other) : size(other.size), data(new T[other.size]) {
    copy(data, other.data, size);
  }

  ~Vector() {
    if (data != nullptr)
      delete[] data;
  }

  Vector(Vector<T> &&other) : size(other.size), data(other.data) {
    other.size = 0u;
    other.data = nullptr;
  }

  std::size_t getSize() const { return size; }

  Vector<T> &operator=(const Vector<T> &other) {
    // Учёт самоприсваивания a = a;
    if (this == &other)
      return *this;

    // Убираемся в левом операнде
    if (data != nullptr)
      delete[] data;

    // Осуществляем глубокое копирование
    size = other.size;
    data = new T[size];

    copy(data, other.data, other.size);

    // Возвращаем ссылку на левый операнд для того, чтобы можно было
    // писать конструкции типа a = b = c;
    return *this;
  }

  Vector<T> &operator=(Vector<T> &&other) {
    // Учёт самоприсваивания a = a;
    if (this == &other)
      return *this;

    // Убираемся в левом операнде
    if (data != nullptr)
      delete[] data;

    // Осуществляем поверхностное копирование
    size = other.size;
    data = other.data;

    // Переводим правый объект в опустошённое состояние
    other.size = 0;
    other.data = nullptr;

    // Возвращаем ссылку на левый операнд для того, чтобы можно было
    // писать конструкции типа a = b = c;
    return *this;
  }

  T &operator[](std::size_t pos) {
    if (nullptr == data)
      throw std::runtime_error(
          "The array is uninitialized due to a move operation");

    if (pos >= size)
      throw std::out_of_range("pos >= " + std::to_string(size));

    return data[pos];
  }

  const T &operator[](std::size_t pos) const {
    if (nullptr == data)
      throw std::runtime_error(
          "The array is uninitialized due to a move operation");

    if (pos >= size)
      throw std::out_of_range("pos >= " + std::to_string(size));

    return data[pos];
  }

  // Добавление элемента в конец вектора
  void push(T item) {
    T *newData = new T[size + 1];

    copy(newData, data, size);
    newData[size] = item;

    if (data != nullptr)
      delete[] data;

    data = newData;
    size++;
  }

  // Удаление элемента по индексу
  void del(std::size_t pos) {
    T *newData = new T[size - 1];

    if (pos >= size)
      throw std::out_of_range("pos >= " + std::to_string(size));

    if (nullptr == data)
      throw std::runtime_error(
          "The array is uninitialized due to a move operation");

    copy(newData, data, pos);
    copy(newData + pos, data + pos + 1, size - pos - 1);

    delete[] data;

    data = newData;
    size -= 1;
  }

private:
  std::size_t size;
  T *data;
};

template <typename T>
std::ostream &operator<<(std::ostream &stream, const Vector<T> &vec) {
  stream << "[\n";

  for (std::size_t i = 0; i < vec.getSize(); i++)
    stream << vec[i] << ",\n";

  stream << "]\n";

  return stream;
}
