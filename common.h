#pragma once

#include <iostream>

enum class Gender {
  Male = 1,
  Female,
};

enum class Recruation { Commission = 1, Hourly, Both, None };

inline std::istream &operator>>(std::istream &stream, Gender &gender) {
  int buffer;
  stream >> buffer;

  if (buffer == 1) {
    gender = Gender::Male;
  } else if (buffer == 2) {
    gender = Gender::Female;
  } else {
    stream.setstate(std::iostream::badbit);
  }

  return stream;
}

inline std::istream &operator>>(std::istream &stream, Recruation &recruation) {
  int buffer;
  stream >> buffer;

  if (buffer == 1) {
    recruation = Recruation::Hourly;
  } else if (buffer == 2) {
    recruation = Recruation::Commission;
  } else if (buffer == 3) {
    recruation = Recruation::Both;
  } else {
    stream.setstate(std::iostream::badbit);
  }

  return stream;
}

inline std::ostream &operator<<(std::ostream &stream, Gender gender) {
  switch (gender) {
  case Gender::Male:
    stream << "male";
    break;
  case Gender::Female:
    stream << "female";
    break;
  }

  return stream;
}
