/*
ʱ�䣺2021/1/1 14:12
�༭�ˣ�chongqiu00
����:����һ����Ԫ���飬������л���������

<�ڶ��α�д>
*/

#include "main.h" 

int main (int argc, char* argv[])
{
    //��ʼ��
    Triplet arry;
    if (NULL != (arry = InitTriplet(arry, 1, 2, 3))){
        printf("��Ԫ�����ʼ���ɹ���\n");
    }
    //����
    if (TraverseTriplet(arry)){
        printf("��Ԫ��������ɹ���\n");
    }
    //�鿴iλ�����Ԫ��
    int e;
    if (Get(arry,0,&e)){
        printf("e = %d\n", e);
    }
    //�ı�����Ԫ��ֵ
    if (Put(arry, 1, 12)){
        printf("���ĳɹ���\n");
        printf("%d\n", arry[0]);
    }
    //�Ƿ�����
    if (IsAscending(arry)){
        printf("����Ԫ����������\n");
    }
    //�Ƿ���
    if (IsDescending(arry)){
        printf("����Ԫ�����ǽ���\n");
    }
    //���ֵ
    if (Max(arry, &e)){
        printf("����Ԫ��������ֵΪ%d\n", e);
    }
    //��Сֵ
    if (Min(arry,  &e)){
         printf("����Ԫ�������СֵΪ%d\n", e);
    }
    //������Ԫ����
    if (DestroyTriplet(arry))
    {
        printf("��Ԫ�������ٳɹ�");
    }

    return 0;
}