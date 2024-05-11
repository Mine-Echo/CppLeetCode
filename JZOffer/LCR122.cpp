#include<string>
using namespace std;

class Solution {
public:
    string pathEncryption(string path) {
        for(int i=0;i<path.size();i++){
            if(path[i]=='.'){
                path[i]=' ';
            }
        }
        return path;
    }
};