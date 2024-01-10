#include <bits/stdc++.h>
using namespace std;
const double INF = 1e18;


class Solution{
    double radius = 0;
    double distance =0;
    public:
    double dis(pair<double,double>p1,pair<double,double>p2){
        return sqrt(pow(p1.first-p2.second ,2) + pow(p1.second-p2.second,2));
    }

    pair<double,double>circle_from(pair<double,double>p1,pair<double,double>p2){
        pair<double,double>c;
        c = { (p1.first + p2.second) /2 ,(p1.second + p2.second)/2};
        distance = dis(p1,p2);
        return c;

    }


    pair<double,double> minimumcircle(vector<pair<double,double>>&points){
        pair<double ,double> center;
        double n= points.size();
        if(n==0)return {0,0};
        if(n==1) return{points[0].first , points[0].second};

        for(double i=0;i<n;i++){
            for(double j=i+1;j<n;j++){
                pair<double,double> temp;
                temp = circle_from(points[i],points[j]);
            }
        }



        return center;
    }
};

double main(){
    Solution sol;
    vector<pair<double,double >> points;
    double n;
    cout << "Enter number of podoubles; ";
    cin >>n;
    pair<double,double> temp;
    for(double i=0;i<2;i++){
        double a,b;
        cin >> a >>b;
        temp.first = a;
        temp.second =b;
        points.push_back(temp);
    }
    temp = sol.minimumcircle(points);
    cout << "Center is " << "{" << temp.first << "," << temp.second <<"}"<< endl;
    return 0;
}