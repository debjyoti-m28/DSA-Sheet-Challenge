#include <bits/stdc++.h>
using namespace std;

bool isValid(int r,int c, int n){
    return (r>0 && c>0 && r<=n && c<=n);
}

int minSteps(pair<int, int> knightPosition, pair<int, int> targetPosition, int size) {
   vector<vector<int>>vis(size+1, vector<int>(size+1,0));
    int dx[]={-2,-2,-1,1,2,2,1,-1};
    int dy[]={-1,1,2,2,1,-1,-2,-2};
    queue<pair<int,int>>q;
    int in_x=knightPosition.first;
    int in_y=knightPosition.second;
    q.push({in_x,in_y});
    vis[in_x][in_y]=1;
    
    int bfs=0;
    while(!q.empty()){
        int len=q.size();
        while(len--){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
             if(x==targetPosition.first && y==targetPosition.second) return bfs;
            
        for(int k=0;k<8;k++){
            int nx=x+dx[k], ny=y+dy[k];
            if(isValid(nx,ny,size) && vis[nx][ny]==0){
                q.push({nx,ny});
                vis[nx][ny]=1;
            }
        }
      }
        bfs++;
    }
    return -1; 
}