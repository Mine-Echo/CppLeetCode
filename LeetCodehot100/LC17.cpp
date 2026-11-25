#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {

public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mapping={
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        vector<vector<char>> result;
        for(int i =0;i<digits.size();i++){
            char number = digits[i];
            if(i==0){
                for(int j=0;j<mapping[number].size();j++){
                    result.push_back({mapping[number][j]});
                }
            }else{
                int n = result.size();
                int size=mapping[number].size();
                //先复制size-1份
                for(int j=0;j<size-1;j++){
                    for(int k=0;k<n;k++){
                        result.push_back(result[k]);
                    }
                }
                //然后添加
                for(int j=0;j<size;j++){
                    for(int k=0;k<n;k++){
                        result[j*n+k].push_back(mapping[number][j]);
                    }
                }
            }
        }
        //转化成vector<string>
        vector<string> res;
        for(auto v:result){
            res.push_back(string(v.begin(),v.end()));
        }
        return res;
    }
};