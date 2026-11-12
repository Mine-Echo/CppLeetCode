#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        vector<int> current_interval = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(current_interval[1]>=intervals[i][0]){
                current_interval[1] = max(current_interval[1], intervals[i][1]);
            }else{
                merged.push_back(current_interval);
                current_interval = intervals[i];
            }
        }
        merged.push_back(current_interval);
        return merged;
    }

    // 这个不用写，vector默认是按第一个元素升序排序的
    // static bool compare(const vector<int>& a, const vector<int>& b) {
    //     if(a[0]<b[0]){
    //         return true;
    //     }else if(a[0]==b[0]){
    //         return a[1]<b[1];
    //     }else{
    //         return false;
    //     }
    // }


};