#include <vector>
using namespace std;

class Solution {
    void subsetsCore(int turn, vector<int>& res, vector<int>& nums, vector<vector<int>>& result){
        if(turn==nums.size()){
            result.push_back(res);
            return ;
        }
        // 加入集合
        res.push_back(nums[turn]);
        subsetsCore(turn+1,res,nums,result);
        res.pop_back();
        // 不加入集合
        subsetsCore(turn+1,res,nums,result);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> res;
        subsetsCore(0, res, nums, result);
        return result;
    }
};