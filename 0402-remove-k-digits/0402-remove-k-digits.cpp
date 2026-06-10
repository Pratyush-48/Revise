class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        deque<int>dq;
        for(int i=0;i<n;i++){
            int m = num[i]-'0';
            while(!dq.empty() && dq.back()>m && k>0){
                dq.pop_back();
                k--;
            }
            dq.push_back(m);
        }
        while(!dq.empty() && k>0){
            dq.pop_back();
            k--;
        }
        while(!dq.empty() && dq.front()==0) dq.pop_front();
        if(dq.empty()) return "0";
        string result = "";
        while(!dq.empty()){
            int m = dq.front();
            result += (m+'0');
            dq.pop_front();
        }
        return result;
    }
};