class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>vec(word1.size(),vector<int>(word2.size(),-1));
        return MinOperations(word1,word2,0,0,vec);
    }
    int MinOperations(string &word1, string &word2,int curr1,int curr2, vector<vector<int>>&vec)
    {
        
        if(curr1>=word1.size() && curr2<=word2.size()) return word2.size()-curr2;
        if(curr1<=word1.size() &&curr2>=word2.size()) return word1.size()-curr1;
        if(vec[curr1][curr2]!=-1) return vec[curr1][curr2]; 
        if(word1[curr1]==word2[curr2]) 
        {
            return vec[curr1][curr2]=MinOperations(word1,word2,curr1+1,curr2+1,vec);
        }
        else
        {
            int insert_char = 1+MinOperations(word1,word2,curr1,curr2+1,vec);
            int delete_char = 1+MinOperations(word1,word2,curr1+1,curr2,vec);
            int replace_char = 1+MinOperations(word1,word2,curr1+1,curr2+1,vec);
            return vec[curr1][curr2] = min(replace_char,min(insert_char,delete_char));
        }
    }
};