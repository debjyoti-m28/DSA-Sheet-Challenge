#include <bits/stdc++.h>
using namespace std;
//

class DSU{
public:
    vector<int>parent,size;
public:
    DSU(int n){
        for(int i=0;i<n;++i){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int findparent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findparent(parent[node]);
    }
    void unionof(int node1,int node2){
        int par1=findparent(node1);
        int par2=findparent(node2);
        if(par1==par2) return;
        else if(size[par1]<size[par2]){
            parent[par1]=par2;
            size[par2]+=size[par1];
        }
        else{
            parent[par2]=par1;
            size[par1]+=size[par2];
        }
    }
};


class Solution {
public:
int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DSU dsu(n*n);
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1){
                    
                    int node=i*n+j;
                    
                    for(int dir=0;dir<4;++dir){
                        int nr=i+dx[dir];
                        int nc=j+dy[dir];
                        if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==1){
                            int node2=(nr*n)+nc;
                            if(dsu.findparent(node)!=dsu.findparent(node2)){
                                dsu.unionof(node,node2);              
                            }
                        }
                    }
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n*n;++i)
            ans=max(ans,dsu.size[i]);
    
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==0){
                    
                    int node1=i*j+1;
                    int sze=1;
                    
                    unordered_set<int> st;
                    for(int k=0;k<4;++k) {
                        int row=i+dx[k];
                        int col=j+dy[k];
                        if(row>=0 && col>=0 && row<n && col<n && grid[row][col]==1){
                            int node2=row*n+col;
                            int up=dsu.findparent(node2);
                            if(st.find(up)==st.end()){
                                st.insert(up);
                                sze+=dsu.size[up];
                            }    
                        }
                    }
                    ans=max(ans,sze); 
                }
            }
        }
        return ans;
    }
};