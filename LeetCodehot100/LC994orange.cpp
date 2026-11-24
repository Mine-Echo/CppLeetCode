#include <vector>
#include <queue>
using namespace std;

class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int count=0;
        while(fresh!=0&&!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto index=q.front();
                int x=index.first,y=index.second;
                q.pop();
                //上下左右
                if(x>0&&grid[x-1][y]==1){
                    grid[x-1][y] = 2;
                    q.push({x-1,y});
                    fresh--;
                }
                if(y>0&&grid[x][y-1]==1){
                    grid[x][y-1] = 2;
                    q.push({x,y-1});
                    fresh--;
                }
                if(x<grid.size()-1&&grid[x+1][y]==1){
                    grid[x+1][y] = 2;
                    q.push({x+1,y});
                    fresh--;
                }
                if(y<grid[0].size()-1&&grid[x][y+1]==1){
                    grid[x][y+1] = 2;
                    q.push({x,y+1});
                    fresh--;
                }
            }
            count++;
        }
        if(fresh) return -1;
        return count;
    }
};