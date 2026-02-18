class Solution {
public:
    bool hasAlternatingBits(int n) {
        int num = n;
        int prev = -1;
        while(num>0){
            int curr = num%2;
            //cout<<curr<<" "<<prev<<endl;
            if(curr==prev) return false;
            prev = curr;
            num /= 2;
        }
        return true;
    }
};