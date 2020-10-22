#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>

#include "JarvisMarch.h"

using namespace std;

Point_2D::Point_2D(double xi,double yi)
{
	this->x=xi;	///< assigning the X-coordinate xi to paramter x of the class object.
	this->y=yi; ///< assigning the Y-coordinate yi to paramter y of the class object.
}


vector<Point_2D> Jarvis_March::Jarvis_March_Convex_Hull(vector<Point_2D> P)
{
	vector<Point_2D> Hull;	///< Initialize the final Sorted Convex Hull.
	
	Point_2D M = findMinX(P);  ///< Find the Point with the minimum x-coordinate and append it to Hull.	
	Hull.push_back(M);
	
	Point_2D next_point = Next_Point_on_Hull(M,P);  
	while(NotEqual(next_point, M))    ///< Keep Finding the next valid point and appending it to the Hull until we reach the first point.
	{
		Hull.push_back(next_point);
		next_point = Next_Point_on_Hull(Hull.back(),P); 
	}

	return Hull;
}

double Jarvis_March::Convex_Hull_Perimeter(vector<Point_2D> P)
{
	int l = P.size();
	double sum = 0.00;	///> Initialize the perimeter to be 0.
	for(int i=0;i<l;i++)
	{
		sum += getDistance(P[i],P[(i+1)%l]);	///> Add the values of all the distances of subsequent points.
	}
	return sum;
}


double Jarvis_March::getDistance(Point_2D p1, Point_2D p2)
{
	
	double a = p1.x - p2.x;
	double b = p1.y - p2.y;
	return sqrt(a*a + b*b) / 1.0;   

}

bool Jarvis_March::NotEqual(Point_2D p1, Point_2D p2)
{
	if(p1.x == p2.x and p1.y == p2.y)        ///> If points are equal, Both x and y coordinates should be equal.
	{
		return false;
	}
	return true;
}
	
Point_2D Jarvis_March::findMinX(vector<Point_2D> Pts)
{
	Point_2D M = Pts[0];        ///> Initializing the Minimum Point
	for(int j=1;j<Pts.size();j++)
	{
		if(M.x > Pts[j].x)			///> Updating the value accordingly.
		{
			M = Pts[j];
		}
	}
	return M;
}

double Jarvis_March::isLeftOf(Point_2D p1, Point_2D p2, Point_2D p3)
{
	double x1 = p2.x - p1.x;
	double y1 = p2.y - p1.y;
	double x2 = p3.x - p1.x;
	double y2 = p3.y - p1.y;
	/// Finding the relative values of x1,x2,y1,y2 w.r.t all 3 points.
	return x1*y2 - x2*y1;
}

Point_2D Jarvis_March::Next_Point_on_Hull(Point_2D curr, vector<Point_2D> Pts)
{
	/// Initializing the next_valid_point to first Non-equal Point.
	Point_2D next_point = Pts[0];  
	if(!NotEqual(next_point, curr))
	{
		next_point = Pts[1];
	}
	for (int i = 0; i < Pts.size(); ++i)
	{
		if(!NotEqual(Pts[i],curr) or !NotEqual(Pts[i],next_point))
		{
			continue;
		}
		double leftmost = isLeftOf(curr, next_point, Pts[i]);  ///> Cross-Product of the 3 Points.
		if(leftmost > 0)	///> Left turn so update required.
		{
			next_point = Pts[i];
		}
		else if(leftmost == 0 and getDistance(curr,next_point) < getDistance(curr, Pts[i])) ///> Points are collinear so find the point with larger distance.
		{
			next_point = Pts[i];
		}
	}
	return next_point;
}




