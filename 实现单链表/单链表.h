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
void SListPushFront(SList* plist, SLTDataType x);//头插
void SListPopFront(SList* plist);//头删
void SListPushBack(SList* plist, SLTDataType x);//尾插
void SListPopBack(SList* plist);//尾删
SListNode* SListfind(SList* plist, SLTDataType x);//在链表中查找某个元素




void SListInsertAfter(SListNode* pos, SLTDataType x);//在pos后面进行插入

void SListEraseAfter(SListNode* pos);//在pos后删除

void SListInsertBack(SList* plist,SListNode* pos, SLTDataType x);//在pos前边插入

void SListEraseBack(SList* plist,SListNode* pos);//在pos前边删除

void SListRemove(SList* plist, SListNode* pos);

void SListPrint(SList* plist);

void TestSList();


