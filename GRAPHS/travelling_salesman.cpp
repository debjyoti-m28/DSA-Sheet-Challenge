#include <bits/stdc++.h>
using namespace std;

int tsp(int mask,int pos,int n,vector<vector<int>> &distance,vector<vector<int>> &dp){
    if(mask == ((1<<n)-1)) return distance[pos][0];
    if(dp[mask][pos]!=-1) return dp[mask][pos];
        
    int ans=INT_MAX;
    for(int city=0; city<n; city++){
        if((mask&(1<<city))==0){
            int newAns= distance[pos][city]+ tsp(mask|(1<<city),city,n,distance,dp);
             ans= min(ans,newAns);
        }
    }
    return dp[mask][pos]=ans;
}
int shortestRoute(vector<vector<int>> &distance)
{       
	    int n=distance.size();
        vector<vector<int>> dp((1<<n), vector<int>(n,-1));
        return tsp(1,0,n,distance,dp);

}
