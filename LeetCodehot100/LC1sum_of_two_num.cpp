#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // O(n^2) solution
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     for(int i=0;i<nums.size();i++){
    //         for(int j=i+1;j<nums.size();j++){
    //             if(nums[i]+nums[j]==target){
    //                 return {i,j};
    //             }
    //         }
    //     }
    //     return {};
    // }

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;
        for (int i=0;i<nums.size();i++) {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end() && num_map[complement] != i) {
                return {i, num_map[complement]};
            }
            num_map[nums[i]] = i;
        }
        return {};
    }
};