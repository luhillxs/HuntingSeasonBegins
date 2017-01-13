#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>  
#include <vector>
using namespace std;

struct Point { 
    double x;
    double y; 
    Point(double a, double b) {
        x = a;
        y = b;
    }
};

double getDistance(Point a, Point b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

//typedef bool (*comp)(Point, Point); // 函数指针 
bool compare(Point a, Point b)
{
  // new point is 'a', if a distance < b distance, return TRUE, keep iterating
  // until FALSE
  // top element is the GREATEST
  Point global_origin = Point(0,0);
  return getDistance(a, global_origin) < getDistance(b, global_origin);
}

class Compare
{
public:
    bool operator() (Point a, Point b)
    {
        Point global_origin = Point(0,0);
        return getDistance(a, global_origin) < getDistance(b, global_origin);
    }
};

vector<Point> Solution(vector<Point> &array, Point origin, int k) {
    global_origin = Point(origin.x, origin.y);
    priority_queue<Point, std::vector<Point>, bool (*)(Point, Point)> pq(compare);
    // priority_queue<Point, std::vector<Point>, Compare> pq;
    vector<Point> ret;
    for (int i = 0; i < array.size(); i++) {
        pq.push(array[i]);
        while(pq.size() > k)
            pq.pop();
    }
    
    while (!pq.empty()){
        ret.push_back(pq.top());
        pq.pop();
    }
    return ret;
}



int main()
{
   Point p1 = Point(4.5, 6.0);
   Point p2 = Point(4.0, 7.0);
   Point p3 = Point(4.0, 4.0);
   Point p4 = Point(2.0, 5.0);
   Point p5 = Point(1.0, 1.0);
   Point p6 = Point(3.0, 0.0);
   Point p7 = Point(0.0, 4.0);
   vector<Point> array;
   array.push_back(p1);
   array.push_back(p2);
   array.push_back(p3);
   array.push_back(p4);
   array.push_back(p5);
   int k = 2;
   Point origin = Point(0.0, 0.0);
   vector<Point> ans = Solution(array, origin, k);
   for (int i = 0; i < ans.size(); i++) {
       cout << i << ": " << ans[i].x << "," << ans[i].y << endl;
   }
   
   cout << getDistance(p6, p7) << endl;
}
