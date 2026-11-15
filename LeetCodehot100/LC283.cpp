#include <vector>
using namespace std;

class Solution {
public:

    // O(n) solution, use div
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     int product = 1;
    //     int zero_count = 0;
    //     for (int num : nums) {
    //         if (num == 0) {
    //             zero_count++;
    //         } else {
    //             product *= num;
    //         }
    //     }
    //     vector<int> result(nums.size(), 0);
    //     if (zero_count > 1)
    //         return result;
    //     for (int i = 0; i < nums.size(); i++) {
    //         if(nums[i]==0){
    //             result[i] = product;
    //         }else if(zero_count==0){
    //             result[i] = product / nums[i];
    //         }
    //     }
    //     return result;
    // }

    // O(n) solution, without div, pre and post product
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     vector<int> pre(nums.size(),1);
    //     for(int i=1;i<nums.size();i++){
    //         pre[i] = pre[i-1] * nums[i-1];
    //     }
    //     vector<int> post(nums.size(),1);
    //     vector<int> result(nums.size());
    //     for(int i=nums.size()-2;i>=0;i--){
    //         post[i] = post[i+1] * nums[i+1];
    //         result[i] = pre[i] * post[i];
    //     }
    //     result[nums.size()-1] = pre[nums.size()-1] * post[nums.size()-1];
    //     return result;
    // }

    // O(1) space solution, without div
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            result[i] = result[i-1] * nums[i-1];
        }
        int tmp=1;
        for(int i=nums.size()-1;i>=0;i--){
            result[i] = result[i] * tmp;
            tmp*=nums[i];
        }
        return result;
    }
};