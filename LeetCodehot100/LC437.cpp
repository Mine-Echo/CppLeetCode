#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

    void dfs(TreeNode* root, int targetSum, unordered_map<long,int>& prefix_sum_count, int& count, long sum){
        if(!root) return ;
        sum+= root->val;
        if(sum == targetSum) count++;
        count += prefix_sum_count.find(sum-targetSum) != prefix_sum_count.end() ? prefix_sum_count[sum-targetSum] : 0;
        prefix_sum_count[sum]++;
        dfs(root->left, targetSum, prefix_sum_count, count, sum);
        dfs(root->right, targetSum, prefix_sum_count, count, sum);
        prefix_sum_count[sum]--; //恢复
    }


public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long,int> prefix_sum_count;
        int count = 0;
        dfs(root, targetSum, prefix_sum_count, count, 0);
        return count;
    }
};