#include <stdio.h>
#include <stdlib.h>

struct information
{
	int num;
};

struct link
{
	struct information info;	//数据域
	struct link *pnext;		//指针域
	struct link *prev;
};

struct link *phead = NULL;
struct link *list = NULL;

//增加一个节点
struct link *Add_Link(int num)
{
	struct link *pnew = (struct link*)malloc(sizeof(struct link));	//申请一个节点的内存

	pnew->info.num = num;
	pnew->pnext = NULL;	//最后一个节点地址必须为空
	pnew->prev = NULL;
	return pnew;	//返回节点地址
}

//头插
void Creat_List(int num)
{
	struct link *pnew = Add_Link(num);	//增加一个节点
	
	if (list == NULL)
	{	
		/*如果链表为空，则把链表的地址指向新建的节点
		 或者说如果第一个节点地址为空，则该新建的节点就是第一个节点*/
		list = pnew;
	}
	else
	{
		//如果第一个节点地址不为空，则新建节点的指针域指向第一个节点
		pnew->pnext = list;
		list->prev = pnew;

		//把pnew的首地址作为链表第一个节点的首地址
		list = pnew;
//		phead = pnew;
	}
}

//尾插
void Creat_List_2(int num)
{
	struct link *pnew = Add_Link(num);	//增加一个节点

	if (list == NULL)
	{
		/*如果链表为空，则把链表的地址指向新建的节点
		 或者说如果第一个节点地址为空，则该新建的节点就是第一个节点*/
		list = pnew;
		phead = pnew;
	}
	else
	{
		//list的指针域指向pnew的首地址
		list->pnext = pnew;
		//list的地址更改为最后一个节点的首地址，以便下次插入
		list = pnew;
	}
}

//以数据域内的信息做参考，指定位置插入节点
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
		//如果是第一个节点，把第一个节点的首地址更改为第一个节点指针域的地址（即第二个节点的首地址）
		//然后再释放第一个节点的内存
		current->pnext->prev = NULL;
		list = current->pnext;
		
		free(current);
	}
	else if(current->pnext ==	NULL)
	{	//如果是最后一个节点，首先释放最后一个节点内存，然后再将上一个节点的指针域指向NULL
		current->prev->pnext = NULL;
		free(current);

	}
	else 
	{	//如果是中间节点，首先把上一个节点的指针域指向当前节点的指针域（下一个节点的首地址）
		//再释放当前节点的内存
		current->prev->pnext = current->pnext;
		current->pnext->prev = current->prev;

		free(current);
	}
	
}


//打印链表
void printf_list(void)
{
	struct link *p = list;	//头节点
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
