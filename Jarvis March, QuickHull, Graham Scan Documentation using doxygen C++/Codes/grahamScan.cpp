#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "grahamScan.h"

using namespace std;

Point::Point()=default;

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

int Point::alignment(Point a, Point b, Point c)
{
	double test = (b.x-a.x)*(c.y-b.y)-(c.x-b.x)*(b.y-a.y);
	if(test>0)
		return 1;
	else if(test==0)
		return 0;
	return -1;
}

double Point::squareDistance(Point a, Point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool Point::operator < (Point other)
{
	if (y != other.y)
    	return y < other.y;
    return x < other.x;
}

void printGrahamScan(stack<Point> &s)
{
	cout<<"###########################################:             THE POINTS IN SORTED CLOCKWISE ORDER ON THE CONVEX HULL ARE :                  ############################"<<endl;
	cout<<"###########################################                                                                                             ############################"<<endl;
	cout<<"###########################################                          (USING GRAHAM SCAN ALGORITHM)                                      ############################"<<endl;
	cout<<"####################################################################################################################################################################"<<endl;
	cout<<"\n"<<"\n";
	cout<<setw(30)<<"S.No."<<setw(30)<<"x-coordinate"<<setw(30)<<"y-coordinate"<<endl;
	cout<<"\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\n";
	int i=0;
	while (!s.empty())   {
        Point p = s.top();
        s.pop();

		cout<<setw(30)<<i+1<<"."<<setw(30)<<p.x<<setw(30)<<p.y<<endl;
		i += 1;
	}

}


Point pivot;

bool ccwOrder(Point a, Point b)  
{	
    int order = Point::alignment(pivot, a, b);
    if (order == 0)
        return Point::squareDistance(pivot, a) < Point::squareDistance(pivot, b);
    return (order == 1);
}

stack<Point> grahamScan(vector<Point> &v)
{	
	stack<Point> convexHull;

	int n = v.size();

	if(n>2)
	{
		
		int k=0;
		for(int i=1;i<n;i++)
		{
			if(v[i]<v[k])
				k=i;
		}

		Point temp;
		temp = v[0];
		v[0] = v[k];
		v[k] = temp;

		pivot = v[0];

		//sorting the points with respect to pivot in increasing polar angle.
		sort(v.begin() + 1, v.end(), ccwOrder);

		vector<Point> v1;
		v1.push_back(pivot);

		//remove collinear points with respect to pivot.
		for(int i=1;i<n-1;i++)
		{	
			if((Point::alignment(pivot,v[i],v[i+1]))!=0)
			{
				v1.push_back(v[i]);
			}
		}

		v1.push_back(v[n-1]);
		int n1=v1.size();

		if(n1<3)
		{
			for(int i=0;i<n1;i++)
			{
				convexHull.push(v1[i]);
			}
			return convexHull;
		}

		convexHull.push(v1[0]);
    	convexHull.push(v1[1]);
    	convexHull.push(v1[2]);

    	for (int i = 3; i < n1; i++) {
	        Point top = convexHull.top();
	        convexHull.pop();

	        //while the 3 points at the top of stack are aligned in a clockwise manner, pop the first 2 points.
	        while (Point::alignment(convexHull.top(), top, v1[i]) == -1)   {
	            top = convexHull.top();
	            convexHull.pop();
	        }
        	convexHull.push(top);
        	convexHull.push(v1[i]);
    	}


    	return convexHull;

	}

	for(int i=0;i<n;i++)
	{
		convexHull.push(v[i]);
	}


	return convexHull;	


}