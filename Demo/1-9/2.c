/*
 * @Description: 在字符串s1中查找字符串s2最右出现的位置，并返回一个指向该位置的指针
 * @Author: aLittleMango
 * @Date: 2021-09-23 14:35:49
 * @LastEditTime: 2021-09-24 10:38:54
 * @FilePath: \VScode_C\Demo\1-9\2.c
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char *my_strrstr(char const *s1, char const *s2);

void main()
{
    char *p = my_strrstr("23abcd1231a", "2");
    printf("%s\n", p);
    system("pause");
}

char *
my_strrstr(char const *s1, char const *s2)
{
    register char *last; //寄存器变量
    register char *current;

    last = NULL;

    if (*s2 != '\0')
    {
        current = strstr(s1, s2);
        while (current != NULL)
        {
            last = current;
            current = strstr(last + 1, s2);
        }
    }
    return last;
}