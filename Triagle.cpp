#include"Triagle.h"

Point::Point() {
	_x = 0;
	_y = 0;
}

Point::Point(float x, float y) {
	_x = x;
	_y = y;
}

float Point::getX() {
	return _x;
}

void Point::setX(int x) {
	_x = x;
}

float Point::getY() {
	return _y;
}

void Point::setY(float y) {
	_y = y;
}

void Point::input() {
	float x, y;
	
	cout << "Input x: ";
	cin >> x;

	cout << "Input y: ";
	cin >> y;

	_x = x;
	_y = y;
}

void Point::output() {
	cout << "(" << _x << ", " << _y << ")";
}

float Point::distanceTo(Point other) {
	float otherX = other.getX();
	float otherY = other.getY();

	float distance;
	distance = sqrt(pow((_x - otherX), 2) + pow((_y + otherY), 2));

	return distance;
}

float Point::distanceToOx() {
	Point oxPoint(_x, 0);

	float distance = this->distanceTo(oxPoint);

	return distance;
}

float Point::distancetoOy() {
	Point oyPoint(0, _y);

	float distance = this->distanceTo(oyPoint);

	return distance;
}

void Triangle::input() {
	
	while (!isValidTriangle()) {
		cout << "Input the first point: ";
		_A.input();
		cout << "Input the second point: ";
		_B.input();
		cout << "Input the last point: ";
		_C.input();
	}

	cout << "Input success. Valid triagle!";
}

void Triangle::output() {
	cout << "Three points of the Triagle: ";
	_A.output(); cout << ", "; _B.output(); cout << ", ";  _C.output();
}

bool Triangle::isValidTriangle() {
	if (_A.distanceTo(_B) > _A.distanceTo(_C) + _B.distanceTo(_C))
		return false;
	if (_A.distanceTo(_C) > _A.distanceTo(_B) + _B.distanceTo(_C))
		return false;
	if (_B.distanceTo(_C) > _A.distanceTo(_B) + _A.distanceTo(_C))
		return false;
	if (_A.distanceTo(_B) == 0 || _A.distanceTo(_C) == 0 || _B.distanceTo(_C) == 0)
		return false;

	return true;
}

string Triangle::typeOfTriangle() {
	if (_A.distanceTo(_B) == _A.distanceTo(_C) && _B.distanceTo(_C) == _A.distanceTo(_B))
		return "equilateral triangle";
	if (_A.distanceTo(_B) == _A.distanceTo(_C) || _B.distanceTo(_A) == _B.distanceTo(_C) || _C.distanceTo(_A) == _C.distanceTo(_B))
		return "isosceles triangle";
	if (Calculate::checkEqualSumSquare(_A, _B, _C) || Calculate::checkEqualSumSquare(_B, _A, _C) || Calculate::checkEqualSumSquare(_C, _A, _B))
		return "right-angled triangle";
	return "scalene triangle";
}

float Triangle::perimeter() {
	float AB = _A.distanceTo(_B);
	float AC = _A.distanceTo(_C);
	float BC = _B.distanceTo(_C);

	return AB + AC + BC;
}

float Triangle::area() {
	float p = (this->perimeter()) / 2; // Half perimeter
	float AB = _A.distanceTo(_B);
	float AC = _A.distanceTo(_C);
	float BC = _B.distanceTo(_C);

	float area = sqrt(p * (p - AB) * (p - AC) * (p - BC));
}

Point Triangle::centerG() {
	float centerX = (_A.getX() + _B.getX() + _C.getX()) / 3;
	float centerY = (_A.getY() + _B.getY() + _C.getY()) / 3;
	
	Point G(centerX, centerY);

	return G;
}

bool Calculate::checkEqualSumSquare(Point A, Point B, Point C) {
	if (pow(A.distanceTo(B), 2) + pow(A.distanceTo(C), 2) == pow(B.distanceTo(C), 2))
		return true;
	return false;
}