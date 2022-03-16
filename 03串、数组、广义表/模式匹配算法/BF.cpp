#include <stdio.h>
#include <string.h>
#include"./SString.h"
int BF(SqString s,SqString t){
    int i = 1,j = 1;//我这里字符从1开始存储
    while(i <= s.length && j <= t.length){//不超过两个字符串的长度
        if(s.data[i] == t.data[j]){//相同则往下
            ++i;
            ++j;
        }
        else{//不相同则回溯
            i = i - j + 2;//从1移动到j个位置，移动了j - 1
            //个单位，要回到原始位置的下一个则是i - (j - 1) + 1
            j = 1;
        }
    }
    if(j > t.length){//返回匹配的第一个字符的下标,匹配完成时j>=子串的长度
        printf("匹配到的子串第一个字母的下标是：%d\n",i - t.length);
        return i - t.length;
    }
    else{
        printf("没有与之相匹配的子串\n");
        return 0;
    }
}
int main(){
    SqString s1;
    SqString s2;
    // 初始化字符串
    char a[100] = "heAAAAlloworld";
    char b[100] = "AAAA";
    StrAssign(s1,a);
    StrAssign(s2,b);
    printf("s1：\n");
    DispStr(s1);
    printf("s2：\n");
    DispStr(s2);
    // 调用BF算法
    BF(s1,s2);
    return 0;
}