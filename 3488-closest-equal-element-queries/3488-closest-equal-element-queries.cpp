class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
    vector<int> num_equal(n, -1);
    
    unordered_map<int, vector<int>> value_to_indices;
    for (int i = 0; i < n; i++) {
        value_to_indices[nums[i]].push_back(i);
    }
    
    for (const auto& [val, indices] : value_to_indices) {
        int m = indices.size();
        
        if (m <= 1) continue; 
        
        for (int k = 0; k < m; k++) {
            int current_idx = indices[k];
            
            int prev_idx = indices[(k - 1 + m) % m];
            int next_idx = indices[(k + 1) % m];
            
            int dist_left = (current_idx - prev_idx + n) % n;
            int dist_right = (next_idx - current_idx + n) % n;
            
            num_equal[current_idx] = min(dist_left, dist_right);
        }
    }
    
    vector<int> result;
    //result.reserve(queries.size());
    for (int q : queries) {
        result.push_back(num_equal[q]);
    }
    
    return result;
    }
};