class Solution {
public:
    long long getN(long long S, long long i) {
    long long constant = (2 * S) / i;
    long long n = (-1 + sqrt(1 + 4 * constant)) / 2;
    return n;
    }
    bool check(long long mid,int mountainHeight,vector<int>&workerTimes){
        int n = workerTimes.size();
        for(int i=0;i<n;i++){
            long long val = getN((long long)mid,(long long)workerTimes[i]);
            mountainHeight -= val;
            if(mountainHeight<=0) return true;
        }
        return mountainHeight<=0;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long result = 1e18;
        long long start = 1;
        long long end = 1e18;
        while(start<=end){
            long long mid = (start+end)/2;
            if(check(mid,mountainHeight,workerTimes)){
                result = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return result;
    }
};