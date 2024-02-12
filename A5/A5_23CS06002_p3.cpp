#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;        
        int n = heights.size();
        int maxa = -1 ;
        int left_small[n] ;
        int right_small[n] ;
    
        for(int i = 0 ; i < n ; i++){  
            if(st.empty()){
                st.push(i);
                left_small[i] = 0;
            } 
            if( (!st.empty()) && (heights[st.top()] <= heights[i])){
                left_small[i] = st.top() + 1;
                st.push(i);   
            }
            while((!st.empty()) && (heights[st.top()] >= heights[i])){
                st.pop();
                if( (!st.empty()) && (heights[st.top()] <= heights[i])){
                    left_small[i] = st.top() + 1; 
                }
            }
            if(st.empty()){
                    left_small[i] = 0;
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        
        for(int i = n-1 ; i >= 0 ; i--){   
            while((!st.empty()) && (heights[st.top()] >= heights[i])) st.pop();
            if(st.empty())right_small[i] = n-1;
            else right_small[i] = (st.top() - 1);   
            st.push(i);
        }
        for(int x = 0 ; x < n ; x++) maxa =  max(maxa,(heights[x] * ( right_small[x] - left_small[x] + 1 )));
        return maxa;
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
    int res = st.largestRectangleArea(nums);
    cout << "Result: " << res << endl;
    return 0;
}