# Doxygen Documentation of Convex Hull Algorithms

 The convex hull algorithms described in the documentation are :
1. **Jarvis March - Gift Wrapping Algorithm : O (n.h) time complexity.**  
2. **QuickHull Algorithm : O (n log n) time complexity.**  
3. **Graham Scan Algorithm : O (n log n) time complexity.**  
  
  
  ## Jarvis March Algorithm :  
  Jarvis March algorithm is used to detect the corner points of a convex hull from a given set of data points.

Starting from a leftmost point of the data set, we keep the points in the convex hull by anti-clockwise rotation. From a current point, we can choose the next point by checking the orientations of those points from the current point. When the angle is largest, the point is chosen. After completing all points, when the next point is the start point, stop the algorithm.  
  
The functions used in the algorithm are :  
* ##### `Point_2D(double xi,double yi)` :  
Define a 2D-Point using the given input Coordinates.  
* ##### `vector<Point_2D> Jarvis_March_Convex_Hull(vector<Point_2D> P)` :  
Compute the CLoclwise Sorted Convex Hull for the given set of the 2D-Points.  
* ##### `Point_2D findMinX(vector<Point_2D> Pts) ` :  
Finds the Point in the set which has the least X-coordinate.  
* ##### `Point_2D Next_Point_on_Hull(Point_2D curr, vector<Point_2D> Pts)` :  
Finds and returns the next valid , clockwise sorted point in the final Convex Hull.  
* ##### `double Convex_Hull_Perimeter(vector<Point_2D> Convex_Hull)` :  
Returns the perimeter of the hull created by the convex polygon of all the points in the Convex_Hull.  
* ##### `double getDistance(Point_2D p1, Point_2D p2)` :  
Finds the distance between points p1 and p2.  
* ##### `bool NotEqual(Point_2D p1, Point_2D p2)` :  
Checks if the given 2 points p1 and p2 are equal or not.  
* ##### `double isLeftOf(Point_2D p1, Point_2D p2, Point_2D p3)` :  
Finds the cross-product of the points p1, p2, p3 .i.e. Finds out whether p1, p2, p3 make a left turn, or a right turn, or are collinear.  

The Pseudocode of the algorithm works as follows:  
![JM Algo](Jarvis_March_Pseudocode.png) 




