class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int num = n;
        int result = 0;
        int curr = 1;
        while(num){
            int rem = num%2;
            num /= 2;
            if(rem==1){
                if(prev!=-1){
                    result = max(result,curr-prev);
                }
                prev = curr;
            }
            curr++;
        }
        return result;
    }
};