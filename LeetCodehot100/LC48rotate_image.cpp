#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size()/2+1;i++){
            for(int j=i;j<matrix[0].size()-i-1;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[matrix.size()-1-j][i];
                matrix[matrix.size()-1-j][i] = matrix[matrix.size()-1-i][matrix[0].size()-1-j];
                matrix[matrix.size()-1-i][matrix[0].size()-1-j] = matrix[j][matrix[0].size()-1-i];
                matrix[j][matrix[0].size()-1-i] = tmp;
            }
        }
    }
};