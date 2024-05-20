#include<vector>

using namespace std;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if (matrix.size()==0)
            return vector<int>();
        int row1=0,row2=matrix.size()-1,col2=matrix[0].size()-1,col1 = 0;
        vector<int> arrayList;
        while(true){
            int i,j;
            for(i=row1,j=col1;j<=col2;j++){
                arrayList.push_back(matrix[i][j]);
            }
            ++row1;
            if(row1>row2||col1>col2)
                break;
            for(j=col2,i=row1;i<=row2;i++){
                arrayList.push_back(matrix[i][j]);
            }
            --col2;
            if(row1>row2||col1>col2)
                break;
            for(i=row2,j=col2;j>=col1;j--){
                arrayList.push_back(matrix[i][j]);
            }
            --row2;
            if(row1>row2||col1>col2)
                break;
            for(j=col1,i=row2;i>=row1;i--){
                arrayList.push_back(matrix[i][j]);
            }
            col1++;
            if(row1>row2||col1>col2)
                break;
        }
        return arrayList;
    }
};