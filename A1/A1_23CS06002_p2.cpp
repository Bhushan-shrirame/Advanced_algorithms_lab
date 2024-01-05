#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int>> markboundary(vector<vector<int>>& rectangle ){
        vector<int> bar(25, 0);
        for(int i=0;i<rectangle.size();i++){
            for(int j=0;j<2;j++){
                bar[rectangle[i][j]] = rectangle[i][2];
            }
        }
        for(int i=0;i<bar.size();i++){
            cout << bar[i] << " ";
        }

        return rectangle;

    }
};

int main(){
    Solution sol;
    vector<vector<int>> rectangle;
    int n , m =3;
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
    sol.markboundary(rectangle);
    return 0;
}