class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> ans;
        int n = strs.size();
        map<map<char,int>, vector<string>> mp;
        // Here it stores the letter and the frequancy of it and the string whose freq count in being             //stored
        for(int i=0;i<n;i++)
        {
            map<char,int>freq;
            string k =strs[i];
            vector<string>list;
            for(int j=0;j<k.size();j++)
            {
                char currchar = k[j];
                auto itr = freq.find(currchar);
                if(itr!=freq.end())
                    freq[currchar]+=1;
                else
                    freq[currchar]=1;
            }
            auto it = mp.find(freq);
            if(it!=mp.end())
                it->second.push_back(k);
            else
            {
                list.push_back(k);
                mp.insert({freq,list});
            }
        }
         for(auto it=mp.begin();it!=mp.end();it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};

