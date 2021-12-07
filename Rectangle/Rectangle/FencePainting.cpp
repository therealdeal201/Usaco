#include "Problems.h"

void fencePainting(std::istream& is, std::ostream& os) {

	int a, b, c, d;
	is >> a >> b >> c >> d;

	os << std::min( (b-a) + (d-c) , b-c );

}