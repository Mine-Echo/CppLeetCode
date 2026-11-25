#include <vector>
using namespace std;

class Solution {

    void permuteCore(vector<int>& res,vector<bool>& visited, vector<int>& nums, vector<vector<int>>& result){
        if(res.size()==nums.size()){
            result.push_back(res);
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]) continue;
            //未被访问
            visited[i]=true;
            res.push_back(nums[i]);
            permuteCore(res, visited, nums, result);
            visited[i]=false;
            res.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> res;
        vector<bool> visited(nums.size(),false);
        vector<vector<int>> result;
        permuteCore(res,visited,nums,result);
        return result;
    }
};