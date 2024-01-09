#include <bits/stdc++.h>
using namespace std;

double radius = 0;


class Solution{
    public:

};

int main(){
    Solution sol;
    vector<vector<int>> rectangle;
    int n,m =2;
    cout << "Enter number of points; ";
    cin >>n;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<m;j++){
            int a;
            cin>>a;
            temp.push_back(a);
        }
        rectangle.push_back(temp);
    }

    return 0;
}