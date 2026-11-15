#include <vector>
using namespace std;




class Solution {
public:

    //O1 space
    void setZeroes(vector<vector<int>>& matrix) {
        int first_row = 1;
        int first_col = 1;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(!matrix[i][j]){
                    if(!i) first_row=0;
                    else matrix[i][0]=0;
                    if(!j) first_col=0;
                    else matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<matrix.size();i++){
            if(!matrix[i][0]){
                for(int j=1;j<matrix[0].size();j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=1;j<matrix[0].size();j++){
            if(!matrix[0][j]){
                for(int i=1;i<matrix.size();i++){
                    matrix[i][j]=0;
                }
            }
        }
        if(!first_row){
            for(int j=0;j<matrix[0].size();j++)
                matrix[0][j]=0;
        }
        if(!first_col){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0]=0;
            }
        }
    }

};