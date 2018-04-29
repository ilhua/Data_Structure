//操作系统：win10
//编译环境：vs2017
//作者：ilhua@https://github.com/ilhua

//头文件
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

//单链表的存储结构
typedef int DataType;
typedef struct Node {
	DataType data;
	struct Node* next;
}Node, *PNode;

//函数声明
PNode InitList(void);	//创建链表并初始化
PNode CreateNode(void);		//创造新结点
void ListEmpty(PNode pHead);		//判空
void AddNode(PNode pHead);	//链表赋值（尾插法）
void AddNode_head_style(PNode pHead);	//链表赋值（头插法）
void TraverList(PNode pHead);	//遍历
void ListInsert(PNode pHead, int i, DataType dataCreate);	//在指定位置插入节点
void LocateElem(PNode pHead, DataType data);		//查找与某值相等的结点
DataType ListDelete(PNode pHead, int i, DataType data);	 //删除指定位置结点并返回其值
void DeleteElem(PNode pHead, DataType data);		//删除指定元素
void ClearList(PNode pHead);		//删除整个链表

//主函数
int main(void)
{
	PNode pHead = InitList();
	AddNode(pHead);
	ClearList(pHead);
	pHead = NULL;
	return 0;
}

//创建链表并初始化
PNode InitList(void)
{
	//定义头节点
	PNode pHead = CreateNode();
	return pHead;
}

//创造新结点
PNode CreateNode(void)
{
	PNode pNew = (PNode)malloc(sizeof(Node));
	if (pNew == NULL) {
		printf("failed malloc\n");
		exit(-1);
	}
	else {
		pNew->data = 0;
		pNew->next = NULL;
	}
	return pNew;
}

//判空
void ListEmpty(PNode pHead)
{
	if (pHead->next == NULL) {
		printf("the list is empty\n");
		//return 1;
	}
	else {
		printf("the list isn't empty\n");
		//return 0;
	}
}

//链表赋值（尾插法）
//pHead->p1->p2->...->pLen->NULL
void AddNode(PNode pHead)
{
	printf("enter the len:");
	scanf("%d", &pHead->data);
	int len = pHead->data;
	PNode pNew;
	//定义尾结点
	PNode pTail = pHead;
	for (int i = 0; i < len; i++) {
		pNew = CreateNode();
		printf("enter the %d data:", i + 1);
		scanf("%d", &pNew->data);
		//首结点指向新结点
		pTail->next = pNew;
		//新结点指空
		pNew->next = NULL;
		//新结点即为尾结点
		pTail = pNew;
	}
	printf("---finish---\n");
}

//链表赋值（头插法）
//pHead->pLen->...->p2->p1->NULL
void AddNode_head_style(PNode pHead)
{
	printf("enter the len:");
	scanf("%d", &pHead->data);
	int len = pHead->data;
	PNode pNew;
	for (int i = 0; i < len; i++) {
		pNew = CreateNode();
		scanf("%d", &pNew->data);
		pNew->next = pHead->next;
		pHead->next = pNew;
	}
	printf("---finish---\n");
}

//遍历
void TraverList(PNode pHead) {
	PNode pTemp = pHead->next; //注意此语句与pTemp->next=pHead的区别
							   //pTemp->next非法，因为pTemp此时只是指针变量，未指向结构体
	if (pTemp == NULL) {
		printf("the list is empty\n");
	}
	else {
		printf("the data of the list is:\n");
		while (pTemp != NULL)
		{
			printf("%d ", pTemp->data);
			pTemp = pTemp->next;
		}
		printf("\n");
	}
	printf("---finish---\n");
}

//在指定位置插入节点
void ListInsert(PNode pHead, int i, DataType dataCreate)
{
	int len = pHead->data;
	if (i<1 || i>len + 1) {
		printf("the location of insert is wrong\n");
	}
	else {
		PNode pCreate = CreateNode();
		pCreate->data = dataCreate;
		PNode pTemp = pHead;
		for (int j = 1; j < i; j++) {
			pTemp = pTemp->next;
		}
		pCreate->next = pTemp->next;
		pTemp->next = pCreate;
		pHead->data += 1;
		printf("---finish---\n");
	}

}

//查找与某值相等的结点
void LocateElem(PNode pHead, DataType data)
{
	PNode pTemp = pHead->next;
	int count, flag;
	count = flag = 0;
	while (pTemp != NULL) {
		count++;
		if (pTemp->data == data) {
			printf("Node:%d ", count);
			flag = 1;
		}
		pTemp = pTemp->next;
	}
	if (flag == 1)	printf("\n---finish---\n");
	else printf("no node in list is %d\n", data);
}

//删除指定位置结点并返回其值
DataType ListDelete(PNode pHead, int i, DataType data)
{
	int len = pHead->data;
	if (len == 0) {
		printf("the list is empty, can not delete\n");
	}
	else {
		if (i<1 || i>len) {
			printf("the location of delete is wrong\n");

		}
		else {
			PNode pTemp, pDelete;
			pTemp = pHead;
			//指针循环至删除点的前一位置
			for (int j = 0; j < i - 1; j++) {
				pTemp = pTemp->next;
			}
			pDelete = pTemp->next;
			data = pDelete->data;
			pTemp->next = pDelete->next;
			free(pDelete);
			pHead->data -= 1;
			//防止产生野指针
			pDelete = NULL;
			printf("---finish---\n");
			return data;
		}
	}
	return -1;
}

//删除指定元素
void DeleteElem(PNode pHead, DataType data)
{
	int flag = 0;
	PNode pTemp, pDelete;
	pDelete = pHead->next;
	pTemp = pHead;
	while (pDelete != NULL) {
		if (pDelete->data == data) {
			pTemp->next = pDelete->next;
			free(pDelete);
			pHead->data -= 1;
			pDelete = pTemp->next;
			flag = 1;
		}
		else {
			pTemp = pDelete;
			pDelete = pDelete->next;
		}
	}
	if (flag == 1)	printf("---finish---\n");
	else printf("%d do not exit\n", data);
}

//删除整个链表
void ClearList(PNode pHead)
{
	PNode pTemp = pHead->next;
	free(pHead);
	pHead = pTemp;
	while (pTemp != NULL) {
		pTemp = pTemp->next;
		free(pHead);
		pHead = pTemp;
	}
	printf("---finish clear the list---\n");
}

