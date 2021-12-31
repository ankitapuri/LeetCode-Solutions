#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&nums)
{
   int ans = 0;
    map <pair <int,int>, int> mp;
    int countZero=0,countOnes=0,countTwos=0;
    string currkey= to_string(countOnes-countZero)+"#"+to_string(countTwos-countOnes);
    mp[make_pair(0,0)]=-1;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==0)
          countZero+=1;
        else if(nums[i]==1)
           countOnes+=1;
        else
          countTwos+=1;
    pair <int, int> currkey= make_pair(countOnes-countZero,countTwos-countOnes);  
    if(mp.find(currkey)!=mp.end())
    {
        int prevIndex = mp[currkey];
        int length = i-prevIndex;
         ans=max(ans,length);
    }
    else
      mp[currkey]=i;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<solve(nums);
    return 0;
}