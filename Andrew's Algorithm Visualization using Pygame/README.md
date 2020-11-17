# Andrew’s Convex Hull:
Andrew’s monotone chain algorithm constructs the convex hull in O (n * log(n)) time. We have to sort the points first and then calculate the upper and lower hulls in O(n) time. The points will be sorted with respect to x-coordinates (with respect to y-coordinates in case of a tie in x-coordinates), we will then find the left most point and then try to rotate in clockwise direction and find the next point and then repeat the step until we reach the rightmost point and then again rotate in the the clockwise direction and find the lower hull. 
The functions used in the algorithm are:
1.	### ` Calculate_Hull (Convexhull, lines, screen, points, green, start, end, step) `

•	ConvexHull is the final hull which contains all the points present in the final hull. It contains all the points.The function is called twice, once for Upper Hull and once for Lower Hull.
 
2.	### ` Cross_Product (last, middle, first) ` 

•	This function takes input 3 points, and determines the direction/ turn that these points make. If cross product is > 0, it is a left turn, if < 0, right turn else collinear.  

3.	### ` create_canvas (lines, screen, points) `

•	Creates a screen with 2d - grid points and lines for each step, when we start the algorithm or whenever a line has to be deleted.


