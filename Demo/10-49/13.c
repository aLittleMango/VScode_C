/*
 * @Description: 寻找两个正序数组的中位数
 * @Author: aLittleMango
 * @Date: 2021-09-24 20:23:30
 * @LastEditTime: 2021-09-26 15:20:20
 * @FilePath: \VScode_C\Demo\10-49\13.c
 */

//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    double median_num = 0;
    int num = nums1Size + nums2Size;
    int i = 0, j = 0, k = 0;
    int merge[num];
    while ((i < nums1Size) && (j < nums2Size))
    {
        if (nums1[i] <= nums2[j])
            merge[k++] = nums1[i++];
        else
            merge[k++] = nums2[j++];
        //merge[k++] = (nums1[i] <= nums2[j]) ? nums1[i++] : nums2[j++];
    }

    // C语言中，Segmentation fault(core dumped) 即段错误
    // 造成原因：段错误就是指访问的内存超出了系统所给这个程序的内存空间。
    // 一般是随意使用野指针或者数组、数组越界。
    while (i < nums1Size)
        merge[k++] = nums1[i++];
    while (j < nums2Size)
        merge[k++] = nums2[j++];

    median_num = (num) % 2 == 0 ? (double)(merge[num / 2] + merge[num / 2 - 1]) / 2 : merge[(num - 1) / 2];
    return median_num;
}

void main()
{
    int a[] = {1, 2, 5, 9};
    int b[] = {3};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);
    double num;
    num = findMedianSortedArrays(a, n1, b, n2);
    printf("%f\n", num);
    system("pause");
}
