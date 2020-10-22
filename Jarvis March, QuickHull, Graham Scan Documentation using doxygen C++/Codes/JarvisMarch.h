#ifndef _JARVISMARCH_H_
#define _JARVISMARCH_H_


using namespace std;

/**
* Implementation of a Point Class to store 2D-Coordinate Points.
*/
class Point_2D
{
public:
	double x; ///< X-coordinate of the 2D-Point.
	double y; ///< Y-coordinate of the 2D-Point.

	/**
	* Define a 2D-Point using the given input Coordinates.
	*
	* @param xi,yi - The values of the coordinates (Xi,Yi) .
	* @returns - A point object P with x,y coordinates which can be accessed by 
	*	P.x and P.y
	*/
	Point_2D(double xi,double yi);
};

/**
* Contains methods which Computes the Convex Hull of n 2D points using Jarvis March algorithm in O(N.H) time.
*
* The Convex hull for a set of 2D-points is defined as the smallest convex polygon, that 
* encloses all of the points in the set. Convex means that the polygon has no corner 
* that is bent inwards. 
*
* In the description,
* N - No. of 2D-points in the set.
* H - No. of output points in the final Convex Hull.
*
* Hence, this algorithm is an Output-Sensitive Algorithm as it depends on H. The worst case
* Time Complexity will be O(n^2) . 
*
* The Convex Hull formed by the functions of this class will be in an CLockwise Sorted order.
* The class contains 7 functions/methods for each step of the Algorithm.
*/
class Jarvis_March
{
public:

	/**
	* Compute the CLoclwise Sorted Convex Hull for the given set of the 2D-Points.
	*
	* @param P - A vector/list of type 'Point' which contains all the points in the set.
	* @returns  A vector/list of type 'Point' which has all the points on the Convex Hull in O(N.H) time.
	*	It neglects the points which are collinear. 
	*/
	vector<Point_2D> Jarvis_March_Convex_Hull(vector<Point_2D> P);

	/**
	* Finds the Point in the set which has the least X-coordinate.
	*
	* Why do we need this function ? - 
	* For starting the algorithm at some point, we need to have atleast One Point which belongs to final Convex Hull Set beforehand.
	* As the leftmost point in the set of points is an extreme point, it will always be in the final Sorted Covex Hull.
	*
	* @param Pts -List of points given in the 2D-Plane.
	* @returns a value with the type 'Point' which has the least value of its x-coordinate.
	*/
	Point_2D findMinX(vector<Point_2D> Pts);

	/**
	* Finds and returns the next valid , clockwise sorted point in the final Convex Hull.
	*
	* @param curr - The latest valid point in the final Convex Hull vector. 
	* @param Pts - List of all the points given in the 2D-plane.
	* @returns - the next valid point after curr, which will be appended in the final Convex Hull.
	*
	* This function first assumes that the next valid point is the first non-equal point in Pts.
	* Then it iterates through all the points, updates the value of next_point iff the point is on the left side
	* of the line formed by curr and next_point(old). It also updates when the 3 points are collinear and the distance
	* between (curr,next_point) is less than that of (curr, iterator_point), update the value of next_point to exclude any collinear points in the final Hull. 
	*/
	Point_2D Next_Point_on_Hull(Point_2D curr, vector<Point_2D> Pts);

	/**
	* Returns the perimeter of the hull created by the convex polygon of all the points in the Convex_Hull.
	*
	* @param Convex_Hull - The final set of points in the hull in Sorted Clockwise Order.
	* @returns - a double value ,i.e. the perimeter of the Convex Hull.
	*/
	double Convex_Hull_Perimeter(vector<Point_2D> Convex_Hull);

	/**
	* Finds the distance between points p1 and p2. 
	*
	* @param p1 - The first point. 
	* @param p2 - The second point.
	* 
	* This is an important function as it handles 2 things.
	* 1. It handles all the collinear cases. If the points are collinear, It calculates the distance between the last 2 points w.r.t. the first.
	* 2. It is used to calculate the perimeter of the Hull as well.
	*/
	double getDistance(Point_2D p1, Point_2D p2);

	/**
	* Checks if the given 2 points p1 and p2 are equal or not.
	* 
	* @param p1,p2 - Points which need to be compared.
	* @returns - A boolean value which is True when both points are not equal , else False.
	*
	* This function is used in determining the next valid point on hull. While iterating through all
	* all the points in the set , we need to exclude 2 points ,i.e. curr and next_point (see Next_Point_in_Hull for reference) to get the correct valid point.
	*/
	bool NotEqual(Point_2D p1, Point_2D p2);

	/**
	* Finds the cross-product of the points p1, p2, p3 .i.e. Finds out whether p1, p2, p3 make a left turn, or a right turn, or are collinear.
	*
	* @param p1 - base point. Cross product is done with respect to this point as origin.
	* @param p2,p3 - points which form lines with p1.
	*
	* This forms the base of the algorithm which helps in finding out the valid points on the hull. If isLeftOf(p1,p2,p3) > 0, then p1,p2,p3 make a left turn.
	* Which implies that an update in the value of valid point is necessary. If its value is 0, then they are collinear and getDistance() is called.
	* Else no changes are made in the value of next_point (See Next_Point_On_Hull for reference).
	*/
	double isLeftOf(Point_2D p1, Point_2D p2, Point_2D p3);

};

#endif // _JARVISMARCH_H_
