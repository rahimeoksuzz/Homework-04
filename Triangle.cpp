#include <array>
#include <vector>
#include <map>
#include <stdexcept>
#include "Point.h"
#include "Triangle.h"
#include <iostream>
using namespace std;

const map<Triangle::Color, string> Triangle::colorToStringMap = { {Triangle::Color::RED, "Red"},
{Triangle::Color::BLUE, "Blue"},
{Triangle::Color::WHITE, "White"},
{Triangle::Color::BLACK, "Black"},
{Triangle::Color::GREEN, "Green"},
{Triangle::Color::PINK, "Pink"}
};

Triangle::Triangle(const Point& a = { 1, 0 }, const Point& b = { 0, 1 }, const Point& c = { 2, 1 }, const Color & color = Color::RED)
{
	pts[0].x = a.x;
	pts[0].y = a.y;

	pts[1].x = a.x;
	pts[1].y = c.y;

	pts[2].x = c.x;
	pts[2].y = c.y;

	this->color = color;

	isValid();
}

Triangle::Triangle(const vector<Point>& pts, const Color& color)
{
	pts[0].x = a.x;
	pts[0].y = a.y;
	
	pts[1].x = a.x;
	pts[1].y = c.y;

	pts[2].x = c.x;
	pts[2].y = c.y;
	
	this->color = color;

	isValid();
	}


Triangle::Triangle(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color)
{
	pts[0].x = a.x;
	pts[0].y = a.y;

	pts[1].x = a.x;
	pts[1].y = c.y;

	pts[2].x = c.x;
	pts[2].y = c.y;

	this->color = color;

	isValid();
}

Point Triangle::getA() const noexcept
{
	return a;
}

Point Triangle::getB() const noexcept
{
	return b;
}

Point Triangle::getC() const noexcept
{
	return c;
}

Triangle::Color Triangle::getColor() const noexcept
{
	return color;
}
string Triangle::getColorAsString() const noexcept{
	return colorToStringMap.at(color);
}

double Triangle::getPerimeter() const noexcept
{
	double perimeter_1 = a.distanceTo(b);
	double perimeter_2 = a.distanceTo(c);
	double perimeter_3 = b.distanceTo(c);
	double perimeter = perimeter_1 + perimeter_2 + perimeter_3;
	return perimeter;
}
//set fonksiyonları tekrar kontrol edilicek
bool Triangle::setA(const Point & pt){
	a.x = pt.x;
	a.y = pt.y;
	return true;
}

bool Triangle::setB(const Point & pt){
	b.x = pt.x;
	b.y = pt.y;
	return true;
}

bool Triangle::setC(const Point & pt){
	c.x = pt.x;
	c.y = pt.y;
	return true;
}
bool Triangle::isValid() const
{
	double x = a.distanceTo(b);
	double y = a.distanceTo(c);
	double z = b.distanceTo(c);

	if ( (x > y+z && x < abs(y-z)) || (y > x+z || y < abs(x-z)) || (z > x+y || z < abs(x-y)))
	{
		throw invalid_argument("UCGEN DEGILDIR!!!");
	}

	if ((a.x == b.x && a.y == b.y) || (a.x == c.x && a.y == c.y) || (b.x == c.x && b.y == c.y))
	{
		throw invalid_argument("UCGEN DEGILDIR!!!");
	}
	return true;
}
double Triangle::printInfo() const noexcept
{

	cout << endl << "Triangle" << endl << "Number of points: " << NUMBER_OF_CORNERS << endl;
	cout << "Points: " << "( " << a.x << ", " << a.y << " ),( " << b.x << ", " << b.y << " ),( " << c.x << "," << c.y  << endl;
	cout << "Priperhal: " << getPerimeter() << endl;
	cout << "Color: " << getColorAsString() << endl;
}
