class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    map<int,int>logs;
    int book(int startTime, int endTime) {
        logs[startTime]++;
        logs[endTime]--;
        int prev = 0;
        int result = 0;
        for (auto& [time, count] : logs) {
            result = max(result,prev+count);
            prev += count;
        }
        return result;
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */