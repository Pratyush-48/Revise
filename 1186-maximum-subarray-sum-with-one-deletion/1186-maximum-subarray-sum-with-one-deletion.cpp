class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int>pre(n,0);
        vector<int>suff(n,0);
        pre[0] = arr[0];
        suff[n-1] = arr[n-1];
        for(int i=1;i<n;i++){
            pre[i] = max(arr[i]+pre[i-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            suff[i] = max(suff[i+1]+arr[i],arr[i]);
        }
        int result = *max_element(pre.begin(),pre.end());
        for(int i=1;i<n-1;i++){
            result = max(result,pre[i-1]+suff[i+1]);
        }
        return result;
    }
};