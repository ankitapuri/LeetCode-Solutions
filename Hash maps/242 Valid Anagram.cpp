class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>mp;
        if(s.size() != t.size())
            return false;
        for(int i=0;i<s.size();i++)
        {
            char currchar = s[i];
            if(mp.find(currchar)!=mp.end())
            {
                mp[currchar]+=1;
            }
            else
                mp[currchar]=1;
        }
       for(int i=0;i<t.size();i++)
       {
           char currchar = t[i];
           if(mp.find(currchar)==mp.end())
               return false;
           mp[currchar]-=1;
           if(mp[currchar]==0)
               mp.erase(currchar);
       }
        return mp.size()==0;
    }
};

