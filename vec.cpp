#include "vec.h"

template <typename T>
inline Vector<T>::Vector() : size(0), data(new T[size]) {}

template <typename T>
inline Vector<T>::Vector(const Vector<T> &other)
    : size(other.size), data(new T[other.size]) {
  std::memcpy(data, other.data, sizeof(T) * other.size);
}

template <typename T> inline Vector<T>::~Vector() {
  if (data != nullptr)
    delete[] data;
}

template <typename T>
inline Vector<T>::Vector(Vector<T> &&other)
    : size(other.size), data(other.data) {
  other.size = 0u;
  other.data = nullptr;
}

template <typename T> inline std::size_t Vector<T>::getSize() const {
  return size;
}
template <typename T> Vector<T> &Vector<T>::operator=(const Vector<T> &other) {
  // Учёт самоприсваивания a = a;
  if (this == &other)
    return *this;

  // Убираемся в левом операнде
  delete[] data;

  // Осуществляем глубокое копирование
  size = other.size;
  data = new T[size];
  std::memcpy(data, other.data, sizeof(T) * other.size);

  // Возвращаем ссылку на левый операнд для того, чтобы можно было
  // писать конструкции типа a = b = c;
  return *this;
}

template <typename T> Vector<T> &Vector<T>::operator=(Vector<T> &&other) {

  // Учёт самоприсваивания a = a;
  if (this == &other)
    return *this;

  // Убираемся в левом операнде
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

template <typename T> T &Vector<T>::operator[](std::size_t pos) {
  if (nullptr == data)
    throw std::runtime_error(
        "The array is uninitialized due to a move operation");

  if (pos >= size)
    throw std::out_of_range("pos >= " + std::to_string(size));

  return data[pos];
}

template <typename T> const T &Vector<T>::operator[](std::size_t pos) const {
  if (nullptr == data)
    throw std::runtime_error(
        "The array is uninitialized due to a move operation");

  if (pos >= size)
    throw std::out_of_range("pos >= " + std::to_string(size));

  return data[pos];
}

// Добавление элемента в конец вектора
template <typename T> void Vector<T>::push(T item) {
  T *newData = new T[size + 1];

  for (std::size_t i = 0; i < size; i++) {
    newData[i] = data[i];
  }

  newData[size] = item;

  delete[] data;
  data = newData;

  size++;
}

// Удаление элемента по индексу
template <typename T> void Vector<T>::del(std::size_t pos) {
  T *newData = new T[size - 1];

  if (pos >= size)
    throw std::out_of_range("pos >= " + std::to_string(size));

  if (nullptr == data)
    throw std::runtime_error(
        "The array is uninitialized due to a move operation");

  for (std::size_t i = 0; i < pos; i++) {
    newData[i] = data[i];
  }

  for (std::size_t i = pos + 1; i < size; i++) {
    newData[i - 1] = data[i];
  }

  delete[] data;

  data = newData;
  size -= 1;
}

template <typename T>
inline std::ostream &operator<<(std::ostream &stream, const Vector<T> &vec) {
  stream << "[\n";

  for (std::size_t i = 0; i < vec.getSize(); i++)
    stream << vec[i] << ",\n";

  stream << "]\n";
  return stream;
}
