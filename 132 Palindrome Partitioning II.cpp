class Solution {
   public:
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    int minCuts(string& s, int start, int end,vector<vector<int>>&vec) {
        if (isPalindrome(s, start, end)) {
            return 0;
        }

        if (vec[start][end] != -1) {
            return vec[start][end];
        }

        int ans = INT_MAX / 2;
        for (int i = start; i < end; i++) {
            if (isPalindrome(s, start, i)) {
                int left = minCuts(s, start, i, vec);
                int right = right = minCuts(s, i + 1, end, vec);
                ans = min(ans, 1 + left + right);
            }
        }

        return vec[start][end] = ans;
    }

    int minCut(string s) {
        vector<vector<int>>vec(2001,vector<int>(2001,-1));
        return minCuts(s, 0, s.length() - 1, vec);
    }
};