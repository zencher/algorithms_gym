//
//  main.cpp
//  sort
//
//  Created by zencher on 2018/5/28.
//  Copyright © 2018年 zencher. All rights reserved.
//

#include <stdio.h>



class BubbleSort
{
public:
    void sort(int A[], int n)
    {
        int temp = 0;
        for (int j = 0; j < n - 1; j++)         // 每次最大元素就像气泡一样"浮"到数组的最后
        {
            for (int i = 0; i < n - 1 - j; i++) // 依次比较相邻的两个元素,使较大的那个向后移
            {
                if (A[i] > A[i + 1])            // 如果条件改成A[i] >= A[i + 1],则变为不稳定的排序算法
                {
                    //Swap(A, i, i + 1);
                    temp = A[i];
                    A[i] = A[i+1];
                    A[i+1] = temp;
                }
            }
        }
    }
};


class CocktailSort
{
public:
    void sort(int A[], int n)
    {
        int left = 0;                            // 初始化边界
        int right = n - 1;
        int temp = 0;
        while (left < right)
        {
            for (int i = left; i < right; i++)   // 前半轮,将最大元素放到后面
            {
                if (A[i] > A[i + 1])
                {
                    //Swap(A, i, i + 1);
                    temp = A[i];
                    A[i] = A[i+1];
                    A[i+1] = temp;
                }
            }
            right--;
            for (int i = right; i > left; i--)   // 后半轮,将最小元素放到前面
            {
                if (A[i - 1] > A[i])
                {
                    //Swap(A, i - 1, i);
                    temp = A[i];
                    A[i] = A[i-1];
                    A[i-1] = temp;
                }
            }
            left++;
        }
    }
};


class SelectionSort
{
public:
    void sort(int A[], int n)
    {
        int temp = 0;
        for (int i = 0; i < n - 1; i++)         // i为已排序序列的末尾
        {
            int min = i;
            for (int j = i + 1; j < n; j++)     // 未排序序列
            {
                if (A[j] < A[min])              // 找出未排序序列中的最小值
                {
                    min = j;
                }
            }
            if (min != i)
            {
                //Swap(A, min, i);    // 放到已排序序列的末尾，该操作很有可能把稳定性打乱，所以选择排序是不稳定的排序算法
                temp = A[min];
                A[min] = A[i];
                A[i] = temp;
            }
        }
    }
};

class InsertionSort
{
public:
    void sort(int A[], int n)
    {
        for (int i = 1; i < n; i++)         // 类似抓扑克牌排序
        {
            int get = A[i];                 // 右手抓到一张扑克牌
            int j = i - 1;                  // 拿在左手上的牌总是排序好的
            while (j >= 0 && A[j] > get)    // 将抓到的牌与手牌从右向左进行比较
            {
                A[j + 1] = A[j];            // 如果该手牌比抓到的牌大，就将其右移
                j--;
            }
            A[j + 1] = get; // 直到该手牌比抓到的牌小(或二者相等)，将抓到的牌插入到该手牌右边(相等元素的相对次序未变，所以插入排序是稳定的)
        }
    }
};

class InsertionSortDichotomy
{
public:
    void sort(int A[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            int get = A[i];                    // 右手抓到一张扑克牌
            int left = 0;                    // 拿在左手上的牌总是排序好的，所以可以用二分法
            int right = i - 1;                // 手牌左右边界进行初始化
            while (left <= right)            // 采用二分法定位新牌的位置
            {
                int mid = (left + right) / 2;
                if (A[mid] > get)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            for (int j = i - 1; j >= left; j--)    // 将欲插入新牌位置右边的牌整体向右移动一个单位
            {
                A[j + 1] = A[j];
            }
            A[left] = get;                    // 将抓到的牌插入手牌
        }
    }
};


class ShellSort
{
public:
    void sort(int A[], int n)
    {
        int h = 0;
        while (h <= n)                          // 生成初始增量
        {
            h = 3 * h + 1;
        }
        while (h >= 1)
        {
            for (int i = h; i < n; i++)
            {
                int j = i - h;
                int get = A[i];
                while (j >= 0 && A[j] > get)
                {
                    A[j + h] = A[j];
                    j = j - h;
                }
                A[j + h] = get;
            }
            h = (h - 1) / 3;                    // 递减增量
        }
    }
};

class MergeSortRecursion
{
public:
    void sort(int A[], int left, int right)
    {
        if (left == right)    // 当待排序的序列长度为1时，递归开始回溯，进行merge操作
            return;
        int mid = (left + right) / 2;
        sort(A, left, mid);
        sort(A, mid + 1, right);
        Merge(A, left, mid, right);
    }
    
private:
    void Merge(int A[], int left, int mid, int right)// 合并两个已排好序的数组A[left...mid]和A[mid+1...right]
    {
        int len = right - left + 1;
        int *temp = new int[len];       // 辅助空间O(n)
        int index = 0;
        int i = left;                   // 前一数组的起始元素
        int j = mid + 1;                // 后一数组的起始元素
        while (i <= mid && j <= right)
        {
            temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];  // 带等号保证归并排序的稳定性
        }
        while (i <= mid)
        {
            temp[index++] = A[i++];
        }
        while (j <= right)
        {
            temp[index++] = A[j++];
        }
        for (int k = 0; k < len; k++)
        {
            A[left++] = temp[k];
        }
    }
};


