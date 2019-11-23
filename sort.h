/*
 * 常见的排序算法
 * 作者：Uncle_Lv
 * 创建时间：2019/11/22
 */

#ifndef CLION_BUBBLE_SORT_H
#define CLION_BUBBLE_SORT_H
#include <stdio.h>

// 此头文件包含以下函数

/*
 * 交换两个整型数的值
 */
void swap(int *num1, int *num2);

/*
 *冒泡排序
 * 参数：*array -数组指针
 *       length -数组元素的个数
 *       order -标识符，true表示升序排序，false表示降序排序
 * 说明：冒泡排序时间复杂度度较高，建议使用快速排序
 */
void *bubble_sort(int *array, int length, bool order);

/* 快速排序
 * 参数：*array -数组指针
 *       left -第一个数组元素的下标
 *       right -最后一个数组元素的下标
 *       order -标识符，true表示升序排序，false表示降序排序
 */
void quick_sort(int *array, int left, int right,bool order);

/*
 * 交换两个整型数的值
 */
void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

/*
 * 冒泡排序
 * 参数：*array -数组指针
 *       length -数组元素的个数
 *       order -标识符，true表示升序排序，false表示降序排序
 * 作者：Uncle_Lv
 * 创建时间：2019/11/22
 */
void *bubble_sort(int *array, int length, bool order) {
    // 进行length-1次排序
    for (int i = 0; i < length - 1; i++) {
        // 每次排序比较length-i-1次
        for (int j = 0; j < length - i - 1; j++) {
            if (order) {
                if (array[j] > array[j + 1]) {
                    swap(array + j, array + j + 1);
                }
            } else {
                if (array[j] < array[j + 1]) {
                    swap(array + j, array + j + 1);
                }
            }
        }
    }
}

/*
 * 快速排序
 * *array -数组指针
 * left -第一个数组元素的下标
 * right -最后一个数组元素的下标
 * 作者：Uncle_Lv
 * 创建时间：2019/11/22
 * 说明：此函数已过时，在C环境下无法使用，但在C++环境下去掉注释符号后，仍可使用（C语言不支持方法重载）
 */
/*
 void quick_sort(int *array, int left, int right) {
    // 当左下标大于右下标时，排序结束
    if (left > right) {
        return;
    }

    // pivot -中心数
    int pivot = array[left];
    int i = left;
    int j = right;

    while (i != j) {
        while (array[j] >= pivot && i < j) {
            j--; // 左下标右移，直至遇见比中心数大的数，或遇见右下标
        }

        while (array[i] <= pivot && i < j) {
            i++; // 右下标左移，直至遇见比中心数小的数，或遇见右下标
        }

        if (i < j) {
            swap(array+i, array+j);
        }

    }

    // 将中心数放到中心
    array[left] = array[i];
    array[j] = pivot;

    // 递归执行，直至结束排序
    quick_sort(array, left, i - 1);
    quick_sort(array, i + 1, right);
}
 */

/*
 * 快速排序
 * 参数：*array -数组指针
 *       left -第一个数组元素的下标
 *       right -最后一个数组元素的下标
 *       order -标识符，true表示升序排序，false表示降序排序
 * 作者：Uncle_Lv
 * 创建时间：2019/11/23
 * 修改时间：2019/11/23
 * 修改内容：增加了降序排序
 */
void quick_sort(int *array, int left, int right,bool order) {
    // 当左下标大于右下标时，排序结束
    if (left > right) {
        return;
    }

    // pivot -中心数
    int pivot = array[left];
    int i = left;
    int j = right;

    while (i != j) {
        if (order) {
            while (array[j] >= pivot && i < j) {
                j--;
            }

            while (array[i] <= pivot && i < j) {
                i++;
            }
        } else {
            while (array[j] <= pivot && i < j) {
                j--;
            }

            while (array[i] >= pivot && i < j) {
                i++;
            }
        }

        if (i < j) {
            swap(array+i, array+j);
        }
    }

    // // 将中心数放到中心
    array[left] = array[i];
    array[j] = pivot;

    quick_sort(array, left, i - 1, order);
    quick_sort(array, i + 1, right, order);
}

#endif