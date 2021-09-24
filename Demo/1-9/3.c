/*
 * @Description: 从一个字符串中提取空白字符分割的标记并把它们打印出来
 * @Author: aLittleMango
 * @Date: 2021-09-23 15:25:15
 * @LastEditTime: 2021-09-24 10:39:36
 * @FilePath: \VScode_C\Demo\1-9\3.c
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_tokens(char *line);
void print_tokens(char *line)
{
    static char whitespace[] = " \t\f\r\v\n";
    char *token;

    for (token = strtok(line, whitespace); token != NULL; token = strtok(NULL, whitespace))
        printf("Next token is %s\n", token);
}

void main()
{
    char str[80] = "this is a test! ";
    print_tokens(str);
    system("pause");
}
