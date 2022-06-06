#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int x,int y, int n, int m){
        return ( x>=0 && y >=0 && x<n && y<m);
    }
    void bfs(int i,int j, int n, int m, vector<vector<char>>& grid,vector<vector<int>>&vis){
        int dx[]={1,0,-1,0};
        int dy[]={0,1,0,-1};
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++){
                int curr_x=x+dx[k], curr_y=y+dy[k];
                if(isValid(curr_x,curr_y,n,m) && grid[curr_x][curr_y]=='1' && vis[curr_x][curr_y]==0){
                    q.push({curr_x,curr_y});
                    vis[curr_x][curr_y]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int no_of_island=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    no_of_island++;
                    bfs(i,j,n,m,grid,vis);
                }
            }
        }
        return no_of_island;
    }
};