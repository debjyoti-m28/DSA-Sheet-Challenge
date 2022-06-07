#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     bool dfs(int i, vector<vector<int>>& g, vector<int>& state){
        if(state[i]) return state[i]==1;
         
        state[i] = 2;
        for(auto& a: g[i]){
            if(!dfs(a, g, state)) return false;
        }
        state[i] = 1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        vector<int>result;
        vector<int> state(n);
        for(int i = 0; i < n; i++)
            if(dfs(i, g, state)) result.push_back(i);
        
        return result;
    }
};