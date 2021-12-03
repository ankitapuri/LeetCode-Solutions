class Solution {
public:
    int totalways(int curr, vector<int>& coins, int amount,unordered_map<string,int>&mp){
        if (amount == 0) return 1;
        if(curr >= coins.size()) return 0;   
        
        string currkey = to_string(curr)+"_"+to_string(amount);
        if(mp.find(currkey)!=mp.end())
            return mp[currkey];
        int consider =0;
        
        if(coins[curr]<=amount){
            consider = totalways(curr,coins,amount-coins[curr],mp);
        }
        int notConsider = totalways(curr+1,coins,amount,mp);
        
        return mp[currkey] = consider+notConsider;
    }
    int change(int amount, vector<int>& coins) {
        unordered_map<string,int>mp;
        
        int ans = totalways(0,coins,amount,mp);
        
            return ans;
        
    }
};