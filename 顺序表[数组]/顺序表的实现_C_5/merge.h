#ifndef MERGE_H_
#define MERGE_H_

#include "main.h"

void Union(struct SqList* La, struct SqList* Lb);//13.1	a��b�����������������˳���ΪLa��A��B�е����Ԫ�ؾ�����A�У�A�е�length��׼ȷֵ,sizelistΪ׼ȷֵ
void MergeList1(struct SqList* La, struct SqList* Lb, struct SqList* Lc);//13.2����������µ�˳����У�A��B�е����Ԫ�ؾ�����C�У�C�е�length����׼ȷֵ,sizelistΪ׼ȷֵ
void MergeList2(struct SqList* La, struct SqList* Lb, struct SqList* Lc);//13.3,����ʹ�ô�����ʼ������ʵ����˳���Ĵ���,ʹ��ָ��ֱ�ָ��A��B���������������������ȱ����û�н��
void MergeList3(struct SqList* La, struct SqList* Lb, struct SqList* Lc);//13.4��A��B�е����Ԫ�ز�����C�У�C�е�length,sizelist��Ϊ׼ȷֵ 

#endif