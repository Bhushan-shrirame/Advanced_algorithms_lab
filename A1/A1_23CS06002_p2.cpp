#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int>> markboundary(vector<vector<int>>& rectangle ){
        int rsize = rectangle.size();
        vector<int> bar(25, 0);
        vector<vector<int>>ans;

        // To create the array with points
        for(int i=0;i<rsize;i++){
            for(int j=0;j<2;j++){
                bar[rectangle[i][j]] = rectangle[i][2];
            }
        }

        // To give all the maximum height they can achive
        for(int i =0 ;i<rsize;i++){
            for(int j=rectangle[i][0];j<=rectangle[i][1];j++){
                if(bar[j] < rectangle[i][2]) bar[j] = rectangle[i][2];
            }
        }

        // Adding the points
        for(int i =1;i<bar.size();i++){
            if(bar[i-1] < bar[i]){
                ans.push_back({i ,bar[i]});
            }
            else if(bar[i] == 0){
                ans.push_back({i-1,bar[i-1]});
            }
            else{
                ans.push_back({i-1,bar[i]});
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