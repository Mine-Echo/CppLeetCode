#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:


    // int lengthOfLongestSubstring(string s) {
    //     int left=0;
    //     int right=0;
    //     int max_length=0;
    //     int length = 0;
    //     unordered_map<char,int> char_index_map; //字符，出现位置
    //     while(right<s.size()){
    //         auto it = char_index_map.find(s[right]);
    //         if(it != char_index_map.end()){
    //             length -= it->second - left +1;
    //             //清除hashtable中left到it->second的字符
    //             for(;left<it->second;left++){
    //                 char_index_map.erase(s[left]);
    //             }
    //             left++;
    //         }
    //         char_index_map[s[right]]=right;
    //         length++;
    //         //更新最大长度
    //         if(length>max_length){
    //             max_length=length;
    //         }
    //         right++;
    //     }
    //     return max_length;
    // }


    // 跳过重复字符
    // int lengthOfLongestSubstring(string s) {
    //     int left=0;
    //     int right=0;
    //     int max_length=0;
    //     int length = 0;
    //     unordered_map<char,int> char_index_map; //字符，出现位置
    //     while(right<s.size()){
    //         auto it = char_index_map.find(s[right]);
    //         if(it != char_index_map.end()&& it->second >= left){
    //             length -= it->second - left +1;
    //             left = it->second + 1; //直接跳过重复字符
    //         }
    //         char_index_map[s[right]]=right;
    //         max_length = max(max_length, right - left + 1);
    //         right++;
    //     }
    //     return max_length;
    // }


    //用数组代替hashtable，减少哈希表的开销
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int max_length=0;
        int length = 0;
        // unordered_map<char,int> char_index_map; //字符，出现位置
        int char_index_map[256]; //字符，出现位置
        std::fill(char_index_map, char_index_map + 256, -1);
        while(right<s.size()){
            if(char_index_map[s[right]]!=-1 && char_index_map[s[right]] >= left){
                length -= char_index_map[s[right]] - left +1;
                left = char_index_map[s[right]] + 1; //直接跳过重复字符
            }
            char_index_map[s[right]]=right;
            max_length = max(max_length, right - left + 1);
            right++;
        }
        return max_length;
    }


};

//测试
int main() {
    Solution solution;
    string s = "abcabcbb";
    int result = solution.lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;
    return 0;
}