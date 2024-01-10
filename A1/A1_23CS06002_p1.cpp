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

double dist(const Point& a, const Point& b){
	return sqrt(pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2));
}

bool is_inside(const Circle& c, const Point& p){
	return dist(c.C, p) <= c.R;
}

Point get_circle_center(double bx, double by, double cx, double cy) {
	double B = bx * bx + by * by;
	double C = cx * cx + cy * cy;
	double D = bx * cy - by * cx;
	return { (cy * B - by * C) / (2 * D), (bx * C - cx * B) / (2 * D) };
}

Circle circle_from(const Point& A, const Point& B,const Point& C){
	Point I = get_circle_center(B.X - A.X, B.Y - A.Y, C.X - A.X, C.Y - A.Y);
	I.X += A.X;
	I.Y += A.Y;
	return { I, dist(I, A) };
}

Circle circle_from(const Point& A, const Point& B){
	Point C = { (A.X + B.X) / 2.0, (A.Y + B.Y) / 2.0 };
	return { C, dist(A, B) / 2.0 };
}

bool is_valid_circle(const Circle& c, const vector<Point>& P){
	for (const Point& p : P) if (!is_inside(c, p)) return false;
	return true;
}

Circle minimum_enclosing_circle(const vector<Point>& P){

	int n = (int)P.size();
	if (n == 0) return { { 0, 0 }, 0 };
	if (n == 1) return { P[0], 0 };

	Circle mec = { { 0, 0 }, INF };

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			Circle tmp = circle_from(P[i], P[j]);
			if (tmp.R < mec.R && is_valid_circle(tmp, P)) mec = tmp;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				Circle tmp = circle_from(P[i], P[j], P[k]);
				if (tmp.R < mec.R && is_valid_circle(tmp, P)) mec = tmp;
			}
		}
	}
	return mec;
}


int main()
{
    int n;
    cout << "Enter number of points: " <<endl;
    cin>>n;
    vector<Point>P;
    for(int i=0;i<n;i++){
        double a,b;
        cin >> a >>b;
        P.push_back({a,b});
    }
	Circle mec = minimum_enclosing_circle(P);

	cout << "Center = { " << mec.C.X << ", " << mec.C.Y << " } Radius = " << mec.R << endl;

	Circle mec2 = minimum_enclosing_circle({ { 5, -2 },{ -3, -2 }, { -2, 5 },{ 1, 6 },{ 0, 2 } });

	cout << "Center = { " << mec2.C.X << ", " << mec2.C.Y<< " } Radius = " << mec2.R << endl;

	return 0;
}
