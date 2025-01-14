#include "Point.h"


int Point::pointsCounter = 0;

bool operator==(const Point& p1, const Point& p2) {
	if (p1.x == p2.x && p1.y == p2.y && p1.z == p2.z)
		return true;
	else
		return false;
}



Point operator+(const Point& p1, const Point& p2) {
	return Point{ p1.x+p2.x, p1.y+p2.y, p1.z+p2.z };
}

Point operator-(const Point& p1, const Point& p2) {
	return Point{ p1.x - p2.x, p1.y - p2.y, p1.z - p2.z };
}

Point Point::operator-() {
	return Point{ -x, -y, -z };
}

Point operator*(const Point& p1, const Point& p2) {
	return Point{ p1.x * p2.x, p1.y * p2.y, p1.z * p2.z };
}

Point operator*(const Point& p1, int n) {
	return Point{ p1.x * n, p1.y * n, p1.z * n };
}


std::ostream& operator<<(std::ostream& os, const Point& p) {
	os << "Point's coordinates: ";
	os << "\nX: " << p.x;
	os << "\tY: " << p.y;
	os << "\tZ: " << p.z << endl;
	return os;
}


//bool operator<(const Point& p1, const Point& p2) {
//	if (p1.x == p2.x) {
//		return p1.y < p2.y;
//	}
//	else if (p1.y == p2.y) {
//		return p1.z < p2.z;
//	}
//	else
//		return p1.x < p2.x;
//}