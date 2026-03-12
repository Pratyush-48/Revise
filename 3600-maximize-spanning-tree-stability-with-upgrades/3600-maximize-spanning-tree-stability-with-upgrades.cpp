class Solution {
public:
    int find_p(int u,vector<int>&parent){
        if(parent[u]==u) return u;
        return parent[u] = find_p(parent[u],parent);
    }
    bool union_by_size(int u,int v,vector<int>&parent,vector<int>&size){
        int u_p = find_p(u,parent);
        int v_p = find_p(v,parent);
        if(u_p==v_p) return true;
        if(size[u_p]>size[v_p]){
            parent[v_p] = u_p;
            size[u_p] += size[v_p];
        }
        else{
            parent[u_p] = v_p;
            size[v_p] += size[u_p];
        }
        return false;
    }
    bool check(vector<vector<int>>& edges,int mid,int k,int n){
        vector<int>parent(n);
        vector<int>size(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        int res = 0;
        vector<vector<int>>candidates;
        for(auto &it:edges){
            if(it[3]==1){
                if(it[2]<mid) return false;
                bool f = union_by_size(it[0],it[1],parent,size);
                if(f) return false;
                res = max(res,it[2]);
            }
            else{
                if(it[2]>=mid){
                    bool f = union_by_size(it[0],it[1],parent,size);
                    if(!f){
                        res = max(res,it[2]);
                    }
                }
                else
               candidates.push_back(it);
            }
        }
        for(auto &it:candidates){
            int u_p = find_p(it[0],parent);
            int v_p = find_p(it[1],parent);
            if(u_p == v_p) continue;
            if(mid<=it[2]){
                res = max(res,it[2]);
                union_by_size(it[0],it[1],parent,size);
            }
            else{
            if(k<=0) continue;
            if(2*it[2] < mid) continue;
             k--;
            union_by_size(it[0],it[1],parent,size);
            res = max(res,2*it[2]);
             }
        }
        int p_0 = find_p(0,parent);
        for(int i=0;i<n;i++){
            int p_i = find_p(i,parent);
            if(p_i != p_0) return false;
        }
        return res>=mid;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>&b){
            return a[3]>b[3];
        });
        int left = 1;
        int right = 2*(1e5);
        int result = -1;
        while(left<=right){
            int mid = (left+right)/2;
            if(check(edges,mid,k,n)){
                result = mid;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return result;

    }
};