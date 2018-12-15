#define _CRT_SECURE_NO_WARNINGS 1

#include"������.h"

void SListInit(SList* plist)//��ͷ����ѭ������ĳ�ʼ��
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



SListNode* BuySListNode(SLTDataType x)//��ͷ����ѭ�����������ڵ�
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SList));
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}


void SListPushFront(SList* plist, SLTDataType x)//��ͷ����ѭ�������ͷ��
{
	assert(plist);
	SListNode* newnode =  BuySListNode(x);
	SListNode* prev;
	if (plist->_head == NULL)//û����ЧԪ��
	{
		plist->_head = newnode;
	}
	else//������ЧԪ��
	{
		prev = plist->_head;
		newnode->_next = prev;
		plist->_head = newnode;

	}

}

void SListPopFront(SList* plist)//��ͷ����ѭ�������ͷɾ
{
	assert(plist);
	SListNode* prev;
	if (plist->_head->_next == NULL)//û�п�ɾ������ЧԪ��
	{
		free(plist->_head);
		plist->_head = NULL;
	}
	else//������ЧԪ��
	{
		prev = plist->_head->_next;
		plist->_head = plist->_head->_next;
	}
	
}


void SListPushBack(SList* plist, SLTDataType x)//β��
{
	assert(plist);
	SListNode* newnode = BuySListNode(x);
	SListNode* tail;
	if (plist->_head == NULL)//ͷ���Ϊ�գ��޷�β��
	{
		plist->_head = newnode;
	}
	else
	{
		tail = plist->_head;
		while (tail->_next != NULL)//ѭ���ҵ�β���
		{
			tail = tail->_next;//ָ������ߣ��ҵ���ָ��β���Ϊֹ
		}
		tail->_next = newnode;//�²������ݸ��ǵ���ָ��β���
	}
}


void SListPopBack(SList* plist)//βɾ
{
	assert(plist);
	SListNode* tail;
	SListNode* cur;
	if (plist->_head== NULL)//ͷΪ�գ�û����Ч���
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

SListNode* SListfind(SList* plist, SLTDataType x)//����ĳ����
{
	assert(plist);
	SListNode* prev = plist->_head;
	while (prev!=NULL)
	{
		if (prev->_data ==x)
		{
			printf("�ҵ���\n");
			return prev;
		}
		else
		{
			prev = prev->_next;
		}
	}
	printf("�Ҳ�����Ҫ������\n");
	return prev;
}



void SListInsertAfter(SListNode* pos, SLTDataType x)//pos��߲�������
{
	    assert(pos);
		if (pos == NULL)
		{
			printf("�Ҳ�����Ч���ݣ��޷�ɾ��\n");
		}
		else
		{
			SListNode* newnode = BuySListNode(x);
			SListNode* prev = pos->_next;
			pos->_next = newnode;
			newnode->_next = prev;
		}


}

void SListEraseAfter(SListNode* pos)//��pos���ɾ��
{
	assert(pos);
	if (pos == NULL)
	{
		printf("�Ҳ�����Ч���ݣ��޷�ɾ��\n");
	}
	else
	{
		SListNode* prev = pos->_next;
		pos->_next =prev->_next;

	}
}


void SListInsertBack(SList* plist,SListNode* pos, SLTDataType x)//��posǰ�߲���
{
	assert(pos);
	SListNode* cur=plist->_head;
	SListNode* newnode = BuySListNode(x);
	if (pos == NULL)
	{
		printf("�Ҳ�����Ч���ݣ��޷�ɾ��\n");
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


void SListEraseBack(SList* plist,SListNode* pos)//��posǰ��ɾ��
{
	assert(pos);
	SListNode* cur = plist->_head;
	if (pos == NULL)
	{
		printf("�Ҳ�����Ч���ݣ��޷�ɾ��\n");
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
		printf("�Ҳ�����Ч���ݣ��޷�ɾ��\n");
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

