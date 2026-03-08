class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();
        int result = -1;
        int curr_diff = INT_MAX;
        for(int i=0;i<n;i++){
            if(capacity[i]>=itemSize && curr_diff>(capacity[i]-itemSize)){
                curr_diff = capacity[i]-itemSize;
                result = i;
            }
        }
        return result;
    }
};