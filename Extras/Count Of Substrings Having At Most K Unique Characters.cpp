#include<bits/stdc++.h>
using namespace std;
int solve(string s, int k)
{
    int ans=0;
    int distinctcnt=0;
    int release=0;
    unordered_map<char,int>mp;
    for(int i=0;i<s.size();i++)
    {
       char currchar = s[i];
     if(mp.find(currchar)!=mp.end())
       mp[currchar]+=1;
       else
       {   distinctcnt+=1;
           mp[currchar]=1;
       }
       while(release<=i and distinctcnt>k)
       {
           char dischar = s[release];
           mp[dischar]-=1;
           release+=1;
        if(mp[dischar]==0)
        {
            mp.erase(dischar);
            distinctcnt-=1;
        }
          
       }
       ans+=(i-release+1); 
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    cout<<solve(s,n);
    
}