#pragma once
#include "common.h"

class Worker {
public:
  Worker(std::string _fullName, Gender _gender)
      : fullName(_fullName), gender(_gender) {
    if (fullName.length() == 0) {
      throw std::invalid_argument(
          "Invalid 'fullName' argument. The length must be non-zero");
    }
  }

  std::string getFullName() const { return fullName; }

  Gender getGender() const { return gender; }

  virtual void work(int) = 0;

  virtual int calculateWage() = 0;

private:
  std::string fullName;
  Gender gender;
};
