#include <vector>
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
    TreeNode* sortedArrayToBSTCore(vector<int>& nums, int begin, int end){
        if(begin == end) return nullptr;
        int mid = (begin+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTCore(nums, begin, mid);
        root->right = sortedArrayToBSTCore(nums, mid+1, end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTCore(nums, 0, nums.size());
    }
};