class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param number int整型 
     * @return int整型
     */
    int jumpFloorII(int number) {
        // write code here
        //实际上就是2*jumpFloorII(number-1);
        // if(number ==1)
        //     return 1;
        // return 2*jumpFloorII(number-1);
        //再简化
        return 1<<(number-1);
    }
};