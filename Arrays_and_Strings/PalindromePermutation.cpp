//
// Created by wangxing on 19-6-21.
//

//1.4 判断输入字符串的任意字符排列是否为回文
//要满足字符串的排列为回文的条件,则该字符串中最多有一个字符的计数为奇数

#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

int getCharNumber(const char &c){
    int a = (int) 'a';
    int z = (int) 'z';
    int A = (int) 'A';
    int Z = (int) 'Z';
    int val = (int) c;
    if (a <= val && val <=z) {
        return val - 'a';
    }
    else if (A <= val && val <= Z) {
        return val - 'A';
    }
    return -1;
 }

 vector<int> buildCharFrequencyTable(string phrase){
    vector<int> table(getCharNumber('z') - getCharNumber('a') + 1, 0);   //  初始化int型的vector
    for (auto &c : phrase) {
        int x = getCharNumber(c);
        if (x!=-1) {
            table[x] ++;
        }
    }
    return table;
}

//字符串中最多有一个计数为奇数的字符
bool checkMaxOneOdd(vector<int> &table){
    bool foundOdd = false;
    for (auto count : table) {
        if (count %2 == 1){
            if (foundOdd) {
                return false;
            }
            foundOdd = true;
        }
    }
    return true;
}

bool isPermutationOfPalindrome(const string &phrase) {
    vector<int> table = buildCharFrequencyTable(phrase);
    return checkMaxOneOdd(table);
}

int main(){
    string pali = "Rats live on no evil star";
    string isPermutation = isPermutationOfPalindrome(pali) ? "yes" : "no";
    cout<<isPermutation<<endl;
    return 0;
}

































































