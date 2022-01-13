class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        unordered_map<int,int>mpp;
        for(int i=0;i<arr.size();i++)
        {
            int currval = arr[i];
            if(mp.find(currval)!=mp.end())
                mp[currval]+=1;
            else
                mp[currval]=1;
        }
//         for(auto it=mp.begin();it!=mp.end();it++)   // using 2nd map
//         {
//             mpp[it->second]++;
//             if(mpp[it->second]>1)
//             {
//                 return false;
//             }
            
//         }
//         return true;
//     }
        set<int>s;
        for(auto it=mp.begin();it!=mp.end();it++) 
        {
            s.insert(it->second);
        }
        if(mp.size()==s.size()) return true;
        return false;
        
            
     }
};