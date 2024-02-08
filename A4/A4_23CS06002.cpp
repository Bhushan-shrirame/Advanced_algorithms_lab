#include <bits/stdc++.h>
using namespace std;

// no. of nodes
extern int global;

class Solution{
public:
    // this vector will store the graph and the first bool value will store if is is used or not;
    vector<pair<bool,pair<int,int>>> graph;
    void Solver(vector<pair<int ,int>> grp ){
        vector<int>father(6 ,-1);

        //updating the graph
        int j=0;
        for(auto i:grp){
            graph[j].second.first = i.first;
            graph[j].second.second = i.second;
            graph[j].first = false;
            j++;
        }

        // starting algorithm
        int initiator = graph[0].second.first;
        cout<< "initiator"<<initiator << "\n";

    }
};

int main(){
    Solution st;
    cin >> global;
    
    vector<pair<int ,int>> grp(0);
    for(int i=0;i<global;i++){
        int a ,b;
        cin >> a >> b;
        grp.push_back({a,b});
        grp.push_back({b,a});
    }
    st.Solver(grp);
    return 0;
}