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
        int p,q0;
        //updating the graph
        int j=0;
        for(auto i:grp){
            graph[j].second.first = i.first;
            graph[j].second.second = i.second;
            graph[j].first = false;
            j++;
        }

        // starting algorithm

        //this will run one time so no need for loop;
        // initializing the initiator

        int initiator = graph[0].second.first;
        cout<< "initiator"<<initiator << "\n";
        father[initiator] = initiator;
        cout << "Father" << initiator << "son " << initiator << "\n";
        int choose = graph[0].second.second;
        graph[0].first = true;



        //wheather the channel p->q has been used;

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