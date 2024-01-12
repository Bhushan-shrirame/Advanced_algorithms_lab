#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countstringwithvowel(int n){
        n++;
        cout << (n+3)*(n+2)*(n+1)*n/24 << endl;
		return (n+3)*(n+2)*(n+1)*n/24;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution sol;
    int n;
    cin >> n;
    sol.countstringwithvowel(n);
    return 0;
}