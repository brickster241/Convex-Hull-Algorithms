#include<bits/stdc++.h>
using namespace std;

#include "quickhull.h"

/**
findDistance is used to use the y=slope*x+c equation of line xy and find distance of point p by substituting it in the equation
@param p,x,y endpoints of aline segment
@returns value proportional to distance of p from xy
*/
double QuickHull::findDistance(vertex p,vertex x,vertex y)
{
	return abs ((p.second - x.second) * (y.first - x.first) - (y.second - x.second) * (p.first - x.first)); 
	
	
} 
/**
findSide is used to find the side of a point p with respect to a line segment xy by calculating the determinant of p,x,y
@param p,x,y endpoints of line segment
@returns 1 or -1 depending on side of xy to which p lies
*/


int QuickHull::findSide(vertex p,vertex x,vertex y)
{
	
	
	double val=(x.first*y.second-x.second*y.first)-p.first*(y.second-x.second)+p.second*(y.first-x.first);
	if(val<0)
		return -1;
	if(val>0)
		return 1;
	return 0;
	
}

/**
quickhull is a recursive function used to find the points of the convex hull
@param x,y endpoints of line segment side: the side of xy that we want to find points in
@param side Cross product value - side of xy
*/
void QuickHull::quickhull(vertex x,vertex y,int side)
{
	
	vertex p;
	p=x;
	
	double max_dist=0;
	
	set<vertex>::iterator it;
	
	for (it = points.begin(); it != points.end(); it++) 
	{

		if(findSide((*it),x,y)==side)	///for each point check if it lies on the required side of the line xy
		{

			double dist=findDistance((*it),x,y);///if it does, then find distance of point from xy 
			if(dist>max_dist)
			{
			//if that distance is maximum, make p as that point
				max_dist=dist;
				p.first=(*it).first;
				p.second=(*it).second;
				
			}
		}
		
	}
	

	if(p.first==x.first && p.second==x.second)///if no such point p with max distance exists, add endpoints x and y to Convex Hull
	{
		convex_hull.insert(x);
		convex_hull.insert(y);
		return;
	}

	
	quickhull(p,x,-findSide(p,x,y));///else, recursively find points on the other side of px and py
	quickhull(p,y,-findSide(p,y,x));
	
	
	

}
/**
function to first call quickhull() 
*/
void QuickHull::findConvexHull()
{


	vertex max_x,min_x;
	set<vertex>::iterator it; 
	it=points.begin();
	max_x=(*it);
	min_x=(*it);
	///find max_x and min_x by iterating through all points
	for (it = points.begin(); it != points.end(); it++) 
	{
		if(max_x.first>(*it).first)
			max_x=(*it);
		if(min_x.first<(*it).first)
			min_x=(*it);
	}
        //cout << max_x.first<<" "<<min_x.first; 
        
        quickhull(min_x,max_x,1);
        quickhull(min_x,max_x,-1);
        
        
        
}
/**
function to print the points of convex hull

*/
void QuickHull::printConvexHull()
{
	
	set<vertex>::iterator it; 
	int i = 0;
	cout<<setw(30)<<"S.No."<<setw(30)<<"x-coordinate"<<setw(30)<<"y-coordinate"<<endl;
	cout<<"\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\n";
	for (it = convex_hull.begin(); it != convex_hull.end(); it++) 
	{
        cout<<setw(30)<<i+1<<"."<<setw(30)<<(*it).first<<setw(30)<<(*it).second<<endl;
        i += 1;
	}

    cout<<"\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\n";
	
}
/**
function to print the set of points
*/

void QuickHull::printPoints()
{
	set<vertex>::iterator it; 
	for (it = points.begin(); it != points.end(); it++) 
        cout<<(*it).first<<" "<<(*it).second<<endl;
        
}
