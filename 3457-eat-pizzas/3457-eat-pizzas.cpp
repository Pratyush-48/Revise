class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int n = pizzas.size();
        sort(pizzas.begin(), pizzas.end());
        
        int total_days = n / 4;
        int odd_days = (total_days + 1) / 2;
        int even_days = total_days - odd_days;
        
        long long result = 0;
        int right = n - 1; 
        
        for (int i = 0; i < odd_days; i++) {
            result += pizzas[right];
            right--;
        }
        
        for (int i = 0; i < even_days; i++) {
            right--; 
            result += pizzas[right]; 
            right--; 
        }
        
        return result;
    }
};