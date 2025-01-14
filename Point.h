#pragma once
#include <iostream>

using std::cin;
using std::cout;
using std::endl;


class Point {
	static int pointsCounter;
	int x;
	int y;
	int z;
public:
	friend bool operator==(const Point& p1, const Point& p2);
	friend Point operator+(const Point& p1, const Point& p2);
	friend Point operator-(const Point& p1, const Point& p2);
	friend Point operator*(const Point& p1, const Point& p2);
	friend Point operator*(const Point& p1, int n);
	friend std::ostream& operator<<(std::ostream& os, const Point& p);
	Point() : Point(0, 0, 0) {
		//std::cout << "Point NO ARGS Constructor Called" << std::endl;
	}

	Point(int xp, int yp = 0, int zp = 0) : x{ xp }, y{ yp }, z{ zp } {
		//cout << "Point OverLoaded Constructor Called" << endl;
		pointsCounter++;
	}

	//friend bool operator<(const Point& p1, const Point& p2);



	~Point() {
		//cout << "Point Destructor Called" << endl;
		pointsCounter--;
	}

	int setX(int n) {
		x = n;
		return x;
	}
	int setY(int n) {
		y = n;
		return x;
	}
	int setZ(int n) {
		z = n;
		return x;
	}

	int getX() const {
		return x;
	}

	int getY() const {
		return y;
	}

	int getZ() const {
		return z;
	}

	static int getCounter() {
		return pointsCounter;
	}
	
	Point operator-();

	operator bool() const {
		return (x || y || z);
	}
	
		


	void initPoint() {
		int num;
		cout << "Enter X coordinate: ";
		cin >> num;
		setX(num);

		cout << "Enter Y coordinate: ";
		cin >> num;
		setY(num);

		cout << "Enter Z coordinate: ";
		cin >> num;
		setZ(num);
	}


};





