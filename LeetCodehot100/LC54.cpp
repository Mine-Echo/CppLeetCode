#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row_start=0,col_start=0,row_end=matrix.size()-1,col_end=matrix[0].size()-1;
        vector<int> result;
        while(row_start<=row_end&&col_start<=col_end){
            for(int j=col_start;j<=col_end;j++){
                result.push_back(matrix[row_start][j]);
            }
            row_start++;
            if(row_start>row_end) break;
            for(int i=row_start;i<=row_end;i++){
                result.push_back(matrix[i][col_end]);
            }
            col_end--;
            if(col_start>col_end) break;
            for(int j=col_end;j>=col_start;j--){
                result.push_back(matrix[row_end][j]);
            }
            row_end--;
            if(row_start>row_end) break;
            for(int i=row_end;i>=row_start;i--){
                result.push_back(matrix[i][col_start]);
            }
            col_start++;
        }
        return result;
    }
};


//测试
int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> result = s.spiralOrder(matrix);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}