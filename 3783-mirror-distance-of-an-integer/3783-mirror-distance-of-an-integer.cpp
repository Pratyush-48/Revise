class Solution {
public:
    int mirrorDistance(int n) {
        int temp = n;
        int num = 0;
        while(n){
            int rem = n%10;
            num*=10;
            num += rem;
            n/=10;
        }
        return abs(num-temp);
    }
};