#include<vector>

using namespace std;


struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param preOrder int整型vector
     * @param vinOrder int整型vector
     * @return TreeNode类
     */
    TreeNode *reConstructBinaryTree(vector<int> &preOrder, vector<int> &vinOrder)
    {
        // write code here
        if(preOrder.size()==0)
            return nullptr;
        TreeNode* node=new TreeNode(preOrder[0]);
        if(preOrder.size()==1)
            return node;
        for(int i=0;i<vinOrder.size();i++){
            if(vinOrder[i]==preOrder[0]){
                vector<int> pre_left(preOrder.begin()+1,preOrder.begin()+i+1);
                vector<int> vin_left(vinOrder.begin(),vinOrder.begin()+i);
                vector<int> pre_right(preOrder.begin()+i+1,preOrder.end());
                vector<int> vin_right(vinOrder.begin()+i+1,vinOrder.end());
                node->left=reConstructBinaryTree(pre_left,vin_left);
                node->right=reConstructBinaryTree(pre_right,vin_right);
                break;
            }
        }
        return node;
    }
};