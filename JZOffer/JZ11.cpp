#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int minNumberInRotatenums(vector<int> &nums)
    {
        // write code here
        //用low与mid判断很复杂
        int low = 0, high = nums.size() - 1;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] < nums[low])
                high = mid;
            else if (nums[mid] == nums[low] && nums[low] < nums[high])
                high--;
            else if (nums[mid] == nums[low] && nums[low] >= nums[high])
                low++;
            else if (nums[mid] > nums[low] && nums[low] < nums[high])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return nums[low];
        //而用high与mid判断就简单很多
        // int low = 0 ; int high = nums.size() - 1;
        // while(low < high){
        //     int mid = low + (high - low) / 2;
        //     if(nums[mid] > nums[high]){
        //         low = mid + 1;
        //     }else if(nums[mid] == nums[high]){
        //         high = high - 1;
        //     }else{
        //         high = mid;
        //     }
        // }
        // return nums[lows];
    }
};