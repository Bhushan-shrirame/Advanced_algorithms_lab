#include <bits/stdc++.h>
using namespace std;
const double INF = 1e18;

struct Point {
	double X, Y;
};

struct Circle {
	Point C;
	double R;
};
class Solution{
	public:
    double Euclideandistance(const Point& a, const Point& b){
    	return sqrt(pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2));
    }
    
    bool IsInside(const Circle& c, const Point& p){
    	return Euclideandistance(c.C, p) <= c.R;
    }
    
    Point getCircleCenter(double bx, double by, double cx, double cy) {
    	double B = bx * bx + by * by;
    	double C = cx * cx + cy * cy;
    	double D = bx * cy - by * cx;
    	return { (cy * B - by * C) / (2 * D), (bx * C - cx * B) / (2 * D) };
    }
    
    Circle circle_from_three_points(const Point& A, const Point& B,const Point& C){
    	Point I = getCircleCenter(B.X - A.X, B.Y - A.Y, C.X - A.X, C.Y - A.Y);
    	I.X += A.X;
    	I.Y += A.Y;
    	return { I, Euclideandistance(I, A) };
    }
    
    Circle circle_from_two_points(const Point& A, const Point& B){
    	Point C = { (A.X + B.X) / 2.0, (A.Y + B.Y) / 2.0 };
    	return { C, Euclideandistance(A, B) / 2.0 };
    }
    
    bool validCircle(const Circle& c, const vector<Point>& P){
    	for (const Point& p : P) if (!IsInside(c, p)) return false;
    	return true;
    }

    // main solving function
    Circle minimum_enclosing_circle(const vector<Point>& P){
    
    	int n = (int)P.size();
    	if (n == 0) return { { 0, 0 }, 0 };
    	if (n == 1) return { P[0], 0 };
    
    	Circle mec = { { 0, 0 }, INF };
    
    	for (int i = 0; i < n; i++) {
    		for (int j = i + 1; j < n; j++) {
    			Circle tmp = circle_from_two_points(P[i], P[j]);
    			if (tmp.R < mec.R && validCircle(tmp, P)) mec = tmp;
    		}
    	}
    
    	for (int i = 0; i < n; i++) {
    		for (int j = i + 1; j < n; j++) {
    			for (int k = j + 1; k < n; k++) {
    				Circle tmp = circle_from_three_points(P[i], P[j], P[k]);
    				if (tmp.R < mec.R && validCircle(tmp, P)) mec = tmp;
    			}
    		}
    	}
    	return mec;
    }
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Solution sol;
    int n;
    cout << "Enter number of points: " <<endl;
    cin>>n;
    vector<Point>Points;
    for(int i=0;i<n;i++){
        double a,b;
        cin >> a >>b;
        Points.push_back({a,b});
    }
	Circle result = sol.minimum_enclosing_circle(Points);
	cout << "Center = { " << result.C.X << ", " << result.C.Y << " } Radius = " << result.R << endl;
	return 0;
}
