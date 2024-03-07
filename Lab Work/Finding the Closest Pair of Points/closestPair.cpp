/*
 * Name: Sam Pupke
 * Date Submitted: 11 March 2024
 * Lab Section: 2
 * Assignment Name: Finding the Closest Pair of Points
 */

/*

Part of this lab also involves figuring out a good choice for the value of b.
Please include in a comment in your code a brief description of why you think your choice of b is a good one
(this will count for 5 of the 10 manual grade points). Submit the file closestPair.cpp with the implemented closestPair() function.

b needs to scale as the amount of points does. If b was just the numPoints, the complexity and time would drastically increase.
Using a square root of numPoints scale allowed for a more efficient value for b than a constant or numPoints.

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
  double x;
  double y;
};

double distanceCalculator(point &p1, point &p2)
{
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

/*Implement the following function
  Reads in a file specified by the parameter
  Format of file: #of points on first line
                  remaining (#of points) lines: x-value and y-value of point
                  one point per line
                  x-value and y-value are double-precision values and
                  bounded by the unit square 0.0 <= x,y < 1.0
  Should use "spatial hashing" where the #of cells scales with the #of points
  and find the distance between the closest pair of points which will be
  returned as a double type value
*/
double closestPair(string filename)
{
  ifstream file(filename);
  if (!file.is_open())
  {
    cerr << "Error opening file: " << filename << endl;
  }

  int numPoints;
  file >> numPoints;

  // Read points from the file
  vector<point> points;
  points.reserve(numPoints);

  for (int i = 0; i < numPoints; i++)
  {
    point p;
    file >> p.x >> p.y;
    points.push_back(p);
  }

  // Find an appropriate value for b (number of divisions along the x-axis and y-axis)
  int b = static_cast<int>(sqrt(numPoints));

  // Initialize the b x b array of cells
  vector<vector<vector<point>>> cells(b, vector<vector<point>>(b));

  // Add each point to the appropriate cell it maps to
  for (point &p : points)
  {
    int cellX = static_cast<int>(p.x * b);
    int cellY = static_cast<int>(p.y * b);
    cells[cellX][cellY].push_back(p);
  }

  // Initialize the minimum distance to the maximum possible value
  double minDistance = numeric_limits<double>::max();

  // Iterate through each cell and its adjacent cells
  for (int i = 0; i < b; i++)
  {
    for (int j = 0; j < b; j++)
    {
      for (int x = max(0, i - 1); x <= min(b - 1, i + 1); x++)
      {
        for (int y = max(0, j - 1); y <= min(b - 1, j + 1); y++)
        {
          // Compare each point in the current cell with points in the adjacent cells
          for (point &p1 : cells[i][j])
          {
            for (point &p2 : cells[x][y])
            {
              if (&p1 != &p2)
              {
                double dist = distanceCalculator(p1, p2);
                minDistance = min(minDistance, dist);
              }
            }
          }
        }
      }
    }
  }

  return minDistance;
}

/*
int main()
{
    double min;
    string filename;
    cout << "File with list of points within unit square: ";
    cin >> filename;
    min = closestPair(filename);
    cout << setprecision(16);
    cout << "Distance between closest pair of points: " << min << endl;
    return 0;
}
*/