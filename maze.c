#include<stdio.h>
#include <malloc.h>

// 结果显示： 
//  2表示走过的路
//  8表示此路不通 

#define row 14
#define col 17 
typedef struct _position{
	int x;
	int y;
	int dir;
}position;

//Stack
typedef struct _node{
	position pos;
	struct _node * next;
}Node;
void push(Node * head,position pos)
{
	Node * temp;
	temp = (Node *) malloc (sizeof(Node));
	temp->pos = pos;
	temp->pos.dir = 0;
	temp->next = head->next;
	head->next = temp;
}
void pop(Node * head)
{
	Node * temp;
	if(head->next)
	{
		temp = head->next;
		head->next = temp->next;
		free(temp);
	}	
	else
		printf("Empty");

}

//判断是否能走 
//能走入栈并标记为走过的路 
//不能走dir++表示换方向 
void judgemove(int (*maze)[col],position pos,Node *head)
{
	//printf("(%2d,%2d) dir:%2d\n",pos.x,pos.y,pos.dir);
	if( (pos.x>-1) && (pos.y>-1) && (pos.x<row) && (pos.y<col) && maze[pos.x][pos.y]==1)
	{	push(head,pos); maze[pos.x][pos.y] = 2;}
	else
		head->next->pos.dir++;
}

//移动 
//无法继续移动出栈pos 并将这个位置标记为死胡同 
void move(int (*maze)[col],position pos,Node * head)
{
	pos = head->next->pos;
	//printf("%d\n",head->next->pos.dir);
	switch(head->next->pos.dir)
	{
		case 0:pos.y = head->next->pos.y-1;judgemove(maze,pos,head);break;
		case 1:pos.x = head->next->pos.x-1;judgemove(maze,pos,head);break;
		case 2:pos.y = head->next->pos.y+1;judgemove(maze,pos,head);break;
		case 3:pos.x = head->next->pos.x+1;judgemove(maze,pos,head);break;
		default: maze[head->next->pos.x][head->next->pos.y] = 8;pop(head);break;
	}
}
void printStack(Node * head)
{
	Node * temp;
	temp = head->next;
	while(temp)
	{
		printf("(%2d,%2d) dir:%2d\n",temp->pos.x,temp->pos.y,temp->pos.dir);
		temp = temp->next;
	}
}

//注意二维数组的参数传递
//*******遇到问题的地方 
void printmaze(int (*maze)[col])
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			printf("%3d",maze[i][j]);
		printf("\n");
	}
	printf("\n\n");
}
int main()
{
	Node * head;
	position finalPosition;
	position pos;
	int Maze[row][col] ={	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
				 			1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,
				 			1,1,0,0,0,1,0,0,1,1,1,0,0,1,1,1,1,
				 			1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,
				 			1,1,1,0,1,1,1,1,1,1,1,0,1,1,0,0,1,
				 			1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1,
				 			1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1,
				 			1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1,
				 			1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,
							1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1,
							1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1,
							1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1,
							1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1,
							1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
	printmaze(Maze);
	
	head = (Node *) malloc (sizeof(Node));
	head->next = (Node *) malloc (sizeof(Node));
	head->next->next = NULL;
	//设置起点 
	head->next->pos.x=0;
	head->next->pos.y=0;
	Maze[0][0] = 2;
	head->next->pos.dir = 0;
	//设置终点 
	finalPosition.x = 3;
	finalPosition.y = 6;
	finalPosition.dir= 0;					
	pos = head->next->pos;
	while(1)
	{	
		if(head->next )
		{
			if(head->next->pos.x!= finalPosition.x || finalPosition.y!=head->next->pos.y)
				move(Maze,pos,head);
			else
			{	printmaze(Maze);printStack(head);printf("走完了");break;}	
		}
		else
		{	printmaze(Maze);printf("到不了");break;}
		//printmaze(Maze);
		//printStack(head);
		//getchar();
	}
}
