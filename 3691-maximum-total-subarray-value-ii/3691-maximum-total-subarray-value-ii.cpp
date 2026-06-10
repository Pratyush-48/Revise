class Solution {
public:
    typedef long long ll;
    vector<ll> maxi;
    vector<ll> mini;

    void build(vector<int>& nums, int idx, int l, int r) {
        if (l == r) {
            maxi[idx] = nums[l];
            mini[idx] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(nums, 2 * idx + 1, l, mid);
        build(nums, 2 * idx + 2, mid + 1, r);
        maxi[idx] = max(maxi[2 * idx + 1], maxi[2 * idx + 2]);
        mini[idx] = min(mini[2 * idx + 1], mini[2 * idx + 2]);
    }

    ll query_max(int idx, int l, int r, int start, int end) {
        if (l > end || r < start) return LLONG_MIN; 
        if (l >= start && r <= end) return maxi[idx];
        
        int mid = l + (r - l) / 2;
        return max(query_max(2 * idx + 1, l, mid, start, end),
                   query_max(2 * idx + 2, mid + 1, r, start, end));
    }

    ll query_min(int idx, int l, int r, int start, int end) {
        if (l > end || r < start) return LLONG_MAX;
        if (l >= start && r <= end) return mini[idx];
        
        int mid = l + (r - l) / 2;
        return min(query_min(2 * idx + 1, l, mid, start, end),
                   query_min(2 * idx + 2, mid + 1, r, start, end));
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return 0;

        maxi.assign(4 * n, 0);
        mini.assign(4 * n, 0);
        build(nums, 0, 0, n - 1);

        priority_queue<tuple<ll, int, int>> pq;
        long long result = 0;

        for (int i = 0; i < n - 1; i++) {
            ll val = query_max(0, 0, n - 1, i, n - 1) - query_min(0, 0, n - 1, i, n - 1);
            pq.push({val, i, n - 1});
        }

        while (!pq.empty() && k > 0) {
            auto [score, i, j] = pq.top();
            pq.pop();

            result += score;
            k--;

            if (j - 1 > i) {
                ll next_val = query_max(0, 0, n - 1, i, j - 1) - query_min(0, 0, n - 1, i, j - 1);
                pq.push({next_val, i, j - 1});
            }
        }

        return result;
    }
};