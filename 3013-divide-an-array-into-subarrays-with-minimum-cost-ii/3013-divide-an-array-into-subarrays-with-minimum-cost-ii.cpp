class Solution {
public:
    typedef long long ll;
    typedef pair<ll,ll> p;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        ll sum = 0;
        ll result = LONG_LONG_MAX;
        int n = nums.size();
        set<p>kmin;
        set<p>removed;
        int i = 1;
        while(i-dist<1){
            sum += nums[i];
            kmin.insert({nums[i],i});
            if(kmin.size()>k-1){
                p temp = *kmin.rbegin();
                kmin.erase(temp);
                removed.insert(temp);
                sum -= temp.first;
            }
            i++;
        }
        while(i<n){
            sum += nums[i];
            kmin.insert({nums[i],i});
            if(kmin.size()>k-1){
                p temp = *kmin.rbegin();
                kmin.erase(temp);
                removed.insert(temp);
                sum -= temp.first;
            }
            result = min(result,sum);
            // removing the first element from the window
            p rem = {nums[i-dist],i-dist};
            if(kmin.count(rem)){
                sum -= rem.first;
                kmin.erase(rem);
                if(!removed.empty()){
                    p ne = *removed.begin();
                    removed.erase(ne);
                    sum += ne.first;
                    kmin.insert(ne);
                }
            }
            else{
                removed.erase(rem);
            }
            i++;
        }
        return result+nums[0];
    }
};