//二叉搜索树的后序遍历序列
#include<vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(!sequence.size())
            return false;
        return check(sequence,0,sequence.size());
    }
    bool check(vector<int> sequence, int start, int end) {
        if (start>=end)
            return true;
        //最后一个元素是根节点
        int root=sequence[end - 1];
        //前面的元素能分为左子树和右子树
        int split=start;
        while(sequence[split] < root){
            split++;
        }
        //判断是否符合搜索二叉树的大小关系
        for(int i=split;i<end-1;i++){
            if(sequence[i]<root)
                return false;
        }
        //递归判断
        return check(sequence,start,split)&&check(sequence,split,end-1);
    }
};

int main(){
    vector<int> v={1};
    (new Solution())->VerifySquenceOfBST(v);
    return 0;
}