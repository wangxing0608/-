//
// Created by wangxing on 19-6-17.
//

//1.2 给定两个字符串是否互为排列（构成字符串的字符一样,排列顺序不同）
//假定区分字符串中的大小写和并且不忽略空格
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

//对两个字符串进行排序,再依次比较各个位置的字符是否相等
bool arePermutation(string str1, string str2){
    // 两个长度不等的字符串肯定不构成排列
    int n1 = str1.length();
    int n2 = str2.length();
    if (n1 != n2)
        return false;

    //对两个字符串中的字符排列,再依次比较各个字符是否相等
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    //比较排序后的两个字符串
    for (int i=0;i<str1.length();i++) {
        if (str1[i] != str2[i])   //存在不相等的字符
            return false;
    }
    return true;
}

//使用排列的定义,遍历两个字符串,使用数组统计各个字符串中每个字符出现的次数
//再比较两个数组,如果相等，则为互为排列
bool arePermutation2(const string &str1, const string &str2) {
    if (str1.length() != str2.length())
        return false;
    int count[256] = {0};
    for (int i=0;i<str1.length();i++) {
        int val = str1[i];
        count[val]++;
    }
    for (int i=0;i<str2.length();i++) {
        int val = str2[i];
        count[val]--;
        if (count[val]<0)
            return false;
    }
    return true;
}

int main(){
    //测试方法1
    cout<<"方法1 - 使用排序"<<endl;
    string str1 = "testest";
    string str2 = "extxest";
    if (arePermutation(str1, str2))
        cout<<str1<<"和"<<str2<<"互为排列"<<endl;
    else
        cout<<str1<<"和"<<str2<<"不互为排列"<<endl;
    str1 = "hello";
    str2 = "oellh";
    if (arePermutation(str1, str2))
        cout<<str1<<"和"<<str2<<"互为排列"<<endl;
    else
        cout<<str1<<"和"<<str2<<"不互为排列"<<endl;
    //测试方法2
    cout<<"方法2 - 使用字符计数"<<endl;
    str1 = "testest";
    str2 = "extxest";
    if (arePermutation2(str1, str2))
        cout<<str1<<"和"<<str2<<"互为排列"<<endl;
    else
        cout<<str1<<"和"<<str2<<"不互为排列"<<endl;
    str1 = "hello";
    str2 = "oellh";
    if (arePermutation2(str1, str2))
        cout<<str1<<"和"<<str2<<"互为排列"<<endl;
    else
        cout<<str1<<"和"<<str2<<"不互为排列"<<endl;
    return 0;
}