#include "Quadrilateral.h"
#include <exception>
#include <stdexcept>
#include <iostream>

const map<Quadrilateral::Color, string> Quadrilateral::colorToStringMap = { {Quadrilateral::Color::RED, "Red"},
{Quadrilateral::Color::BLUE, "Blue"},
{Quadrilateral::Color::WHITE, "White"},
{Quadrilateral::Color::BLACK, "Black"},
{Quadrilateral::Color::GREEN, "Green"}
};
Quadrilateral::Quadrilateral(const Point& a = { 0,0 }, const Point& c = { -1,-1 }, const Color& color = Quadrilateral::Color::GREEN)
{
	pts[0].x = a.x;
	pts[0].y = a.y;

	pts[1].x = a.x;
	pts[1].y = c.y;

	pts[2].x = c.x;
	pts[2].y = c.y;

	pts[3].x = c.x;
	pts[3].y = a.y;

	this->color = color;
	isValid();
}

Quadrilateral::Quadrilateral(const Point& a, double width, double height, const Color& color = Color::GREEN)
{
	pts[0].x = a.x;
	pts[0].y = a.y;

	pts[1].x = a.x;
	pts[1].y = a.y + height;

	pts[2].x = a.x + width;
	pts[2].y = pts[1].y;

	pts[3].x = pts[2].x;
	pts[3].y = a.y;

	this->color = color;

	isValid();
}
Quadrilateral::Quadrilateral(const Point& a, const Point& b, const Point& c, const Point& d, const Color& color)
{
	setA(a);
	setB(b);
	setC(c);
	setD(d);

	this->color = color;

	isValid();
}
Quadrilateral::Quadrilateral(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color)
{
	setA(pts[0]);
	setB(pts[1]);
	setC(pts[2]);
	setD(pts[3]);

	this->color = color;

	isValid();
}
Point Quadrilateral::getA() const noexcept
{
	return a;
}

Point Quadrilateral::getB() const noexcept
{
	return b;
}

Point Quadrilateral::getC() const noexcept
{
	return c;
}

Point Quadrilateral::getD() const noexcept
{
	return d;
}

Quadrilateral::Color Quadrilateral::getColor() const noexcept
{
	return color;
}


string Quadrilateral::getColorAsString() const noexcept
{
	return colorToStringMap.at(color);
}

double Quadrilateral::getPerimeter() const noexcept
{
	double perimeter_1 = a.distanceTo(b);
	double perimeter_2 = a.distanceTo(d);
	double perimeter_3 = b.distanceTo(d);
	double perimeter_4 = c.distanceTo(d);
	double perimeter = perimeter_1 + perimeter_2 + perimeter_3 + perimeter_4;
	return perimeter;
}

bool Quadrilateral::isValid() const {

	if ((c.y >= d.y || b.y >= a.y) && (a.x - b.x == 0))
	{
		throw invalid_argument("DORTGEN DEGILDIR!!!");
	}
	else 
	{
		double slope = (a.y - b.y) / (a.x - b.x);
		if (c.x <= ((c.y - a.y) / (slope + a.x)) && d.x <= ((d.y - a.y) / (slope + a.x)))
		{
			throw invalid_argument("DORTGEN DEGILDIR!!!");
		}
	}
	if (((a.x == b.x) && (a.x == c.x)) && ((a.x == b.x) && (a.x == d.x)))
	{
		throw invalid_argument("X BİRBİRİNİN AYNISI");
	}
	else if (((a.x == d.x) && (a.x == c.x)) && ((d.x == b.x) && (b.x == c.x))) {
		throw invalid_argument("X BİRBİRİNİN AYNISI");
	}
	else if (((a.y == b.y) && (a.y == c.y)) && ((a.y == b.y) && (a.y == d.y))) {
		throw invalid_argument("Y BİRBİRİNİN AYNISI");
	}
	else if (((a.y == d.y) && (a.y == c.y)) && ((d.y == b.y) && (b.y == c.y))) {
		throw invalid_argument("Y BİRBİRİNİN AYNISI");
	}
    return true;
}

bool Quadrilateral::setA(const Point& pt)
{
	a.x = pt.x;
	a.y = pt.y;

	isValid();

	return true;
}

bool Quadrilateral::setB(const Point& pt)
{
	b.x = pt.x;
	b.y = pt.y;

	isValid();

	return true;
}

bool Quadrilateral::setC(const Point& pt)
{
	c.x = pt.x;
	c.y = pt.y;

	isValid();

	return true;
}

bool Quadrilateral::setD(const Point& pt)
{
	d.x = pt.x;
	d.y = pt.y;

	isValid();

	return true;
}


void Quadrilateral::printInfo() const noexcept
{

	cout << endl << "Rectangle" << endl << "Number of points: " << NUMBER_OF_CORNERS << endl;
	cout << "Points: " << "( " << a.x << ", " << a.y << " ),( " << b.x << ", " << b.y << " ),( " << c.x << "," << c.y << " ),( " << d.x << "," << d.y << " )" << endl;
	cout << "Priperhal: " << getPerimeter() << endl;
	cout << "Color: " << colorToStringMap.at(color);

}
