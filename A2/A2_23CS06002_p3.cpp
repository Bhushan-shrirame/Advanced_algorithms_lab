#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return vector<int>{0};
        vector<vector<int>>graph(n);
        vector<int>degree(n,0);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0], b=edges[i][1];
            
            graph[a].push_back(b);
            graph[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        queue<int>queue_degree_1;
        for(int i=0;i<n;i++) if(degree[i]==1) queue_degree_1.push(i);
        vector<int>res;
        while(!queue_degree_1.empty()){
            int n = queue_degree_1.size();
            res.clear();
            while(n--){
                int node = queue_degree_1.front();
                queue_degree_1.pop();
                res.push_back(node);
                for(int i=0;i<graph[node].size();i++){
                    degree[graph[node][i]]--;
                    if(degree[graph[node][i]]==1) queue_degree_1.push(graph[node][i]);
                }
            }
        }
        return res;
    }
};
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    Solution sol;
    int n,e;
    cout << "Enter no. of nodes ";
    cin >> n; 
    cout << "Enter no. of edge ";
    cin >> e;
    vector<vector<int>>edges;
    vector<int>res;
    for(int i=0;i<e;i++){
        vector<int>temp;
        for(int j=0;j<2;j++){
            int a;
            cin >> a ;
            temp.push_back(a);
        }
        edges.push_back(temp);
    }
    res = sol.findMinHeightTrees(n,edges);
    for(int i=0;i<res.size();i++) cout << res[i] << " ";
    cout<<endl;
    return 0;
}