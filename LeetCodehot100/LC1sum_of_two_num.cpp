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


    // O(n) solution哈希表
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

    // O(nlogn) solution排序+双指针
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<pair<int, int>> num_with_index;
    //     for (int i = 0; i < nums.size(); i++) {
    //         num_with_index.push_back({nums[i], i});
    //     }
    //     sort(num_with_index.begin(), num_with_index.end());
    //     int left = 0;
    //     int right = nums.size() - 1;
    //     while (left<right){
    //         int sum = num_with_index[left].first + num_with_index[right].first;
    //         if (sum == target) {
    //             return {num_with_index[left].second, num_with_index[right].second};
    //         } else if (sum < target) {
    //             left++;
    //         } else {
    //             right--;
    //         }
    //     }
    //     return {};
    // }

};