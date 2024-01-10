#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int>> markboundary(vector<vector<int>>& rectangle ){
        int rsize = rectangle.size();
        int arrsize = INT_MIN;
        for(int i=0;i<rsize;i++){
            for(int j=0;j<2;j++){
                if(arrsize < rectangle[i][j]) arrsize = rectangle[i][j];
            }
        }
        arrsize++;
        arrsize++;
        cout << arrsize <<endl;
        vector<int> bar(arrsize, 0);
        // vector<int> bar(100, 0);
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
       bool flag = false;
        // Adding the points
        for(int i =1;i<bar.size();i++){
            if(bar[i-1] > bar[i]){
                if(bar[i] == 0 && flag){
                    ans.push_back({i-1 ,bar[i]});
                    flag = false;
                }
                else {
                    ans.push_back({i-1,bar[i]});
                    flag = false;
                }

            }
            else if(bar[i-1] < bar[i]){
                ans.push_back({i,bar[i]});
                flag = true;
            }
        }
        ans.push_back({0,0});  

        for(int i=0;i<ans.size()-1;i++){
            cout << "< " << ans[i][0] << "," << ans[i][1] << " > ";
            cout<<endl;  
        }
        return ans;

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