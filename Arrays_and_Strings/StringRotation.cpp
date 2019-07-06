//
// Created by wangxing on 19-7-6.
//

// 1.9 字符串旋转, 有substring方法可以判断一个字符串是否为另一个字符串的方法
// 例: s1 = "waterbottle", s2 = "erbottlewat",则s2为s1的旋转后得到的字符串
// s1 = xy  ==> wat + erbottle,    s2 = yx  ==> erbottle + wat
// s1s1 = "waterbottlewaterbottle", s2为s1s1的子串
// 所以字符s2串为字符串s1的旋转的条件是： s2字符串是s1字符串与自己拼接后的字符串的子串

#include <iostream>
#include <string>

bool isStringRotation(std::string s1, std::string s2)
{
    size_t len1 = s1.length();    // s1长度
    size_t len2 = s2.length();    // s2长度
    if (len1 == 0 || len1 != len2)
    {
        // 如果s1字符串为空或两个字符串长度不相等,则返回false
        return false;
    }
    std::string concatS1 = s1 + s1;   // 拼接s1字符串
    if (concatS1.find(s2) != std::string::npos)
    {
        return true;      // s2为concatS1的子串
    } else {
        return false;     // 没有在concatS1中找到子串s2
    }
}

int main()
{
    std::string s1, s2;
    std::cout << "Enter string 1 : ";
    std::cin >> s1;
    std::cout << "Enter string 2 : ";
    std::cin >> s2;
    if (isStringRotation(s1, s2))
    {
        std::cout << "Yes! " << s2 << " is a rotation of " << s1 <<std::endl;
    } else {
        std::cout << "No! " << s2 << " is not a rotation of " << s1 <<std::endl;
    }
    return 0;
}