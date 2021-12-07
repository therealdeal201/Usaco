#pragma once

#include <algorithm>

#include "Point.h"

template <class _Numeric_Point_Type>

class Rectangle {

private:

	Point<_Numeric_Point_Type> bottomLeft;

	Point<_Numeric_Point_Type> topRight;

	_Numeric_Point_Type xDimension;

	_Numeric_Point_Type yDimension;

	_Numeric_Point_Type area;

	_Numeric_Point_Type perim;

public:

	Rectangle(const Point<_Numeric_Point_Type>& bl = { 0,0 }, const Point<_Numeric_Point_Type>& tr = { 0,0 }) :
		bottomLeft(bl),
		topRight(tr),
		xDimension(tr.x - bl.x),
		yDimension(tr.y - bl.y),
		area(xDimension* yDimension),
		perim((2 * xDimension) + (2 * yDimension))
	{	}


	template <class _Numeric_Point_Type>
	friend std::ostream& operator<<(std::ostream& os, const Rectangle<_Numeric_Point_Type>& r) {
		os << "BL: " << r.bottomLeft << "TR: " << r.topRight;
		return os;
	}

	template <class _Numeric_Point_Type>
	friend std::istream& operator>>(std::istream& is, Rectangle<_Numeric_Point_Type>& r) {
		Point<_Numeric_Point_Type> bl, tr;
		is >> bl >> tr;
		r = Rectangle(bl, tr);
		return is;
	}

	_Numeric_Point_Type intersectArea(const Rectangle<_Numeric_Point_Type>& r) {
		_Numeric_Point_Type xOverlap = std::max(0, std::min(topRight.x, r.topRight.x) - std::max( bottomLeft.x, r.bottomLeft.x) );
		_Numeric_Point_Type yOverlap = std::max(0, std::min(topRight.y, r.topRight.y) - std::max( bottomLeft.y, r.bottomLeft.y) );
		return xOverlap * yOverlap;
	}

	_Numeric_Point_Type getArea() {
		return area;
	}

};