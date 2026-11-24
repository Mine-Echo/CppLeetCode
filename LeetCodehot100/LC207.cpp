#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> neighbors(numCourses);
        for(auto prerequisite:prerequisites){
            neighbors[prerequisite[1]].push_back(prerequisite[0]);
            inDegree[prerequisite[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(!inDegree[i]) q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            count++;
            for(auto neighbor:neighbors[course]){
                inDegree[neighbor]--;
                if(!inDegree[neighbor]) q.push(neighbor);
            }
        }
        return count==numCourses;
    }
};