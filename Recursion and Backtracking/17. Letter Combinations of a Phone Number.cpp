class Solution {
public:
    void generateCombinations(string digits,int curr,string currstr,vector<string>&ans,unordered_map<char,string>&mp)
    {
        if(curr>=digits.size())
        {ans.push_back(currstr);
         return;
        }
        char currchar = digits[curr];
        string mappings = mp[currchar];
        
        for(int i=0;i<mappings.size();i++)
        {
            generateCombinations(digits,curr+1,currstr+mappings[i],ans,mp);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp{
            {'1', ""}, 
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
          };
        vector<string>ans;
        if(digits.size()==0) return ans;
        generateCombinations(digits,0,"",ans,mp);
        return ans;
    }
};