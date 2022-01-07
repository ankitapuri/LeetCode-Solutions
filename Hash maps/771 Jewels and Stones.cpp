class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans=0;
        unordered_map<char,int>mp;
       for(int i=0;i<jewels.size();i++)
       {
           char currchar = jewels[i];
           if(mp.find(currchar)!=mp.end())
               mp[currchar]+=1;
           else
               mp[currchar]=1;
       }
        for(int j=0;j<stones.size();j++)
        {
            if(mp.find(stones[j])!=mp.end())
                ans+=1;
        }
        return ans;
    }
};