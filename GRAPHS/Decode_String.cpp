#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int n=s.length();
        stack<int>st_int;
        stack<string>st_str;
        string res="";
        int num=0;
        
        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9') num=num*10 + (s[i]-'0');
            else if(s[i]>='a' && s[i]<='z') res += s[i];
            else if(s[i]=='['){
                st_int.push(num);
                st_str.push(res);
                res="";
                num=0;
            }
            else{
                int j=st_int.top();
                st_int.pop();
                string temp=res;
                
                for(int i=0; i<j-1 ;i++){
                    res +=temp;
                }
                
                    res = st_str.top()+res;
                    st_str.pop();
            }
            
        }
        return res;
    }
};