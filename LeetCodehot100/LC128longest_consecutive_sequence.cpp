#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // O(nlogn) solution
    // int longestConsecutive(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     int longest = 0;
    //     int current_length;
    //     for (int i = 0; i < nums.size(); i++) {
    //         current_length = 1;
    //         while (i + 1 < nums.size() && ((nums[i + 1] == nums[i] + 1)||(nums[i + 1] == nums[i]))) {
    //             if (nums[i + 1] == nums[i] + 1) {
    //                 current_length++;
    //             }
    //             i++;
    //         }
    //         longest = max(longest, current_length);
    //     }
    //     return longest;
    // }



    // O(n) solution
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longest = 0;
        // 找序列的起点
        for(auto num:num_set){
            if(num_set.find(num-1)!=num_set.end()){
                continue;
            }
            int current_length = 1;
            while(num_set.find(num+1)!=num_set.end()){
                num++;
                current_length++;
            }
            longest = max(longest, current_length);
        }
        return longest;
    }
};