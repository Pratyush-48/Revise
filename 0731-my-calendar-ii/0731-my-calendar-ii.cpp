class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    map<int,int>log;
    bool book(int startTime, int endTime) {
        int prev = 0;
        log[startTime] += 1;
        log[endTime] -= 1;
        for(auto &it:log){
            if(prev+it.second > 2){
                log[startTime] -= 1;
                log[endTime] += 1;
                return false;
            }
            else{
                prev += it.second;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */