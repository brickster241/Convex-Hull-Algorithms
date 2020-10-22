#include<bits/stdc++.h>
#include "quickhull.h"
#include "JarvisMarch.h"
#include "grahamScan.h"
using namespace std;


int main()
{
	int n; ///> Number of points in the 2D-Plane.	
	cin>>n;
	vector<Point_2D> Points;
	vector<Point> v;
	QuickHull qh;	///> Declaring an object of QuickHull class

	/// Taking N Points as input.
	for (int i = 0; i < n; ++i)
	{
		double Xi;
		double Yi;
		cin >> Xi >> Yi;
		Point_2D p = Point_2D(Xi, Yi);
		Point pt(Xi, Yi);
		Points.push_back(p);
		v.push_back(pt);
		qh.points.insert(make_pair(Xi, Yi));
	}
	
	Jarvis_March ob;	///> Declaring an object of Jarvis_March class.

	vector<Point_2D> Convex_Hull = ob.Jarvis_March_Convex_Hull(Points);	///> Computes the Convex Hull using Jarvis March Algorithm in O(n.h) time.

	stack<Point> convexHull = grahamScan(v);	///> Computes the Convex Hull using Graham Scan Algorithm in O(n.log n) time.

	qh.findConvexHull();	///>  Computes all the points on the Convex Hull using QuickHull algorithm in O(n*n) time.

	double perimeter = ob.Convex_Hull_Perimeter(Convex_Hull); ///> Computes the perimeter of the hull.

	int l=Convex_Hull.size();
	/// Represnting the Output on the Terminal Console.
	cout<<"################################################: THE CONVEX HULL POINTS AND LINES IN CLOCKWISE SORTED ORDER ARE : #################################################"<<endl;
	cout<<"################################################                 (EXCLUDING COLLINEAR POINTS)                      #################################################"<<endl;
	cout<<"################################################                (USING JARVIS MARCH ALGORITHM)                     #################################################"<<endl;
	cout<<"####################################################################################################################################################################"<<endl;
	cout<<"\n"<<"\n";
	cout<<setw(30)<<"Line No."<<setw(35)<<"1st Point"<<setw(35)<<"2nd Point"<<setw(45)<<"Line Distance(Units)."<<endl;
	cout<<"\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\n";

	for (int i = 0; i < l; ++i)	///> Printing Points in Sorted Clockwise Order calculated using Jarvis March algorithm .( Excluding Collinear Points. )
	{
		double x1 = Convex_Hull[i].x;
		double y1 = Convex_Hull[i].y;
		double x2 = Convex_Hull[(i+1)%l].x;
		double y2 = Convex_Hull[(i+1)%l].y;
		cout<<right<<setw(30)<<i+1<<"."<<setw(30)<<"("<<x1<<","<<y1<<")"<<setw(30)<<"("<<x2<<","<<y2<<")"<<setw(30)<<setprecision(6)<<ob.getDistance(Point_2D(x1, y1), Point_2D(x2, y2))<<endl;
	}
	cout<<"\n";
	cout<<"PERIMETER OF THE CONVEX HULL : "<<setprecision(6)<<perimeter<<"\n"<<endl;
	cout<<"-----------------------------------------------------------------------------------X---------------------------------------------------------------------------------"<<endl;
	cout<<"\n"<<"\n"<<endl;
	cout<<"################################################:             THE POINTS ON THE CONVEX HULL ARE :                  #################################################"<<endl;
	cout<<"################################################                (INCLUDING COLLINEAR POINTS)                       #################################################"<<endl;
	cout<<"################################################                (USING QUICKHULL ALGORITHM)                        #################################################"<<endl;
	cout<<"####################################################################################################################################################################"<<endl;
	cout<<"\n"<<"\n";
	
	qh.printConvexHull();	///> prints all the points in the Convex Hull obtained by QuickHull algorithm.
	
	cout<<"\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\n";
	printGrahamScan(convexHull); ///> Printing Points in Sorted Clockwise Order calculated using Graham Scan algorithm .
	cout<<"\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\n";
	return 0;
}

