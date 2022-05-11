#include "vector.h"

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    // Учёт самоприсваивания a = a;
    if (this == &other)
        return *this;
        
    // Убираемся в левом операнде
    delete[] m_data;

    // Осуществляем глубокое копирование
    m_size = other.m_size;
    m_data = new int[m_size];
    std::memcpy(m_data, other.m_data, sizeof(int) * other.m_size);

    // Возвращаем ссылку на левый операнд для того, чтобы можно было
    // писать конструкции типа a = b = c;
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other)
{

    // Учёт самоприсваивания a = a;
    if (this == &other)
        return *this;
        
    // Убираемся в левом операнде
    delete[] m_data;

    // Осуществляем поверхностное копирование
    m_size = other.m_size;
    m_data = other.m_data;    

    // Переводим правый объект в опустошённое состояние
    other.m_size = 0;
    other.m_data = nullptr;

    // Возвращаем ссылку на левый операнд для того, чтобы можно было
    // писать конструкции типа a = b = c;
    return *this;
}

template <typename T>
T& Vector<T>::operator[](std::size_t pos)
{
    if (nullptr == m_data)
        throw std::runtime_error("The array is uninitialized due to a move operation");

    if (pos >= m_size)
        throw std::out_of_range("pos >= " + std::to_string(m_size));

    return m_data[pos];
}

template <typename T>
const T& Vector<T>::operator[](std::size_t pos) const
{
    if (nullptr == m_data)
        throw std::runtime_error("The array is uninitialized due to a move operation");

    if (pos >= m_size)
        throw std::out_of_range("pos >= " + std::to_string(m_size));
                
    return m_data[pos];
}

template <typename T>
void Vector<T>::push(T item) {
  Vector<T> *newData =
      new T[m_size + 1];

  std::memcpy(newData, m_data, m_size);
  newData[m_size] = item;

  delete[] m_data;
  m_data = newData;

  m_size += 1;
}

template <typename T>
void Vector<T>::del(std::size_t pos) {
    Vector<T> *newData =
        new T[m_size - 1];

    if (pos >= m_size)
        throw std::out_of_range("pos >= " + std::to_string(m_size));

    if (nullptr == m_data)
        throw std::runtime_error("The array is uninitialized due to a move operation");

    std::memcpy(newData, m_data, pos);
    std::memcpy(newData + pos, m_data + pos + 1,
                m_size - pos - 1);

    delete[] m_data;

    m_data = newData;
    m_size -= 1;
}

template <typename T>
inline std::ostream operator<<(std::ostream &stream, const Vector<T>& vec) {
    stream << "[\n";

    for (std::size_t i = 0; i < vec.getSize(); i++)
        stream << vec[i] << ",\n";

    stream << "]\n";
}
