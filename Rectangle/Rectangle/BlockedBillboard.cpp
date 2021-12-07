#include "Problems.h"
#include "Rectangle.h"

void blockedBillboard(std::istream& is, std::ostream& os) {

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