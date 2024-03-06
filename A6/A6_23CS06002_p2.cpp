#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int Egg_Dropping_Puzzle(int n, int k){
        vector<vector<int> > dp(k + 1, vector<int>(n + 1, 0));
        int m = 0;
        while (dp[m][n] < k) {
            m++;
            for (int x = 1; x <= n; x++) dp[m][x] = 1 + dp[m - 1][x - 1] + dp[m - 1][x];
        }
        return m;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    Solution st;
    int n,k;
    cin >> n >> k;
    cout << st.Egg_Dropping_Puzzle(n,k) << endl;
    return 0;
}