class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int>result(n,0);
        stack<int>st;
        st.push(heights[n-1]);
        for(int i=n-2;i>=0;i--){
            int visible = 0;
            while(!st.empty() && st.top()<heights[i]){
                visible++;
                st.pop();
            }
            if(!st.empty()){
                visible++;
            }
            result[i] = visible;
            st.push(heights[i]);
        }
        return result;
    }
};