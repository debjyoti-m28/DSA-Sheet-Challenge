#include <bits/stdc++.h>
using namespace std;
//

class Solution {
public:
    void dfs(int i,int j,int initial,int final,vector<vector<int>>& image){
        int r=image.size();
        int c=image[0].size();
        if(i<0 || j<0 || i>=r || j>=c)
            return;
        if(initial != image[i][j])
            return;
        
       image[i][j]=final;
        dfs(i,j+1,initial,final,image);
        dfs(i,j-1,initial,final,image);
        dfs(i+1,j,initial,final,image);
        dfs(i-1,j,initial,final,image);
         
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int final) {
        int initial=image[sr][sc];
        if(initial!=final)
         dfs(sr,sc,initial,final,image);
        return image;
    }
};