#include "worker.h"

Worker::Worker(std::string _fullName, Gender _gender)
    : fullName(_fullName), gender(_gender) {
  if (fullName.length() == 0) {
    throw std::invalid_argument(
        "Invalid 'fullName' argument. The length must be non-zero");
  }
}
