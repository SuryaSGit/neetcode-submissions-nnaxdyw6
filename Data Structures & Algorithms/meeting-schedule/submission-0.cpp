/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),
        [](auto& a, auto& b){
            return a.end < b.end;
        });
        int cur_interval_end = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start < cur_interval_end){
                return false;
            }
            cur_interval_end = intervals[i].end;
        }
        return true;
    }
};
