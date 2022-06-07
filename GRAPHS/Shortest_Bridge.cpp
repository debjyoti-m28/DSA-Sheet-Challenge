#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void floodfill(vector<vector<int>>& grid, int i, int j,int n, queue<pair<int,int>> &q,vector<vector<int>> &vis){  
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j]!=1 || vis[i][j]==1) return;
        
        q.push({i,j});
        vis[i][j]=1;
        
        floodfill(grid,i+1,j,n,q,vis);
        floodfill(grid,i,j+1,n,q,vis);
        floodfill(grid,i-1,j,n,q,vis);
        floodfill(grid,i,j-1,n,q,vis);  
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n, vector<int>(n,0));
        queue<pair<int,int>>q;
        bool flag=false;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) {
                    floodfill(grid,i,j,n,q,vis);
                    flag=true;
                    break;
                }  
            }
            if(flag) break;
        }
        
        int dx[]={0,1,-1,0};
        int dy[]={1,0,0,-1};
        int cnt=0;
        
        while(!q.empty()){
            int size=q.size();
            while(size--){
               int x=q.front().first;
               int y=q.front().second;
               q.pop();
            
            for(int k=0;k<4;k++){
                int curr_x=x+dx[k], curr_y=y+dy[k];
                if(curr_x>=0 && curr_x<n && curr_y>=0 && curr_y<n && vis[curr_x][curr_y]==0){
                    if(grid[curr_x][curr_y]==1) return cnt;
                    q.push({curr_x,curr_y});
                    vis[curr_x][curr_y]=1;
                }
            } 
          }
          cnt++; 
        }
        return -1;
        
    }
};