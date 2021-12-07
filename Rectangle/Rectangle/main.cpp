// Rectangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <algorithm>

template <class _Numeric_Measurement_Type>

struct Point {

	_Numeric_Measurement_Type x;
	_Numeric_Measurement_Type y;

	friend Point<_Numeric_Measurement_Type> operator+ (const Point<_Numeric_Measurement_Type>& lhs, const Point<_Numeric_Measurement_Type>& rhs) {
		return { lhs.x + rhs.x, lhs.y + rhs.y };
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
		os << "X: " << point.x << " Y: " << point.y << std::endl;
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

template <class _Numeric_Measurement_Type>

class Rectangle {

private:

	Point<_Numeric_Measurement_Type> bottomLeft;

	Point<_Numeric_Measurement_Type> topRight;

	_Numeric_Measurement_Type xDimension;

	_Numeric_Measurement_Type yDimension;

	_Numeric_Measurement_Type area;

	_Numeric_Measurement_Type perim;

public:

	Rectangle(const Point<_Numeric_Measurement_Type>& bl = { 0,0 }, const Point<_Numeric_Measurement_Type>& tr = { 0,0 } ) :
		bottomLeft(bl),
		topRight(tr),
		xDimension(tr.x - bl.x),
		yDimension(tr.y - bl.y),
		area(xDimension* yDimension),
		perim((2 * xDimension) + (2 * yDimension))
	{	}

	friend std::ostream& operator<<(std::ostream& os, const Rectangle<_Numeric_Measurement_Type>& r) {
		os << "BL: " << r.bottomLeft << "TR: " << r.topRight;
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Rectangle<_Numeric_Measurement_Type>& r) {
		Point<_Numeric_Measurement_Type> bl, tr;
		is >> bl >> tr;
		r = Rectangle(bl, tr);
		return is;
	}

	_Numeric_Measurement_Type intersectArea(const Rectangle<_Numeric_Measurement_Type>& r) {
		_Numeric_Measurement_Type xOverlap = std::max(0, std::min(topRight.x, r.topRight.x) - std::max(bottomLeft.x, r.bottomLeft.x));
		_Numeric_Measurement_Type yOverlap = std::max(0, std::min(topRight.y, r.topRight.y) - std::max(bottomLeft.y, r.bottomLeft.y));
		return xOverlap * yOverlap;
	}

	_Numeric_Measurement_Type getArea() {
		return area;
	}

};

void blockedBillboardFinal(std::istream& is, std::ostream& os) {

	Rectangle<int> billboard1, billboard2, truck;

	is >> billboard1 >> billboard2 >> truck;

	int uncoveredArea = billboard1.getArea() + billboard2.getArea();

	/*

	os << billboard1 << billboard2 << truck;

	os << billboard1.getArea() << std::endl;
	os << billboard2.getArea() << std::endl;
	os << billboard1.intersectArea(truck) << std::endl;
	os << billboard2.intersectArea(truck) << std::endl;

	*/

	os << uncoveredArea - billboard1.intersectArea(truck) - billboard2.intersectArea(truck);

}

int main()
{

	std::ifstream input;

	input.open("billboard.in");

	std::ofstream output;

	output.open("billboard.out");

	blockedBillboardFinal(input, output);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