class MergeSortIteration
{
public:
    void sort(int A[], int len)    // 非递归(迭代)实现的归并排序(自底向上)
    {
        int left, mid, right;// 子数组索引,前一个为A[left...mid]，后一个子数组为A[mid+1...right]
        for (int i = 1; i < len; i *= 2)        // 子数组的大小i初始为1，每轮翻倍
        {
            left = 0;
            while (left + i < len)              // 后一个子数组存在(需要归并)
            {
                mid = left + i - 1;
                right = mid + i < len ? mid + i : len - 1;// 后一个子数组大小可能不够
                Merge(A, left, mid, right);
                left = right + 1;               // 前一个子数组索引向后移动
            }
        }
    }
    
private:
    void Merge(int A[], int left, int mid, int right)// 合并两个已排好序的数组A[left...mid]和A[mid+1...right]
    {
        int len = right - left + 1;
        int *temp = new int[len];       // 辅助空间O(n)
        int index = 0;
        int i = left;                   // 前一数组的起始元素
        int j = mid + 1;                // 后一数组的起始元素
        while (i <= mid && j <= right)
        {
            temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];  // 带等号保证归并排序的稳定性
        }
        while (i <= mid)
        {
            temp[index++] = A[i++];
        }
        while (j <= right)
        {
            temp[index++] = A[j++];
        }
        for (int k = 0; k < len; k++)
        {
            A[left++] = temp[k];
        }
    }
};

class HeapSort
{
public:
    void sort(int A[], int n)
    {
        int heap_size = BuildHeap(A, n);    // 建立一个最大堆
        while (heap_size > 1)               // 堆（无序区）元素个数大于1，未完成排序
        {
            // 将堆顶元素与堆的最后一个元素互换，并从堆中去掉最后一个元素
            // 此处交换操作很有可能把后面元素的稳定性打乱，所以堆排序是不稳定的排序算法
            Swap(A, 0, --heap_size);
            Heapify(A, 0, heap_size);     // 从新的堆顶元素开始向下进行堆调整，时间复杂度O(logn)
        }
    }
    
private:
    void Swap(int A[], int i, int j)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    
    void Heapify(int A[], int i, int size)  // 从A[i]向下进行堆调整
    {
        int left_child = 2 * i + 1;         // 左孩子索引
        int right_child = 2 * i + 2;        // 右孩子索引
        int max = i;                        // 选出当前结点与其左右孩子三者之中的最大值
        if (left_child < size && A[left_child] > A[max])
            max = left_child;
        if (right_child < size && A[right_child] > A[max])
            max = right_child;
        if (max != i)
        {
            Swap(A, i, max);                // 把当前结点和它的最大(直接)子节点进行交换
            Heapify(A, max, size);          // 递归调用，继续从当前结点向下进行堆调整
        }
    }
    
    int BuildHeap(int A[], int n)           // 建堆，时间复杂度O(n)
    {
        int heap_size = n;
        for (int i = heap_size / 2 - 1; i >= 0; i--) // 从每一个非叶结点开始向下进行堆调整
            Heapify(A, i, heap_size);
        return heap_size;
    }
};



int main()
{
    int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 };
    int n = sizeof(A) / sizeof(int);
    HeapSort sortAlgrithm;
    sortAlgrithm.sort(A, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
