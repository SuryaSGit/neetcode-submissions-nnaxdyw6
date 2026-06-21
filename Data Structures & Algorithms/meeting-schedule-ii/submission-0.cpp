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
    int minMeetingRooms(vector<Interval>& intervals) {
        int max_interval_end = 0;
        for(int i = 0; i < intervals.size(); i++){
            max_interval_end = max(intervals[i].end, max_interval_end);
        }
        vector<int> times(max_interval_end + 1);
        for(int i = 0; i < intervals.size(); i++){
            times[intervals[i].start]++;
            times[intervals[i].end]--;
        }
        int max_concurrent = 0;
        int cur_con = 0;
        for(int i = 0; i < times.size(); i++){
            cur_con = cur_con + times[i];
            max_concurrent = max(max_concurrent, cur_con);
        }
        return max_concurrent;
    }
};
