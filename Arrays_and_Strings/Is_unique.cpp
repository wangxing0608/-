//
// Created by wangxing on 19-6-16.
//


// 1.1 检测给定字符串是否存在重复的字符
// 假设组组成字符串的字符为ASCII码中128种字符集组成

#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm> // for sort()

using namespace std;

//使用bool表示字符集
bool isUniqueChars(const string &str){
    //如果待检测字符串长度超过128,则该待检测字符串一定包含重复字符
    if (str.length() > 128) {
        return false;
    }
    vector<bool> char_set(128);    // 创建bool类型的vector容器类保存该字符是否出现在待检测字符串中
    //顺序检测str中的每一个字符是否已经出现
    for (int i =0;i<str.length();i++) {
       int val = str[i];  //取出当前位置的字符
       if (char_set[val]) {
           //如果当前位置的字符已经在字符串中出现
           return false;
       }
       char_set[val] = true;    // 当前位置尚未在字符表char_set中出现
    }
    return true;
}

//使用bitset表示字符集
bool isUniqueChars_bitvector(const string &str) {
    //使用bitset表示字符集中的每一个字符
    bitset<256> bits(0);    //创建表示字符集的bitset变量
    for (int i = 0; i < str.length(); i++) {
        int val = str[i];
        if (bits.test(val) > 0) {
            return false;
        }
        bits.set(val);
    }
    return true;
}

//
bool isUniqueChars_noDS(string str) {
    sort(str.begin(), str.end());  //对字符串中的字符进行排序
    bool noRepeat = true;
    for (int i=0;i<str.size()-1;i++) {
        if (str[i] == str[i+1]) {
            noRepeat = false;
            break;
        }
    }
    return noRepeat;
}

int main(){
    vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
    for (auto word: words) {
        cout << word << string(": ") << boolalpha << isUniqueChars(word) <<endl;
    }
    cout <<endl << "Using bit vector" <<endl;
    for (auto word : words)
    {
        cout << word << string(": ") << boolalpha << isUniqueChars_bitvector(word) <<endl;
    }
    cout <<endl << "Using no Data Structures" <<endl;
    for (auto word : words)
    {
        cout << word << string(": ") << boolalpha << isUniqueChars_noDS(word) <<endl;
    }
    return 0;
}
