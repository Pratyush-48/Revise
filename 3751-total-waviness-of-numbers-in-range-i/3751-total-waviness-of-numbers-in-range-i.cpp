class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int result = 0;
        for(int num=num1;num<=num2;num++){
            int val = num;
            vector<int>dig;
            while(val){
                dig.push_back(val%10);
                val/=10;
            }
            if(dig.size()<3) continue;
            reverse(dig.begin(),dig.end());
            int res = 0;
            for(int j=1;j<dig.size()-1;j++){
                if(dig[j]>dig[j-1] && dig[j]>dig[j+1]){
                    res++;
                }
                else if(dig[j]<dig[j-1] && dig[j]<dig[j+1]){
                    res++;
                }
            }
            result += res;
        }
        return result;
    }
};