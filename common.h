#pragma once
#include <iostream>

enum class Gender {
	Male = 1,
	Female,
};

inline std::istream& operator>>(std::istream& stream, Gender& gender) 
{
	char buffer;
	stream >> buffer;

	if (buffer == '1') {
		gender = Gender::Male;
	}

	else if (buffer == '2') {
		gender = Gender::Female;
	}

	return stream;
}

inline std::ostream& operator<<(std::ostream& stream, Gender& gender) 
{
	if (gender == Gender::Male) {
		stream << "Male";
	}

	if (gender == Gender::Female) {
		stream << "Female";
	}

	return stream;
}