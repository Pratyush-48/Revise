class Solution {
    int m;
    int res_mask;

    pair<int, long long> recc(unordered_map<string, int>& skills, int idx, vector<vector<string>>& people, int num, vector<vector<pair<int, long long>>>& dp) {
        if (idx >= m) {
            if (num == res_mask) return {0, 0LL};
            return {1e9, 0LL};
        }
        
        if (dp[idx][num].first != -1) return dp[idx][num];
        
        pair<int, long long> dont_take = recc(skills, idx + 1, people, num, dp);
        
        int next_num = num;
        for (auto& it : people[idx]) {
            if (skills.find(it) != skills.end()) {
                int j = skills[it];
                next_num = next_num | (1 << j);
            }
        }
        
        pair<int, long long> take = recc(skills, idx + 1, people, next_num, dp);
        take.first += 1;
        take.second |= (1LL << idx);
        
        if (take.first < dont_take.first) {
            return dp[idx][num] = take;
        }
        return dp[idx][num] = dont_take;
    }

public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> req;
        int n = req_skills.size();
        m = people.size();
        
        res_mask = (1 << n) - 1; 
        
        vector<vector<pair<int, long long>>> dp(m, vector<pair<int, long long>>(res_mask + 1, {-1, -1}));
        
        unordered_map<string, int> skills;
        for (int i = 0; i < n; i++) {
            skills[req_skills[i]] = i;
        }
        
        auto res = recc(skills, 0, people, 0, dp);
        
        vector<int> result;
        long long r = res.second;
        
        for (int i = 0; i < m; ++i) {
            if ((r >> i) & 1) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};