#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:

    // out of time, brute force
    // int subarraySum(vector<int>& nums, int k) {
    //     int count = 0;
    //     for(int i=0;i<nums.size();i++){
    //         for(int j=i;j<nums.size();j++){
    //             int sum = 0;
    //             for(int m=i;m<=j;m++){
    //                 sum += nums[m];
    //             }
    //             if(sum == k){
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }


    // prefix sum + hash table
    int subarraySum(vector<int>& nums, int k) {
        for(int i=1;i<nums.size();i++){
            nums[i] += nums[i-1];
        }
        int count = 0;
        unordered_map<int,int> prefix_sum_count;
        for(auto num:nums){
            if(num == k){
                count++;
            }
            count += prefix_sum_count.find(num-k) != prefix_sum_count.end() ? prefix_sum_count[num-k] : 0;
            prefix_sum_count[num]++;
        }
        return count;
    }

};