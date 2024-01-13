#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countstringwithvowel(int n){
        n++;
		return (n+3)*(n+2)*(n+1)*n/24;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution sol;
    int n ,res;
    cin >> n;
    int res = sol.countstringwithvowel(n);
    cout << res << endl;
    return 0;
}