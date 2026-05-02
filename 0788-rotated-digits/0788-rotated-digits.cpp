class Solution {
public:
    int rotatedDigits(int n) {
        int result = 0;
        unordered_map<int,int>rules;
        rules[0] = 0;
        rules[1] = 1;
        rules[2] = 5;
        rules[3] = -1;
        rules[4] = -1;
        rules[5] = 2;
        rules[6] = 9;
        rules[7] = -1;
        rules[8] = 8;
        rules[9] = 6;
        for(int i=1;i<=n;i++){
            int num = i;
            bool can = true;
            bool atleast_one = false;
            while(num){
                int mo = num%10;
                if(rules[mo]==-1){
                    can = false;
                    break;
                }
                if(rules[mo]!=mo) atleast_one = true;
                num /= 10;
            }
            if(can && atleast_one) result++;
        }
        return result;
    }
};