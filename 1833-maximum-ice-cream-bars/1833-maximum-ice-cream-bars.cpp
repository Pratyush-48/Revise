class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int>ice(1e5+1,0);
        for(auto &it:costs){
            ice[it]++;
        }
        int result = 0;
        for(int i=0;i<=1e5;i++){
            while(ice[i]>0 && coins>=i){
                result++;
                ice[i]--;
                coins -= i;
            }
        }
        return result;
    }
};