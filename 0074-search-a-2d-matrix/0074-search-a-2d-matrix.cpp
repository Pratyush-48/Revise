class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = m*n - 1;
        while(l<=r){
            int mid = (l+r)/2;
            int mid_r = mid/n;
            int mid_c = mid%n;
            if(matrix[mid_r][mid_c]==target) return true;
            else if(matrix[mid_r][mid_c]>target) r = mid-1;
            else l = mid+1;
        }
        return false;
    }
};