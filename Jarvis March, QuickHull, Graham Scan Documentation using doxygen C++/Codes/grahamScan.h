#ifndef _GRAHAMSCAN_H_
#define _GRAHAMSCAN_H_

#include<stack>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

/**
 *Used to store the coordinates of points in 2D space.It includes methods
 *for finding alignment of points, the square distance between them, and an overloaded operator
 *to compare two points.
 *It has two attributes: x-coordinate, y-coordinate
 */
class Point
{
public:
	double x,y;
	/**
	 *Default constructor.
	 */
	Point();

	/**
	 *Overloaded constructor.
	 *@param x :x-coordinate, Type: double
	 *@param y :y-coordinate, Type: double
	 */
	Point(double x, double y);

	/**
	 *Used to test the alignment of three points a,b,c.
	 *@param a :first point, Type: Point
	 *@param b :second point, Type: Point
	 *@param c :third point, Type: Point
	 *@returns -1 if bc makes a clockwise turn with respect to ab, 1 if bc makes an anticlockwise turn w.r.t. ab, 0 if the points are collinear.
	 */
	static int alignment(Point a, Point b, Point c);

	/**
	 *Used to find the square of the distance between two points.
	 *@param a :first point, Type Point
	 *@param b :second point, Type Point
	 *@returns The square of the distance between a and b.
	 */
	static double squareDistance(Point a, Point b);

	/**
	 *An overloaded < operator for comparing the ordering of two points.
	 *@param other :RHS of the comparison operator, Type Point
	 *@returns a boolean, true if y-coordinate of LHS is less than that of RHS(tie broken using x-coordinate, true if x-coordinate of LHS is less than that of RHS).
	 */
	bool operator < (Point other);
};

/**
 *Calculates the convex hull of a list of points in 2D. Takes in a list of points
 *and returns a stack of points in the convex hull in clockwise order from the top.
 *@param v :A vector of Point objects ;passed by reference, Type: std::vector<Point>
 *@returns The convex hull as a stack of Point objects containing the points in clockwise order from the top, Type: std::stack<Point>
 */
std::stack<Point> grahamScan(std::vector<Point> &v);

/**
 *Utility function to display the convex hull.
 *@param s :A stack of Point objects containing points of the convex hull ;passed by reference, Type: std::stack<Point>
 *@returns No return value, prints to stdout
 */
void printGrahamScan(std::stack<Point> &s);
#endif
