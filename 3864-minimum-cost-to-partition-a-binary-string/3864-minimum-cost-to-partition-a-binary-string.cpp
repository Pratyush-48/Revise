class Solution {
public:
    long long recc(int l,int r,vector<int>&p,long long e,long long f){
        long long len = r-l+1;
        long long x = p[r+1]-p[l];
        long long b = (x==0)?f:len*x*e;
        if(len%2 != 0) return b;
        int m = (l+r)/2;
        return min(b,recc(l,m,p,e,f)+recc(m+1,r,p,e,f));
    }
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.length();
        vector<int>p(n+1,0);
        for(int i=0;i<n;i++){
            p[i+1] = p[i]+(s[i]=='1');
        }
        return recc(0,n-1,p,encCost,flatCost);
    }
};