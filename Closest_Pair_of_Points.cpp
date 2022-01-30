#include <bits/stdc++.h>
using namespace std;

// A structure to represent a Point in 2D plane
class Point
{
	public:
	int x, y, idx;
};

// Needed to sort array of points according to X coordinate
int compareX(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->x - p2->x);
}

// Needed to sort array of points according to Y coordinate
int compareY(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->y - p2->y);
}


// Find distance between two points
float dist(Point p1, Point p2)
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +(p1.y - p2.y)*(p1.y - p2.y));
}

// Find the smallest distance between two points by brute force
float bruteForce(Point P[], int n, int &i1, int &i2)
{
	float min = FLT_MAX;
	for (int i = 0; i < n; ++i)
	{
	    for (int j = i+1; j < n; ++j)
		{
		    if (dist(P[i], P[j]) < min)
			{
			    min = dist(P[i], P[j]);
			    i1 = P[i].idx;
			    i2 = P[j].idx;
			}
		}
	}
	return min;
}


// Find the distance between the closest points of strip[]
float stripClosest(Point strip[], int size, float d, int &i1, int &i2)
{
	float min = d; 
	qsort(strip, size, sizeof(Point), compareY);

	// Inner loop runs at most 6 times
	for (int i = 0; i < size; ++i)
	{
	    for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
		{
		    if (dist(strip[i],strip[j]) < min)
			{
			    min = dist(strip[i], strip[j]);
			    i1 = strip[i].idx;
			    i2 = strip[j].idx;
			}
		}
	}

	return min;
}


// Find the smallest distance using divide and conquer technique. 
float closestUtil(Point P[], int n, int &i1, int &i2)
{
	// If there are 2 or 3 points, then use brute force
	if (n <= 3)
		return bruteForce(P, n, i1, i2);

	int mid = n/2;
	Point midPoint = P[mid];

    int i11, i12, i21, i22;
	float dl = closestUtil(P, mid, i11, i12);
	float dr = closestUtil(P + mid, n - mid, i21, i22);
	float d;
	if(dl < dr)
	{
	    d = dl;
	    i1 = i11; i2 = i12;
	}
	else
	{
	    d = dr;
	    i1 = i21; i2 = i22;
	}

    // Create a strip of width 2d
	Point strip[n];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (abs(P[i].x - midPoint.x) < d)
			strip[j] = P[i], j++;
			
	return stripClosest(strip, j, d, i1, i2);
}


float closest(Point P[], int n, int &i1, int &i2)
{
	qsort(P, n, sizeof(Point), compareX);
	return closestUtil(P, n, i1, i2);
}


int main()
{
	Point P[] = {{2, 3, 1}, {12, 30, 2}, {40, 50, 3}, {5, 1, 4}, {12, 10, 5}, {3, 4, 6}};
	int n = sizeof(P) / sizeof(P[0]);
	int i1, i2;
	cout << "The smallest distance is " << closest(P, n, i1, i2) << endl;
	cout << i1 << " " << i2 << endl;
	return 0;
}
