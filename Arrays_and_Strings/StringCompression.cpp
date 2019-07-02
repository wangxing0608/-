//
// Created by wangxing on 19-7-2.
//

// 1.6 字符串压缩表示:使用字符串计数值代替字符串中重复的字符实现字符串压缩
// 如果压缩后的字符串长度小于原始字符串,输出压缩后的字符串,否则输出原始字符串

#include <iostream>
#include <string>

std::string stringCompress(std::string str){
    size_t original_length = str.length();    // 原始字符串长度
    if (original_length < 2){
        return str;      // 原始字符串长度为1,直接输出
    }
    std::string out{""};   // 保存压缩字符串
    int count = 1;   // 字符计数器
    for(size_t i = 1; i<original_length; ++i){
        // 存在重复字符,增加计数器
        if (str[i-1] == str[i])
            ++count;
        else {
            out += str[i-1];
            out += std::to_string(count);  // 将字符计数值转换为字符保存入新的字符串
            count = 1;  // 重置字符计数器
        }
        if (out.length() >= original_length) {
            return str;  // 压缩后字符串长度大于原始字符串,返回原始字符串
        }
    }
    out += str[original_length-1];
    out += std::to_string(count);
    if (out.length() >= original_length) {
        return str;
    }
    return out;
}

int main() {
    std::string str, out;
    std::cout<<"Enter a string:\n";
    std::cin>>str;
    out=stringCompress(str);
    // 原始字符串长度大于压缩字符串长度
    if (str.compare(out)) {
        std::cout<<str<<" can be compressed to " <<out<<std::endl;
    }
    // 原始字符串长度小于压缩字符串长度
    else {
        std::cout<<str<<" can't be compressed"<<std::endl;
    }
    return 0;
}
























