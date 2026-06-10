class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> result;
    set<pair<int, int>> visited;

    pq.push({nums1[0] + nums2[0], 0, 0});
    visited.insert({0, 0});

    while (!pq.empty() && result.size() < k) {
        auto [sum, i1, j1] = pq.top();
        pq.pop();
        
        result.push_back({nums1[i1], nums2[j1]});
        
        if (i1 + 1 < n && visited.find({i1 + 1, j1}) == visited.end()) {
            pq.push({nums1[i1 + 1] + nums2[j1], i1 + 1, j1});
            visited.insert({i1 + 1, j1});
        }
        
        if (j1 + 1 < m && visited.find({i1, j1 + 1}) == visited.end()) {
            pq.push({nums1[i1] + nums2[j1 + 1], i1, j1 + 1});
            visited.insert({i1, j1 + 1});
        }
    }
    
    return result;
}
};