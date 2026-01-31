class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char result = letters[0];
        int n = letters.size();
        int left = 0;
        int right = n-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(letters[mid]>target){
                result = letters[mid];
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return result;
    }
};