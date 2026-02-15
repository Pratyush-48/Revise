class Solution {
public:
    void rev(string&a){
        int start = 0;
        int end = a.size()-1;
        while(start<end){
            swap(a[start],a[end]);
            start++;
            end--;
        }
    }
    string addBinary(string a, string b) {
        // we will reverse and then add 
        string ans = "";
        rev(a);
        rev(b);
        int n = a.size();
        int m = b.size();
        int carry = 0;
        int i = 0;
        int j = 0;
        while(i<n && j<m){
            int sum = ((a[i]-'0')+(b[j]-'0'))+carry;
             carry = (sum/2);
            sum=(sum%2);
            char ch = sum+'0';
            ans.push_back(ch);
            i++;
            j++;
        }
        while(i<n){
            int sum = (a[i]-'0')+carry;
             carry = (sum/2);
            sum=(sum%2);
             char ch = sum+'0';
            ans.push_back(ch);
            i++;
        }
        while(j<m){
            int sum = ((b[j]-'0'))+carry;
             carry = (sum/2);
            sum=(sum%2);
             char ch = sum+'0';
            ans.push_back(ch);
            j++;
        }
        if(carry){
            ans.push_back('1');
        }
        rev(ans);
        return ans;
    }
};