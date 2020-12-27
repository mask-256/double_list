#include <stdio.h>
#include <stdlib.h>

struct information
{
	int num;
};

struct link
{
	struct information info;	//������
	struct link *pnext;		//ָ����
	struct link *prev;
};

struct link *phead = NULL;
struct link *list = NULL;

//����һ���ڵ�
struct link *Add_Link(int num)
{
	struct link *pnew = (struct link*)malloc(sizeof(struct link));	//����һ���ڵ���ڴ�

	pnew->info.num = num;
	pnew->pnext = NULL;	//���һ���ڵ��ַ����Ϊ��
	pnew->prev = NULL;
	return pnew;	//���ؽڵ��ַ
}

//ͷ��
void Creat_List(int num)
{
	struct link *pnew = Add_Link(num);	//����һ���ڵ�
	
	if (list == NULL)
	{	
		/*�������Ϊ�գ��������ĵ�ַָ���½��Ľڵ�
		 ����˵�����һ���ڵ��ַΪ�գ�����½��Ľڵ���ǵ�һ���ڵ�*/
		list = pnew;
	}
	else
	{
		//�����һ���ڵ��ַ��Ϊ�գ����½��ڵ��ָ����ָ���һ���ڵ�
		pnew->pnext = list;
		list->prev = pnew;

		//��pnew���׵�ַ��Ϊ�����һ���ڵ���׵�ַ
		list = pnew;
//		phead = pnew;
	}
}

//β��
void Creat_List_2(int num)
{
	struct link *pnew = Add_Link(num);	//����һ���ڵ�

	if (list == NULL)
	{
		/*�������Ϊ�գ��������ĵ�ַָ���½��Ľڵ�
		 ����˵�����һ���ڵ��ַΪ�գ�����½��Ľڵ���ǵ�һ���ڵ�*/
		list = pnew;
		phead = pnew;
	}
	else
	{
		//list��ָ����ָ��pnew���׵�ַ
		list->pnext = pnew;
		//list�ĵ�ַ����Ϊ���һ���ڵ���׵�ַ���Ա��´β���
		list = pnew;
	}
}

//���������ڵ���Ϣ���ο���ָ��λ�ò���ڵ�
void Creat_List_3(int position, int num)
{

}

void delete_list(int num)
{
	struct link *current = list;

	while (current)
	{
		if (current->info.num == num)
		{
			break;
		}

		current = current->pnext;
	}

	if (current == list)
	{
		//����ǵ�һ���ڵ㣬�ѵ�һ���ڵ���׵�ַ����Ϊ��һ���ڵ�ָ����ĵ�ַ�����ڶ����ڵ���׵�ַ��
		//Ȼ�����ͷŵ�һ���ڵ���ڴ�
		current->pnext->prev = NULL;
		list = current->pnext;
		
		free(current);
	}
	else if(current->pnext ==	NULL)
	{	//��������һ���ڵ㣬�����ͷ����һ���ڵ��ڴ棬Ȼ���ٽ���һ���ڵ��ָ����ָ��NULL
		current->prev->pnext = NULL;
		free(current);

	}
	else 
	{	//������м�ڵ㣬���Ȱ���һ���ڵ��ָ����ָ��ǰ�ڵ��ָ������һ���ڵ���׵�ַ��
		//���ͷŵ�ǰ�ڵ���ڴ�
		current->prev->pnext = current->pnext;
		current->pnext->prev = current->prev;

		free(current);
	}
	
}


//��ӡ����
void printf_list(void)
{
	struct link *p = list;	//ͷ�ڵ�
	printf("from begin to end\n");
	while (p) 
	{	
		printf("%d\n", p->info.num);
		if(p->pnext != NULL)
			p = p->pnext;
		else
		{
			break;
		}
	}

	printf("form end to begin\n");
	while (p)
	{
		printf("%d\n", p->info.num);
		if (p->prev != NULL)
			p = p->prev;
		else
		{
			break;
		}
	}
}

struct link *g_temp = NULL;
void main(void)
{
//	int a = 0;
//	a = phead->info.num;
	
#if 1
	Creat_List(1);
	Creat_List(2);
	Creat_List(3);
	Creat_List(4);
#endif
#if 0
	Creat_List_2(1);
	Creat_List_2(2);
	Creat_List_2(3);
	Creat_List_2(4);
#endif
	g_temp = phead;
	delete_list(2);

	printf_list();
	while (1);
}
