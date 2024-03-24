#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int  Maximum_Number_of_Envelops(vector<vector<int>> Envelops){
        return 0;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    Solution st;
    int n;
    cin >> n;
    vector<vector<int>> Envelops;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        Envelops.push_back({a,b});
    }
    st.Maximum_Number_of_Envelops(Envelops);
    return 0;
}

