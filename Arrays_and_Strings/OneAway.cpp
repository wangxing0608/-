//
// Created by wangxing on 19-7-1.
//

// 1.5 判断两个字符串是否小于等于一个编辑距离
// 插入一个字符,移除一个字符,替代一个字符两个字符串相等.即为一个编辑距离


#include <string.h>
#include <iostream>

using namespace std;


bool isOneAway(string s1, string s2){
    string a, b;
    a = s1.length() >= s2.length() ? s1 : s2;   // a为两个字符串中较长的
    b = s1.length() < s2.length() ? s1 : s2;    // b为两个字符串中较短的
    int len1, len2;
    len1 = a.length();   // 较长的字符串长度
    len2 = b.length();   // 较短的字符串长度
    // 两个字符串的长度差大于1则一定不是one edit away
    if(abs(len1-len2) > 1)
        return false;

    bool flag = false;
    for(int i = 0,j=0; i<len1 && j<len2;){
        // 找到第一处不相等字符
        if (a[i] != b[j]) {
            //不是两个字符串的第一处不同,则编辑距离一定大于1
            if(flag)
                return false;
            flag = true;   // 标志设为true,表示已经找到一处替代操作
            if(len1==len2){
                i++;
                j++;
            }
            else
                i++;      // 较长字符串向前移动一个字符继续比较
        }
        else
            i++,j++;      // 该处字符相等,向前移动
    }
    return true;
}

int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    if(isOneAway(s1, s2))
        cout<<"One edit away."<<endl;
    else
        cout<<"Not one edit away."<<endl;
    return 0;
}
