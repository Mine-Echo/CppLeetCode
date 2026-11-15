#include <vector>
using namespace std;


class Solution {
public:
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     for(int i=0;i<matrix.size();i++){
    //         if(matrix[i][0]<=target && matrix[i][matrix[0].size()-1]>=target){
    //             for(int j=0;j<matrix[0].size();j++){
    //                 if(matrix[i][j]==target){
    //                     return true;
    //                 }
    //             }
    //         }
    //     }
    //     return false;
    // }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = matrix.size() - 1, j = 0;
        while(i >= 0 && j < matrix[0].size())
        {
            if(matrix[i][j] > target) i--;
            else if(matrix[i][j] < target) j++;
            else return true;
        }
        return false;
    }

};