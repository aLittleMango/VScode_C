/*
 * @Description: 无重复字符的最大子串
 * @Author: aLittleMango
 * @Date: 2021-09-24 19:21:20
 * @LastEditTime: 2021-09-26 15:19:55
 * @FilePath: \VScode_C\Demo\10-49\12_hard.c
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char *s)
{
    int start = 0, end = 0, maxlen = 0;
    /*维护一个字符表，里面存已经出现的字符，(int)*(s+end)就是对应字符的ASCII码，start是字串的开头，end是结尾。*/
    char map[256] = {0};
    map[(int)*(s + start)] = 1;

    while (*(s + end) != 0)
    {
        maxlen = maxlen > (end - start + 1) ? maxlen : (end - start + 1);
        ++end;
        while (0 != map[(int)*(s + end)])
        {
            map[(int)*(s + start)] = 0;
            ++start;
        }
        map[(int)*(s + end)] = 1;
    }

    return maxlen;
}

void main()
{
    char str[80] = "abccb 1aeiaa";
    int num = lengthOfLongestSubstring(str);
    printf("%d\n", num);
    system("pause");
}