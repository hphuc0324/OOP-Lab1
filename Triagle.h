#pragma once
#include<iostream>
using namespace std;

class Point {
private:
	float _x;
	float _y;

public:
	float getX();
	void setX(int);

	float getY();
	void setY(float);

public:
	Point();
	Point(float, float);
	
public:
	void input();
	void output();
	float distanceTo(Point);
	float distanceToOx();
	float distancetoOy();
};

class Triangle {
private:
	Point _A;
	Point _B;
	Point _C;
public:
	void input();
	void output();
	bool isValidTriangle();
	string typeOfTriangle();
	float perimeter();
	float area();
	Point centerG();
};

class Calculate {
public:
	static bool checkEqualSumSquare(Point, Point, Point);
};
