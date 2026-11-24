#include <vector>
using namespace std;

class Solution {
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
        if(grid[i][j]=='0'||visited[i][j]) return; //水域或已访问过
        visited[i][j]=true;
        if(i>0) dfs(grid, visited, i-1, j); //上
        if(i<grid.size()-1) dfs(grid, visited, i+1, j); //下
        if(j>0) dfs(grid, visited, i, j-1); //左
        if(j<grid[0].size()-1) dfs(grid, visited, i, j+1); //右
        return ;
    }
public:

    int numIslands(vector<vector<char>>& grid) {
        // vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        vector<vector<bool>> visited(grid.size());
        for (auto& row : visited) {
            row.resize(grid[0].size());
        }
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'&&!visited[i][j]){ //未被访问过的陆地
                    dfs(grid, visited, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};