# C语言自定义函数库</center>



## 文档信息

作者：Uncle_Lv

创建时间：2019/11/22

修改时间：2019/11/23



## sort.h



### 说明



依赖：需要标准头文件<stdio.h>

描述：此头文件包含C语言的常用排序算法

创建时间：2019/11/22



### 内容



#### swap()函数 -交换两数位置

```c
/*
 * 交换两个整型数的值
 */
void swap(int *num1, int *num2);
```



#### bubble_sort()函数 -冒泡排序

```c
/*
 *冒泡排序
 * 参数：*array -数组指针
 *       length -数组元素的个数
 *       order -标识符，true表示升序排序，false表示降序排序
 * 说明：冒泡排序时间复杂度度较高，建议使用快速排序
 */
void *bubble_sort(int *array, int length, bool order);
```



#### quick_sort()函数 -快速排序

```c
/* 快速排序
 * 参数：*array -数组指针
 *       left -第一个数组元素的下标
 *       right -最后一个数组元素的下标
 *       order -标识符，true表示升序排序，false表示降序排序
 */
void quick_sort(int *array, int left, int right,bool order);
```