class Solution {
public:
    void permute(unordered_set<string>&fin,string &result,string &temp,int n){
        if(temp.size()==n){
            if(fin.find(temp)==fin.end()){
                result = temp;
            }
            return;
        }
        if(!result.empty()){
            return;
        }
        for(char ch='0';ch<='1';ch++){
            temp.push_back(ch);
            permute(fin,result,temp,n);
            temp.pop_back();
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string>fin;
        for(int i=0;i<nums.size();i++){
            fin.insert(nums[i]);
        }
        string result ="";
        string temp ="";
        permute(fin,result,temp,n);
        return result;
    }
};