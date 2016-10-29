#include<stdio.h>
#include <malloc.h>

#define row 17
#define col 17
typedef struct _position{
	int x;
	int y;
	int dir;
}position;

//Stack
typedef struct _node{
	position pos;
	struct nodetag * next;
}Node;
void push(Node * head,position pos)
{
	Node * temp;
	temp = (Node *) malloc (sizeof(Node));
	temp->pos = pos;
	temp->next = head->next;
	head->next = temp;
}
void pop(Node * head)
{
	Node * temp;
	if(head->next)
		printf("Empty");
	else
	{
		temp = head->next;
		head->next = temp->next;
		free(temp);
	}
}
//maze
/*
typedef struct{
	position pos;
	int dir;
}mazeNode;*/

void judgemove(int maze[row][col],position pos,Node *head)
{
	if( (pos.x>-1) && (pos.y>-1) && (pos.x<row) && (pos.y<col) && maze[pos.x][pos.y]==1)
	{	push(head,pos); maze[pos.x][pos.y] = 2;}
	else
		head->pos.dir++;
}


void move(int maze[row][col],Node * head)
{
	position pos;
	pos = head->next->pos;
	switch(head->next->pos.dir)
	{
		case 0:pos.y = head->next->pos.y-1;judgemove(maze,pos,head);break;
		case 1:pos.x = head->next->pos.x-1;judgemove(maze,pos,head);break;
		case 2:pos.y = head->next->pos.y+1;judgemove(maze,pos,head);break;
		case 3:pos.x = head->next->pos.x+1;judgemove(maze,pos,head);break;
		default: pop(head);break;
	}
/*
	if( (pos->x>-1) && (pos->y>-1) && (pos->x<row) && (pos->y<col) && maze[pos->x][pos->y]==1)
	{	push(head,pos); maze[pos->x][pos->y] = 2;}
	else
		head->pos->dir++;*/
}

void printmaze(int maze[row][col])
{
	int i,j;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			printf(maze[i][j]);
}
int main()
{
	Node * head;
	head = (Node *) malloc (sizeof(Node));
	head->next = NULL;
	head->next = (Node *) malloc (sizeof(Node));
	head->next->pos.x=0;
	head->next->pos.y=0;
	position finalPosition;
	finalPosition.x = 5;
	finalPosition.y = 0;
	int Maze[row][col] ={	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
				 			1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,
				 			1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,1,
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
	while(1)
	{	
		if(head->next && head->next->pos != finalPosition)
			move(Maze,head);
		else
		{	printmaze(Maze);break;}
	}
}
