class Solution {
public:
    double angleClock(int hour, int minutes) {
        // each minute is equal to 360
        // each hour has 30 deg
        double h_angle = 30*hour;
        double min_angle = 6*minutes;
        double extra = ((double)30/(double)(1.0/((double)minutes/60.0)));
        h_angle += extra;
        double ans = abs(h_angle-min_angle);
        double ans2 = 360-ans;
        return min(ans,ans2);
    }
};