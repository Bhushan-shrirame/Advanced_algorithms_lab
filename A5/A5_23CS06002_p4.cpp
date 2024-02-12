#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& h) {
        int l=0,r=h.size()-1,lmax=INT_MIN,rmax=INT_MIN,ans=0;
        while(l<r){
            lmax=max(lmax,h[l]);
            rmax=max(rmax,h[r]);
            ans+=(lmax<rmax)?lmax-h[l++]:rmax-h[r--];
        }
        return ans;
    }
};    

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    Solution st;
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    int res = st.trap(nums);
    cout << "Result: " << res << endl;
    return 0;
}