#pragma once

enum class Gender {
	Male = 1,
	Female,
};

inline std::istream& operator>>(std::istream& stream, Gender& gender) 
{
	stream >> gender;
	return stream;
}