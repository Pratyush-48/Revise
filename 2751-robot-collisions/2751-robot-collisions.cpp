class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,int>>result;
        vector<pair<int,pair<int,int>>>store;
        unordered_map<int,int>idx;
        int n = positions.size();
        for(int i=0;i<n;i++){
            idx[positions[i]] = i;
        }
        for(int i=0;i<n;i++){
            store.push_back({positions[i],{healths[i],directions[i]=='L'?-1:1}});
        }
        sort(store.begin(),store.end());
        stack<pair<int,int>>st;
        int i = 0;
        while(i<n){
            int pos = store[i].first;
            int h = store[i].second.first;
            int dir = store[i].second.second;

            if(dir==-1){
                if(st.empty()){
                    result.push_back({idx[pos],h});
                    i++;
                }
                else if(st.top().second==h){
                    st.pop();
                    i++;
                }
                else if(st.top().second>h){
                    st.top().second-=1;
                    i++;
                }
                else{
                    while(!st.empty() && st.top().second<h){
                        st.pop();
                        h--;
                        store[i].second.first = h;
                    }
                }
            }
            else if(dir==1){
                st.push({idx[pos],h});
                i++;
            }
        }
        
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        if(result.empty()) return {};
        vector<int>ans;
        sort(result.begin(),result.end());
        for(int i=0;i<result.size();i++){
            ans.push_back(result[i].second);
        }
        return ans;
    }
};