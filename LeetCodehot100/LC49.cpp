#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // out of time
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     vector<bool> visited(strs.size(), false);
    //     vector<vector<string>> result;
    //     for (int i = 0; i < strs.size(); i++) {
    //         if(visited[i]) continue;
    //         visited[i] = true;
    //         vector<string> group;
    //         group.push_back(strs[i]);
    //         for (int j = i + 1; j < strs.size(); j++) {
    //             if (!visited[j] && is_ywc(strs[i], strs[j])) {
    //                 visited[j] = true;
    //                 group.push_back(strs[j]);
    //             }
    //         }
    //         result.push_back(group);
    //     }
    //     return result;
    // }

    // bool is_ywc(string& s1, string& s2){
    //     if (s1.size() != s2.size()) return false;
    //     unordered_map<char, int> char_count;
    //     for (char c : s1) {
    //         char_count[c]++;
    //     }
    //     for (char c : s2) {
    //         if (char_count.find(c) == char_count.end() || char_count[c] == 0) {
    //             return false;
    //         }
    //         char_count[c]--;
    //     }
    //     return true;
    // }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_map;
        for (auto& str:strs){
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            anagram_map[sorted_str].push_back(str);
        }
        vector<vector<string>> result;
        for (auto& pair: anagram_map) {
            result.push_back(pair.second);
        }
        return result;
    }
};