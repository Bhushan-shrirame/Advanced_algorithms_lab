#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int Weighted_Interval_Scheduling(vector<vector<int>> jobs){
        int n = jobs.size();
        sort(jobs.begin(),jobs.end());
        vector<int> dp(n + 1, 0);
        for (int idx = n - 1; idx >= 0; idx--) {
            int notTake = dp[idx + 1];
            vector<int> v = {jobs[idx][1], 0, 0};
            int nextIdx = lower_bound(jobs.begin(), jobs.end(), v) - jobs.begin();
            int take = jobs[idx][2] + dp[nextIdx];
            dp[idx] = max(take, notTake);
        }
        return dp[0];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    Solution st;
    int n;
    cin >> n;
    vector<vector<int>> jobs;
    for(int i=0;i<n;i++){
        int a , b ,c;
        cin >> a >> b >> c;
        jobs.push_back({a,b,c});

    }
    int res  = st.Weighted_Interval_Scheduling(jobs);
    cout << "Result: " << res <<endl;
    return 0;
}