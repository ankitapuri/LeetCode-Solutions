class Solution {
public:
    /**
     * @param s: a string
     * @param k: an integer
     * @return: the number of substrings there are that contain at least k distinct characters
     */
    long long atMostKDistinctCharacters(string s, int k) {
        unordered_map<int,int> memo;
        int answer = 0, distinctCount = 0, rel = 0;

        for (int i = 0; i < s.size(); i++) {
            if (memo.count(s[i]) == 0) {
                distinctCount++;
            }
            memo[s[i]]++;
            if (distinctCount > k) {
                while (distinctCount > k) {
                    if (memo[s[rel]] == 1) {
                        memo.erase(s[rel++]);
                        distinctCount--;
                    } else {
                        memo[s[rel++]]--;
                    }
                }
            }
            answer += i - rel + 1;
        }
        return answer;
    }

    long long kDistinctCharacters(string &s, int k) {
        // Write your code here
        long long n = s.size();
        return (n * (n + 1) / 2) - atMostKDistinctCharacters(s, k - 1);
    }
};