#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<int>&vis ){
        if(vis[node]) return;
        
        vis[node]=1;
        for(auto adj_node: adj[node]){
            if(!vis[adj_node]) dfs(adj_node,adj,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& con) {
      int cables=con.size();
        if(cables<n-1) return -1;
        vector<int>vis(n,0);
        vector<int>adj[n];
        for(auto it:con){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
                
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i, adj, vis);
                cnt++;
            }
        }
        return cnt-1;
    }
};