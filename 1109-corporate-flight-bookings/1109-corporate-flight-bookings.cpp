class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n,-1);
        map<double,int>mp;
        for(auto &it:bookings){
            mp[it[0]] += it[2];
            mp[(double)it[1]+0.01] -= it[2];
        }
        int sum = 0;
        for(auto &it:mp){
            sum += it.second;
            double num =  it.first;
            if((num-(int)num) == 0.0){
                ans[(int)num-1] = sum;
            }
            else{
                if(ceil(num)-1 >= n) break;
                ans[(int)ceil(num)-1] = sum;
            }
        }
        if(ans[0]==-1) ans[0]=0;
        for(int i=1;i<n;i++){
            if(ans[i]==-1) ans[i] = ans[i-1];
        }
        return ans;
    }
};