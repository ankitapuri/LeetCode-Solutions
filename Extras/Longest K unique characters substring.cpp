class Solution{
  public:
    int longestKSubstr(string s, int k) {
    int ans = -1;
    int left = 0;
    unordered_map<char,int>mp;
    for(int right=0;right<s.size();right++)
    {
           char currchar = s[right];
            if(mp.find(currchar)!=mp.end())
            {
                mp[currchar]+=1;
            }
            else
              mp[currchar]=1;
            while(left<=right && mp.size()>k)
            {
                char dischar = s[left];
                mp[dischar]-=1;
                left+=1;
                
                if(mp[dischar]==0)
                 mp.erase(dischar);
            }
            if(mp.size()==k)
            ans = max(ans,right-left+1);
    }
    return ans;
    }
};