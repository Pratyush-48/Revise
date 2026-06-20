class Solution {
public:
    void func(vector<int>&lights,vector<int>&num){
        int n = lights.size();
        int count = 0;
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<n;i++){
            if(lights[i]!=0){
                count++;
                q.push(i+lights[i]);
            }
            while(!q.empty() && (q.top()<i)){
                q.pop();
                count--;
            }
            num[i] += count;
        }
    }
    void func2(vector<int>&lights,vector<int>&num){
        int n = lights.size();
        int count = 0;
        priority_queue<int>q;
        for(int i=n-1;i>=0;i--){
            if(lights[i]!=0){
                count++;
                q.push(i-lights[i]);
            }
            while(!q.empty() && (q.top()>i)){
                q.pop();
                count--;
            }
            num[i] += count;
        }
    }
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int>num(n,0);
        func(lights,num);
        func2(lights,num);
        queue<int>q;
        int i = 0;
        while(i<n){
            if(num[i]==0){
                int j = i;
                while(j<n && num[j]==0){
                    j++;
                }
                q.push(j-i);
                i = j-1;
            }
            i++;
        }
        int result = 0;
        while(!q.empty()){
            double num = q.front();
            cout<<num<<endl;
            result += ceil(num/3.0);
            q.pop();
        }
        return result;
    }
};