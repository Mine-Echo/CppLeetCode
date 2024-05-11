class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param number int整型 
     * @return int整型
     */
    int jumpFloor(int number) {
        // write code here
        // 动态规划，直接从写的java改过来（建议把int数组换成vector）
        if(number==1)
        return 1;
        if(number==2)
        return 2;
        int* dp = new int[number + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= number; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        int ret=dp[number];
        delete[] dp;
        return ret;
    }
};