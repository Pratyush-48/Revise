class Solution {
public:
    int minimumDistance(vector<int>& nums) {
    unordered_map<int, vector<int>> mp;
    int n = nums.size();
    
    for(int i = 0; i < n; i++){
        mp[nums[i]].push_back(i);
    }
    
    deque<int> dq;
    int result = INT_MAX;
    
    for(auto &it : mp){
        if(it.second.size() < 3) continue;
        
        for(int index : it.second){
            dq.push_back(index);
        }
        
        while(dq.size() >= 3){
            int a = dq[0];
            int b = dq[1];
            int c = dq[2];
            
            int dist = abs(a - b) + abs(b - c) + abs(c - a);
            result = min(result, dist);
            
            dq.pop_front();
        }
        
        dq.clear(); 
    }
    
    return result == INT_MAX ? -1 : result;
}
};