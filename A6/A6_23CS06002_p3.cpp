#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int  Minimum_Concrete_for_Staircase_Reduction(int k,int m,vector<vector<int>>&steps){
        int res =0;
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    Solution st;
    int k,m;
    cin >> k >> m;
    vector<vector<int>>steps;
    for(int i=0;i<k;i++){
        int l ,h;
        cin >> l >> h;
        steps.push_back({l,h});
    }
    cout << st.Minimum_Concrete_for_Staircase_Reduction(k,m,steps) << endl;
    return 0;
}