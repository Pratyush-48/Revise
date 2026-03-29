class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1==s2) return true;
        // 1,3
        swap(s1[0],s1[2]);
        if(s1==s2) return true;
        swap(s1[0],s1[2]);
        // 2,4
        swap(s1[1],s1[3]);
        if(s1==s2)return true;
        swap(s1[0],s1[2]);
        //1,3 + 2,4
        return s1==s2;
    }
};