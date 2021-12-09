#pragma once

#include <iostream>

template <class P>

struct Point {

	P x;
	P y;

	friend Point<P> operator+ (const Point<P>& lhs, const Point<P>& rhs) {
		return {lhs.x + rhs.x, lhs.y + rhs.y};
	}

	friend Point<P> operator- (const Point<P>& lhs, const Point<P>& rhs) {
		return { lhs.x - rhs.x, lhs.y - rhs.y };
	}

	friend Point<P> operator* (const Point<P>& point, const P& factor) {
		return { point.x * factor, point.y * factor };
	}

	friend Point<P> operator* (const P& factor, const Point<P>& point) {
		return point * factor;
	}

	friend std::ostream& operator<< (std::ostream& os, const Point<P>& point) {
		os << "X: " << point.x << " Y: " << point.y  << std::endl;
		return os;
	}

	friend std::istream& operator>> (std::istream& is, Point<P>& point) {
		is >> point.x >> point.y;
		return is;
	}

	P dotProduct(const Point<P>& other) const {
		return x * other.x + y * other.y;
	}

};