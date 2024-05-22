#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pushV int整型vector 
     * @param popV int整型vector 
     * @return bool布尔型
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        // write code here
        stack<int> s;
        int j=0;
        for(int i=0;i<pushV.size();i++){
            s.push(pushV[i]);
            while(j<popV.size()&&!s.empty()&&popV[j]==s.top()){
                s.pop();
                ++j;
            }
        }
        return s.empty();
    }
};