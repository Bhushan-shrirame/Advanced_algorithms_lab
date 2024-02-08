#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // this vector will store the graph and the first bool value will store if is is used or not;
    vector<pair<bool,pair<int,int>>> graph;
    vector<pair<int ,int>> father;
    void Solver(vector<pair<int ,int>> grp){

        //updating the graph
        int j=0;
        for(auto i:grp){
            graph[j].second.first = i.first;
            graph[j].second.second = i.second;
            graph[j].first = false;
            j++;
        }

        // starting algorithm

    }
};

int main(){
    Solution st;
    int n;
    cin >> n;
    vector<pair<int ,int>> grp(0);
    for(int i=0;i<n;i++){
        int a ,b;
        cin >> a >> b;
        grp.push_back({a,b});
        grp.push_back({b,a});
    }
    st.Solver(grp);
    return 0;
}