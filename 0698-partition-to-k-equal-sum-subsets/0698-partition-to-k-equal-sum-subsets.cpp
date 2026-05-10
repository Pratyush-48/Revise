class Solution {
public:
 bool backtrack(int start, vector<int>& nums, vector<bool>& visited, int k, int currSum, int target) {
    if (k == 0) return true;  // all k subsets formed
    if (currSum == target)    // one subset formed, start next
        return backtrack(0, nums, visited, k - 1, 0, target);

    for (int i = start; i < nums.size(); ++i) {
        if (visited[i] || currSum + nums[i] > target) continue;
        visited[i] = true;
        if (backtrack(i + 1, nums, visited, k, currSum + nums[i], target))
            return true;
        visited[i] = false; // backtrack
        // Optimization: if currSum is 0 and first pick fails, break (to avoid duplicates)
       // if (currSum == 0) break;
    }

    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) return false;
    int target = sum / k;
    sort(nums.rbegin(), nums.rend()); // sorting helps early pruning

    vector<bool> visited(nums.size(), false);
    return backtrack(0, nums, visited, k, 0, target);
}


};