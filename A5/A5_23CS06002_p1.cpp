#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        int l = 1; 
        for(int i=1;i<nums.size();i++){
            if(temp.back() < nums[i]) temp.push_back(nums[i]) ,l++;
            else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        // return l;
        cout << "Result: " << l << endl;
        for(auto i:temp) cout << i  << " ";
        cout << endl;
    }
};

int main(){
    // ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
    Solution st;
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    st.lengthOfLIS(nums);
    return 0;
}