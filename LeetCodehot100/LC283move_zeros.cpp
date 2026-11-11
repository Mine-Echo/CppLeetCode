#include <vector>
using namespace std;

class Solution {
public:
    // void moveZeroes(vector<int>& nums) {
    //     int head,tail;
    //     //tail起始位置
    //     for(tail=nums.size()-1;tail>=0;tail--){
    //         if(nums[tail]!=0){
    //             break;
    //         }
    //     }
    //     if(tail<0){
    //         return;
    //     }
    //     for(head=tail-1;head>=0;head--){
    //         if(nums[head]==0){ //head,tail
    //             for(int i=head;i<tail;i++){
    //                 nums[i]=nums[i+1];
    //             }
    //             nums[tail]=0;
    //             tail--;
    //         }
    //     }
    // }


    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for(int num:nums){
            if(num){
                nums[index++] = num;
            }
        }
        for(int i=index;i<nums.size();i++){
            nums[i] = 0;
        }
    }
};