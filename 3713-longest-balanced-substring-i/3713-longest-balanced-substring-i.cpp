class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int max_len = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;
            for (int j = i; j < n; j++) {
                freq[s[j]]++;

                
                int count = freq[s[i]];
                bool balanced = true;
                for (auto &p : freq) {
                    if (p.second != count) {
                        balanced = false;
                        break;
                    }
                }

                if (balanced) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }

        return max_len;
        
    }
};