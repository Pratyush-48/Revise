class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int n = asteroids.size();
        long long Mass = mass;
        for(int i=0;i<n;i++){
            if(Mass>=asteroids[i]){
                Mass += (long long)asteroids[i];
            }
            else return false;
        }
        return true;
    }
};