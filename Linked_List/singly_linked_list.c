//����ϵͳ��win10
//���뻷����vs2017
//���ߣ�ilhua@https://github.com/ilhua

//ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

//������Ĵ洢�ṹ
typedef int DataType;
typedef struct Node {
	DataType data;
	struct Node* next;
}Node, *PNode;

//��������
PNode InitList(void);	//����������ʼ��
PNode CreateNode(void);		//�����½��
void ListEmpty(PNode pHead);		//�п�
void AddNode(PNode pHead);	//����ֵ��β�巨��
void AddNode_head_style(PNode pHead);	//����ֵ��ͷ�巨��
void TraverList(PNode pHead);	//����
void ListInsert(PNode pHead, int i, DataType dataCreate);	//��ָ��λ�ò���ڵ�
void LocateElem(PNode pHead, DataType data);		//������ĳֵ��ȵĽ��
DataType ListDelete(PNode pHead, int i, DataType data);	 //ɾ��ָ��λ�ý�㲢������ֵ
void DeleteElem(PNode pHead, DataType data);		//ɾ��ָ��Ԫ��
void ClearList(PNode pHead);		//ɾ����������

//������
int main(void)
{
	PNode pHead = InitList();
	AddNode(pHead);
	ClearList(pHead);
	pHead = NULL;
	return 0;
}

//����������ʼ��
PNode InitList(void)
{
	//����ͷ�ڵ�
	PNode pHead = CreateNode();
	return pHead;
}

//�����½��
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

//�п�
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

//����ֵ��β�巨��
//pHead->p1->p2->...->pLen->NULL
void AddNode(PNode pHead)
{
	printf("enter the len:");
	scanf("%d", &pHead->data);
	int len = pHead->data;
	PNode pNew;
	//����β���
	PNode pTail = pHead;
	for (int i = 0; i < len; i++) {
		pNew = CreateNode();
		printf("enter the %d data:", i + 1);
		scanf("%d", &pNew->data);
		//�׽��ָ���½��
		pTail->next = pNew;
		//�½��ָ��
		pNew->next = NULL;
		//�½�㼴Ϊβ���
		pTail = pNew;
	}
	printf("---finish---\n");
}

//����ֵ��ͷ�巨��
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

//����
void TraverList(PNode pHead) {
	PNode pTemp = pHead->next; //ע��������pTemp->next=pHead������
							   //pTemp->next�Ƿ�����ΪpTemp��ʱֻ��ָ�������δָ��ṹ��
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

//��ָ��λ�ò���ڵ�
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

//������ĳֵ��ȵĽ��
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

//ɾ��ָ��λ�ý�㲢������ֵ
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
			//ָ��ѭ����ɾ�����ǰһλ��
			for (int j = 0; j < i - 1; j++) {
				pTemp = pTemp->next;
			}
			pDelete = pTemp->next;
			data = pDelete->data;
			pTemp->next = pDelete->next;
			free(pDelete);
			pHead->data -= 1;
			//��ֹ����Ұָ��
			pDelete = NULL;
			printf("---finish---\n");
			return data;
		}
	}
	return -1;
}

//ɾ��ָ��Ԫ��
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

//ɾ����������
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

