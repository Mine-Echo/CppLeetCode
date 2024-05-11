#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //从右上角往左/下搜索
        int i=0,j=matrix[0].size()-1;
        while(i<matrix.size()&&j>=0){
            if(matrix[i][j]<target)
                i++;
            else if(matrix[i][j]>target)
                j--;
            else
                return true;
        }
        return false;
    }
};