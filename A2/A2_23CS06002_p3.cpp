#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution sol;
    int n,e;
    cout << "Enter no. of nodes ";
    cin >> n; 
    cout << "Enter no. of edge ";
    cin >> e;
    vector<vector<int>>edges;
    for(int i=0;i<e;i++){
        int a , b;
        cin >> a ,b;
        edges.push_back({a,b});
    }
    for(int i=0;i<e;i++){
        cout << edges[i][0] << " " << edges[i][1] << endl;
    }
    return 0;
}