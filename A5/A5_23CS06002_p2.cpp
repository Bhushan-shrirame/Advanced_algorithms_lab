#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int cnt = 0;
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]) cnt++,l--, r++;
            ans += cnt;
            l = i, r = i+1, cnt = 0;
            while(l >= 0 && r < n && s[l] == s[r]) cnt++ ,l--, r++;
            ans += cnt;
        }
        return ans;
    }
};

int main(){
    // ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
    Solution st;
    string s;
    cin >> s;
    int res =  st.countSubstrings(s);
    cout << "Result: "<< res << endl;
    return 0;
}