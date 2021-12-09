#pragma once

#include <algorithm>

#include "Point.h"

template <class R>

class Rectangle {

private:

	Point<R> bottomLeft;

	Point<R> topRight;

	R xDimension;

	R yDimension;

	R area;

	R perim;

public:

	Rectangle(const Point<R>& bl = { 0,0 }, const Point<R>& tr = { 0,0 }) :
		bottomLeft(bl),
		topRight(tr),
		xDimension(tr.x - bl.x),
		yDimension(tr.y - bl.y),
		area(xDimension* yDimension),
		perim((2 * xDimension) + (2 * yDimension))
	{	}


	template <class R>
	friend std::ostream& operator<<(std::ostream& os, const Rectangle<R>& r) {
		os << "BL: " << r.bottomLeft << "TR: " << r.topRight;
		return os;
	}

	template <class R>
	friend std::istream& operator>>(std::istream& is, Rectangle<R>& r) {
		Point<R> bl, tr;
		is >> bl >> tr;
		r = Rectangle(bl, tr);
		return is;
	}

	R intersectArea(const Rectangle<R>& r) {
		R xOverlap = std::max(0, std::min(topRight.x, r.topRight.x) - std::max( bottomLeft.x, r.bottomLeft.x) );
		R yOverlap = std::max(0, std::min(topRight.y, r.topRight.y) - std::max( bottomLeft.y, r.bottomLeft.y) );
		return xOverlap * yOverlap;
	}

	R getArea() {
		return area;
	}

};