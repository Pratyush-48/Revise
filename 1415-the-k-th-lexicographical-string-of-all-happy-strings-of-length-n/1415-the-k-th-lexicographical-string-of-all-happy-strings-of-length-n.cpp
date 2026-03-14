class Solution {
public:
void fi(int n, int idx,int k,int &j,string temp,string &result){
    if(idx>=n){
        if(temp.size()==n)j++;
        if(j==k){
            result=temp;
        }
        return;
    }
    for(int i=0;i<3;i++){
        if(!temp.empty() && temp.back()==(i+'a')) continue;
        temp.push_back(i+'a');
        fi(n,idx+1,k,j,temp,result);
        temp.pop_back();
    }
}
    string getHappyString(int n, int k) {
        string result = "";
        string temp ="";
        int j = 0;
        fi(n,0,k,j,temp,result);
        return result;
    }
};