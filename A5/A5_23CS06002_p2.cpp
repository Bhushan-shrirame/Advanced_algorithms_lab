#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        if (s.empty()) return 0;
        int n = static_cast<int>(s.size());
        vector<vector<bool>> is_pal(n, vector<bool>(n, false));
        for (auto i = 0; i  < n; i ++) is_pal[i][i] = true;
        for (auto len = 2; len <= n; len++){
            for (auto i = 0; i <= n - len; i++){
                auto j = i + len - 1;
                if ((s[i] == s[j]) && ((len == 2) || is_pal[i + 1][j - 1])) is_pal[i][j] = true;
            }
        }
        vector<int> dp(n, 0);
        for (auto i = 0; i < n; i++)dp[i] = i;
        for (auto i = 1; i < n; i++){
            if (is_pal[0][i]) dp[i] = 0;
            else for (auto j = 1; j <= i; j++) if (is_pal[j][i]) dp[i] = std::min(dp[i], dp[j - 1] + 1);
        }
        return dp[n - 1];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    Solution st;
    string s;
    cin >> s;
    int res =  st.minCut(s);
    cout << "Result: "<< res << endl;
    return 0;
}