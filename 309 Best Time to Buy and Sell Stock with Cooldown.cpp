class Solution {
public:
    int bestTrans(vector<int>&prices,int curr,bool canbuy ,vector<vector<int>>&vec)
    {
        
        if(curr>=prices.size()) return 0;
        // if(trans<=0) return 0;
        if(vec[curr][canbuy]!= -1)
           return vec[curr][canbuy];
        if(canbuy)
        {
            int idle = bestTrans(prices,curr+1,canbuy,vec); 
            int buy = -prices[curr]+bestTrans(prices,curr+1,false,vec);
            return vec[curr][canbuy]=max(idle,buy);
        }
        else{
            int idle1 = bestTrans(prices,curr+1,canbuy,vec);
            int sell = prices[curr]+bestTrans(prices,curr+2,true,vec);// cooldown after 1 transaction
            return vec[curr][canbuy]=max(idle1,sell);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>vec(prices.size(),vector<int>(2,-1));
        return bestTrans(prices,0,1,vec);
        
    }
};