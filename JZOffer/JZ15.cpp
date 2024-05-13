//二进制中1的数量

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    int NumberOf1(int n) {
        // write code here
        //C++中>>对有符号数操作默认算数右移，会保留符号（最左边补1）
        //所以先转为unsigned int
        int count=0;
        unsigned int temp=(unsigned int)n;
        while(temp!=0){
            if((temp&1)>0)
                count++;
            temp=temp>>1;
        }
        return count;
    }
};

int main(){
    Solution solution;
    solution.NumberOf1(-1);
}