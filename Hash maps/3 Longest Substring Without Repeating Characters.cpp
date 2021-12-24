class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left = 0;
        unordered_map<char,int>mp;
        for(int right=0;right<s.size();right++)
        {
            char currchar = s[right];
            if(mp.find(currchar)!=mp.end() && mp[currchar]>=left)
            {
                left = mp[currchar]+1;
            }
            int a = right-left+1;
            mp[currchar]=right;
            ans = max(ans,a);
        }
        return ans;
    }
};