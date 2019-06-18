//
// Created by wangxing on 19-6-18.
//

//1.3 将给定长度字符串中的空格替换为"%20"

#include <iostream>
#include <string>

/*
 * Function: urlify
 * Args    : string long enough to extra chars + true len
 * Return  : void (in place transformation of string)
 */
void urlify(char *str, int len){
    int numOfSpaces = 0;
    int i =0, j=0;
    for (i=0;i<len;i++) {
        if (str[i] == ' '){
            ++numOfSpaces;       //统计字符串中的空格数
        }
    }
    int extendLen = len + 2 * numOfSpaces;   //添加“%20”后字符串长度
    i = extendLen -1;
    for (j=len-1;j>=0;j--) {
        if (str[j] != ' ') {
            str[i--] = str[j];
        } else {
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
        }
    }
}

int main() {
    char str[] = "Mr John Smith    ";
    std::cout<<"Actual string : "<<str<<std::endl;
    urlify(str, 13);
    std::cout<<"URLified string : "<<str<<std::endl;
    return 0;
}
