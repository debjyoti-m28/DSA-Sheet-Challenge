#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int charToInt(char c){
        return (c- 'a');
    }
    bool isCycle(int node, vector<int>&vis,vector<int>&dfs,vector<int>adj[],stack<int>&st){
        vis[node]=1;
        dfs[node]=1;

        for(auto it: adj[node]){
            if(vis[it]==0){
                if(isCycle(it,vis,dfs,adj,st)) return true;
            }
            else if(dfs[it]==1) return true;
        }
        dfs[node]=0;
        st.push(node);
        return false;
    }
    string alienOrder(vector<string> &words) {
        string ans="";
        vector<int> adj[26];
        vector<int> present(26,0);

        for(int i=0;i<words.size();i++){
                for(auto it: words[i]){
                    present[charToInt(it)]=1;
                }
            }
        for(int i=0;i<words.size()-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            
            for(int j=0;j<s1.size();j++){
                if(j>=s2.size()) return ""; // "raja" and "raj"
                if(s1[j]!=s2[j]){
                    adj[charToInt(s1[j])].push_back(charToInt(s2[j]));
                    // if they would have said to print only the non maching chars
                    // present[charToInt(s1[j])]=1; 
                    // present[charToInt(s2[j])]=1;
                    break;
                }
            }
        }

        vector<int>vis(26,0);
        vector<int>dfs(26,0);
        stack<int>st;
        for(int i=0;i<26;i++){
            if(present[i]==1 && vis[i]==0) {
                if(isCycle(i,vis,dfs,adj,st)) return "";
            }
        }
        while(!st.empty()){
            ans += char(st.top() + 'a');
            st.pop();
        }
        return ans;
    }
};