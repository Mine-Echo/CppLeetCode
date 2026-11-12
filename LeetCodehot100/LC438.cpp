#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:

    // out of time, sort the substring and compare with p
    // vector<int> findAnagrams(string s, string p) {
    //     if(s.size()<p.size()) return {};
    //     sort(p.begin(), p.end());
    //     vector<int> result;
    //     int p_length = p.size();
    //     for(int i=0;i<s.size()-p_length+1;i++){
    //         string sub_str = s.substr(i, p_length);
    //         sort(sub_str.begin(), sub_str.end());
    //         if(sub_str == p){
    //             result.push_back(i);
    //         }
    //     }
    //     return result;
    // }



    // hash table && sliding window
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size()) return {};
        int p_count[26] = {0};
        for(int i=0;i<p.size();i++){
            p_count[p[i]-'a']++;
        }
        for(int i=0;i<p.size();i++){
            p_count[s[i]-'a']--;
        }
        vector<int> result;
        if(is_anagram(p_count)){
            result.push_back(0);
        }
        for(int i=1;i<s.size()-p.size()+1;i++){
            int end = i+p.size();
            p_count[s[i-1]-'a']++;
            p_count[s[end-1]-'a']--;
            if(is_anagram(p_count)){
                result.push_back(i);
            }
        }
        return result;
    }

    bool is_anagram(int p_count[26]){
        for(int i=0;i<26;i++){
            if(p_count[i]!=0){
                return false;
            }
        }
        return true;
    }
};