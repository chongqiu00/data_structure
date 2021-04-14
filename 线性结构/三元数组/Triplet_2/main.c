/*
时间：2021/1/1 14:12
编辑人：chongqiu00
功能:定义一个三元数组，对其进行基本操作。

<第二次编写>
*/

#include "main.h" 

int main (int argc, char* argv[])
{
    //初始化
    Triplet arry;
    if (NULL != (arry = InitTriplet(arry, 1, 2, 3))){
        printf("三元数组初始化成功！\n");
    }
    //遍历
    if (TraverseTriplet(arry)){
        printf("三元数组遍历成功！\n");
    }
    //查看i位数组的元素
    int e;
    if (Get(arry,0,&e)){
        printf("e = %d\n", e);
    }
    //改变数组元素值
    if (Put(arry, 1, 12)){
        printf("更改成功！\n");
        printf("%d\n", arry[0]);
    }
    //是否升序
    if (IsAscending(arry)){
        printf("此三元数组是升序！\n");
    }
    //是否降序
    if (IsDescending(arry)){
        printf("此三元数组是降序！\n");
    }
    //最大值
    if (Max(arry, &e)){
        printf("此三元数组的最大值为%d\n", e);
    }
    //最小值
    if (Min(arry,  &e)){
         printf("此三元数组的最小值为%d\n", e);
    }
    //销毁三元数组
    if (DestroyTriplet(arry))
    {
        printf("三元数组销毁成功");
    }

    return 0;
}