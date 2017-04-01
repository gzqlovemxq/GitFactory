/*
 * 给定一个无序数组，获取该数组需要排序的最小长度
 */
#include <iostream>

int getMinLength(int a[], int length)
{
    if(!a || length <= 0)
    {
        return 0;
    }

    int max = a[0];
    int maxIndex = 0;
    for(int i = 1; i < length; i++)
    {
        if(a[i] < max)
        {
            maxIndex = i;
        }
        else
        {
            max = a[i];
        }
    }

    // 有序数组，不需要排序
    if(maxIndex == 0)
    {
        return 0;
    }

    int min = a[length - 1];
    int minIndex = length - 1;
    for(int j = length - 2; j >= 0; j--)
    {
        if(a[j] > min)
        {
            minIndex = j;
        }
        else
        {
            min = a[j];
        }
    }

    return maxIndex - minIndex + 1;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[] = {9, 2, 8, 4, 5, 6, 7, 2, 1, 10};
    int c[] = {1, 2, 3, 8, 4, 5, 6, 7, 9, 10};
    int d[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    std::cout << getMinLength(a, 10) << std::endl;
    std::cout << getMinLength(b, 10) << std::endl;
    std::cout << getMinLength(c, 10) << std::endl;
    std::cout << getMinLength(d, 10) << std::endl;

    return 0;
}

