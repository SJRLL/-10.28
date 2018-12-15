#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode*_next;
	
}SListNode;

typedef struct SList
{
	SListNode*_head; 
}SList;


void SListInit(SList* plist);
void SListDestory(SList* plist);


SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plist, SLTDataType x);//ͷ��
void SListPopFront(SList* plist);//ͷɾ
void SListPushBack(SList* plist, SLTDataType x);//β��
void SListPopBack(SList* plist);//βɾ
SListNode* SListfind(SList* plist, SLTDataType x);//�������в���ĳ��Ԫ��




void SListInsertAfter(SListNode* pos, SLTDataType x);//��pos������в���

void SListEraseAfter(SListNode* pos);//��pos��ɾ��

void SListInsertBack(SList* plist,SListNode* pos, SLTDataType x);//��posǰ�߲���

void SListEraseBack(SList* plist,SListNode* pos);//��posǰ��ɾ��

void SListRemove(SList* plist, SListNode* pos);

void SListPrint(SList* plist);

void TestSList();


