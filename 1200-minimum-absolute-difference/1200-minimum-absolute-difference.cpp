class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>result;
        sort(arr.begin(),arr.end());
        int min_diff = INT_MAX;
        int n = arr.size();
        for(int i=1;i<n;i++){
            min_diff = min(min_diff,abs(arr[i]-arr[i-1]));
        }
        for(int i=1;i<n;i++){
            if(abs(arr[i]-arr[i-1])==min_diff){
                result.push_back({arr[i-1],arr[i]});
            }
        }
        return result;
    }
};