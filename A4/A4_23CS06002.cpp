#include <bits/stdc++.h>
using namespace std;

// no. of nodes
extern int global;

class Solution{
public:
    // this vector will store the graph and the first bool value will store if is is used or not;
    vector<pair<bool,pair<int,int>>> graph;


    //to check whether all the neighbour is used or not
    bool all_neighbour_used(int q){
        //TODO
    }

    //to check if their is some neighbour where (q != father[p]) or (!used[p][q])
    int some_neighbour_not_used(int q, int p){
        //TODO
    }

    // solver function
    void Solver(vector<pair<int ,int>> grp ){
        vector<int>father(6 ,-1);
        int p,q0,q;
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

        int p = graph[0].second.first;
        cout<< "initiator"<<p << "\n";
        father[p] = p;
        cout << "Father" << p << "son " << p << "\n";
        q = p;
        int p = graph[0].second.second;
        graph[0].first = true;
        q0=q;

        //wheather the channel p->q has been used;
        while(p){
            if(father[p] == -1) father[p] = q0;
            if(all_neighbour_used(q)){
                break;
            }
            else if(some_neighbour_not_used(q,p)){
                if((father[p] !=q) ) q = q0;   
                else q = some_neighbour_not_used(q,p);
            }
            // todo used[p][q] = true;
            else {
            //used[p]
            // for(auto i: graph){   
            // }
        }
        }


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