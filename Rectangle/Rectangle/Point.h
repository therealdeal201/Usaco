#pragma once

#include <iostream>

template <class _Numeric_Measurement_Type>

struct Point {

	_Numeric_Measurement_Type x;
	_Numeric_Measurement_Type y;

	friend Point<_Numeric_Measurement_Type> operator+ (const Point<_Numeric_Measurement_Type>& lhs, const Point<_Numeric_Measurement_Type>& rhs) {
		return {lhs.x + rhs.x, lhs.y + rhs.y};
	}

	friend Point<_Numeric_Measurement_Type> operator- (const Point<_Numeric_Measurement_Type>& lhs, const Point<_Numeric_Measurement_Type>& rhs) {
		return { lhs.x - rhs.x, lhs.y - rhs.y };
	}

	friend Point<_Numeric_Measurement_Type> operator* (const Point<_Numeric_Measurement_Type>& point, const _Numeric_Measurement_Type& factor) {
		return { point.x * factor, point.y * factor };
	}

	friend Point<_Numeric_Measurement_Type> operator* (const _Numeric_Measurement_Type& factor, const Point<_Numeric_Measurement_Type>& point) {
		return point * factor;
	}

	friend std::ostream& operator<< (std::ostream& os, const Point<_Numeric_Measurement_Type>& point) {
		os << "X: " << point.x << " Y: " << point.y  << std::endl;
		return os;
	}

	friend std::istream& operator>> (std::istream& is, Point<_Numeric_Measurement_Type>& point) {
		is >> point.x >> point.y;
		return is;
	}

	_Numeric_Measurement_Type dotProduct(const Point<_Numeric_Measurement_Type>& other) const {
		return x * other.x + y * other.y;
	}

};