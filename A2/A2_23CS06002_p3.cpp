#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
    }
};

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    Solution sol;
    int n,e;
    cout << "Enter no. of nodes ";
    cin >> n; 
    cout << "Enter no. of edge ";
    cin >> e;
    vector<vector<int>>edges;
    for(int i=0;i<e;i++){
        vector<int>temp;
        for(int j=0;j<2;j++){
            int a;
            cin >> a ;
            temp.push_back(a);
        }
        edges.push_back(temp);
    }
    sol.findMinHeightTrees(n,edges);
    return 0;
}