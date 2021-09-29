/*
 * @Description: 最长回文子串
 * @Author: aLittleMango
 * @Date: 2021-09-26 12:53:08
 * @LastEditTime: 2021-09-28 23:21:22
 * @FilePath: \VScode_C\Demo\10-49\14_amusing.c
 */

//给你一个字符串 s，找到 s 中最长的回文子串
// 1 <= s.length <= 1000
// s 仅由数字和英文字母（大写和/或小写）组成
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//string 是定义一个字符串，存储的是一段如“abcd”的数据，而且最后还有一个结束符'\0';
//char 是定义一个字符，存储一个字符，占一个字节。

struct huiwen
{
    int start;
    int end;
};

char *longestPalindrome(char *s)
{
    struct huiwen temp, max; //先声明两个变量用于存储当前回文串和最优回文串
    int i;
    int lenth = strlen(s);
    max.start = max.end = 0; //最优回文串初始化为0
    for (i = 0; i < lenth;)
    {
        temp.start = temp.end = i;
        while (s[temp.start] == s[temp.end + 1]) //先找相同的字符作为回文串的中心主体
            (temp.end)++;
        i = temp.end + 1;
        while ((temp.start - 1) >= 0 && (temp.end + 1) < lenth) //两边延伸
        {
            if (s[temp.start - 1] == s[temp.end + 1])
            {
                (temp.start)--;
                (temp.end)++;
            }
            else
                break;
        }
        if (temp.end - temp.start > max.end - max.start)
            max = temp;
    }
    s[max.end + 1] = '\0';
    return &s[max.start];
}

void main()
{
    char str[80] = "a";
    char *num = longestPalindrome(str);
    printf("%s\n", num);
    system("pause");
}