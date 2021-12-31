class Solution
{
  public:
long long atMostKDistinctCharacters(string s, int k) {
        int memo[26]{0};
        long long answer = 0, distinctCount = 0, rel = 0;

        for (int i = 0; i < s.size(); i++) {
            int currentChar = s[i] - 'a';
            if (memo[currentChar] == 0) {
                distinctCount++;
            }
            memo[currentChar]++;
            if (distinctCount > k) {
                while (distinctCount > k) {
                    if (memo[s[rel] - 'a'] == 1) {
                        distinctCount--;
                    }
                    memo[s[rel++] - 'a']--;
                }
            }
            answer += i - rel + 1;
        }
        return answer;
    }
    
    long long int substrCount (string s, int k) {
      //code here.
      return atMostKDistinctCharacters(s, k) - atMostKDistinctCharacters(s, k - 1);
    }
};