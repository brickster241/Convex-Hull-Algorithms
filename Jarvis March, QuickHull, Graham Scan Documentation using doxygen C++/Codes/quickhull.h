#ifndef _GRAHAMSCAN_H_
#define _GRAHAMSCAN_H_

#include<bits/stdc++.h>
using namespace std;

/**
vertex is used to represent a point in 2d space
*/
#define vertex pair<double,double>
/**
Class used to compute and store the convex hull of a set of points using quickhull algorithm
*/
class QuickHull
{
	public:
	set<vertex> points;///points: used to store the set of points 


	
	void printConvexHull();
	
	void printPoints();

	
	void findConvexHull();
		
	
	
	set<vertex> convex_hull;///convex_hull: used to store the points in convex hull	
	
	double findDistance(vertex p,vertex x,vertex y);
	
	int findSide(vertex p,vertex x,vertex y);
	
	void quickhull(vertex x,vertex y,int side);
};

#endif // GRAHAMSCAN_H



