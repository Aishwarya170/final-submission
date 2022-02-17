#include<stdio.h>
#include<stdlib.h>

struct node
{
int info;
struct node *link;
};

void display(struct node *);
struct node * insert(int, struct node *);
struct node * end(int, struct node *);
struct node * ord(int, struct node *);

void main()
{
struct node *first;
first=(struct node *)malloc(sizeof(struct node));

first->info=22;
first->link=NULL;
display(first);

first=insert(78,first);
first=insert(56,first);
first=insert(67,first);
printf("");
display(first);

first=end(89,first);
first=end(45,first);
printf("");
display(first);

first-ord(34,first);
printf("");
display(first);
}
void display(struct node *first)
{
struct node *temp;
temp=first;
while(temp!=NULL)
	{
	printf("%d",temp->info);
	temp=temp->link;
	}
}

struct node * insert(int x,struct node *first)
{
struct node *new;
new=(struct node *)malloc(sizeof(struct node));
if(new==NULL)
	{
	printf("overflow\n");
	return first;
	}
else
	{
	new->info=x;
	if(first==NULL)
		{
		new->link=NULL;
		return new;
		}
	else
		{
		new->link=first;
		return new;
		}
	}
}

struct node * end(int x,struct node *first)
{
struct node *new, *temp;
new=(struct node *)malloc(sizeof(struct node));
new->info=x;
new-> link=NULL;
if(first==NULL)
	{
	printf("underflow\n");
	return new;
	}
else
	{
	temp=first;
	while(temp->link!=NULL)
		{
		temp=temp->link;
		}
	temp->link=new;
	}
return first;
}

struct node * ord(int x,struct node *first)
{
struct node *new, *temp;
new=(struct node*)malloc(sizeof(struct node));
new->info = x;
if(first==NULL)
	{
	new->link=NULL;
	return new;
	}
else if(new->info < first->info)
	{
	new->link = first;
	return new;
	}
else
	{
	temp=first;
	while(temp->link!=0 && new->info > temp->info)
		{
		temp=temp->link;
		}
	new->link = temp->link;
	temp->link = new;
	}
return first;
}


