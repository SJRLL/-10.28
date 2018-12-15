#define _CRT_SECURE_NO_WARNINGS 1

#include"单链表.h"

void SListInit(SList* plist)//无头单向不循环链表的初始化
{
	assert(plist);
	plist->_head = NULL;
}


void SListDestory(SList* plist)
{
	assert(plist);
	SListNode* prev = plist->_head;
	SListNode* cur = plist->_head->_next;
	while (cur->_next !=NULL)
	{
		free(prev);
		prev = cur;
		cur = cur->_next;
	}
	free(cur);
	plist->_head = NULL;
}


void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL");
	printf("\n");
}



SListNode* BuySListNode(SLTDataType x)//无头单向不循环链表的申请节点
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SList));
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}


void SListPushFront(SList* plist, SLTDataType x)//无头单向不循环链表的头插
{
	assert(plist);
	SListNode* newnode =  BuySListNode(x);
	SListNode* prev;
	if (plist->_head == NULL)//没有有效元素
	{
		plist->_head = newnode;
	}
	else//存在有效元素
	{
		prev = plist->_head;
		newnode->_next = prev;
		plist->_head = newnode;

	}

}

void SListPopFront(SList* plist)//无头单向不循环链表的头删
{
	assert(plist);
	SListNode* prev;
	if (plist->_head->_next == NULL)//没有可删除的有效元素
	{
		free(plist->_head);
		plist->_head = NULL;
	}
	else//存在有效元素
	{
		prev = plist->_head->_next;
		plist->_head = plist->_head->_next;
	}
	
}


void SListPushBack(SList* plist, SLTDataType x)//尾插
{
	assert(plist);
	SListNode* newnode = BuySListNode(x);
	SListNode* tail;
	if (plist->_head == NULL)//头结点为空，无法尾插
	{
		plist->_head = newnode;
	}
	else
	{
		tail = plist->_head;
		while (tail->_next != NULL)//循环找到尾结点
		{
			tail = tail->_next;//指针向后走，找到空指针尾结点为止
		}
		tail->_next = newnode;//新插入数据覆盖掉空指针尾结点
	}
}


void SListPopBack(SList* plist)//尾删
{
	assert(plist);
	SListNode* tail;
	SListNode* cur;
	if (plist->_head== NULL)//头为空，没有有效结点
	{
		free(plist->_head);
		plist->_head = NULL;
	}
	else
	{
		tail = plist->_head;
		cur = plist->_head->_next;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
			tail = tail->_next;
			
		}
		tail->_next = NULL;
	}
}

SListNode* SListfind(SList* plist, SLTDataType x)//查找某个数
{
	assert(plist);
	SListNode* prev = plist->_head;
	while (prev!=NULL)
	{
		if (prev->_data ==x)
		{
			printf("找到了\n");
			return prev;
		}
		else
		{
			prev = prev->_next;
		}
	}
	printf("找不到需要的数据\n");
	return prev;
}



void SListInsertAfter(SListNode* pos, SLTDataType x)//pos后边插入数据
{
	    assert(pos);
		if (pos == NULL)
		{
			printf("找不到有效数据，无法删除\n");
		}
		else
		{
			SListNode* newnode = BuySListNode(x);
			SListNode* prev = pos->_next;
			pos->_next = newnode;
			newnode->_next = prev;
		}


}

void SListEraseAfter(SListNode* pos)//在pos后边删除
{
	assert(pos);
	if (pos == NULL)
	{
		printf("找不到有效数据，无法删除\n");
	}
	else
	{
		SListNode* prev = pos->_next;
		pos->_next =prev->_next;

	}
}


void SListInsertBack(SList* plist,SListNode* pos, SLTDataType x)//在pos前边插入
{
	assert(pos);
	SListNode* cur=plist->_head;
	SListNode* newnode = BuySListNode(x);
	if (pos == NULL)
	{
		printf("找不到有效数据，无法删除\n");
	}
	else
	{
		while (cur->_next->_next !=pos)
		{
			cur = cur->_next;
		}
		newnode->_next = pos;
		cur->_next->_next = newnode;
	}
}


void SListEraseBack(SList* plist,SListNode* pos)//在pos前边删除
{
	assert(pos);
	SListNode* cur = plist->_head;
	if (pos == NULL)
	{
		printf("找不到有效数据，无法删除\n");
	}
	else
	{
		while (cur->_next->_next != pos)
		{
			cur = cur->_next;
		}
		cur->_next = pos;
    }
}


void SListRemove(SList* plist, SListNode* pos)
{
	assert(pos);
	SListNode* prev = plist->_head;
	if (pos == NULL)
	{
		printf("找不到有效数据，无法删除\n");
	}
	else
	{
		while (prev->_next != pos)
		{
			prev = prev->_next;
		}
		prev->_next = pos->_next;
	}

}

void TestSList()
{
	SList plist;
	SListInit(&plist);
	SListPushFront(&plist, 5);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 1);

	SListPrint(&plist);

    //SListPopFront(&plist);
	//SListPushBack(&plist, 7);

    //SListPopBack(&plist);
	
	
	
    
    //SListEraseAfter(pos);
	/*SListfind(&plist,2);*/
	
    
	SListNode* pos = SListfind(&plist,3);
	//SListInsertAfter(pos, 7);

	//SListInsertBack(&plist,pos, 7);

	//SListEraseBack(&plist,pos);

	SListRemove(&plist, pos);

	//SListEraseAfter(pos);
	SListPrint(&plist);
	
	/*SListDestory(&plist);*/
}

