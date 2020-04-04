#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
	char alp;
	int freq;
	struct node *left;
	struct node *right;
};

struct node **num;

struct node1
{
	struct node *s1;
	struct node1 *next;
};
struct node1 *s;

struct node2
{
	struct node *s1;;
	char *code;
	int s_code;
	struct node2 *next;
};
struct node2 *r;
int n;

void push(int i)
{
	struct node1 *q,*new;
	new=(struct node1 *)malloc(sizeof(struct node1));
	new->s1=num[i];
	new->next=NULL;
	if(s==NULL)
		s=new;
	else
	{
		q=s;
		s=new;
		new->next=q;
	}
}

void insert(struct node *c)
{
	struct node1 *new,*q,*q1;
	int count;
	new=(struct node1 *)malloc(sizeof(struct node1));
	new->s1=c;
	new->next=NULL;
	if(s==NULL)
		s=new;
	else
	{
		q=s;
		q1=q->next;
		if(new->s1->freq <= q->s1->freq)
		{
			new->next=s;
			s=new;
		}
		else
		{
			count=1;
			while(q1!=NULL)
			{
				if(q1->s1->freq > new->s1->freq)
				{
					count=0;
					q->next=new;
					new->next=q1;
					q1=NULL;
				}
				else
				{
					q=q->next;
					q1=q1->next;
				}
			}
			if(count==1)
				q->next=new;
		}
	}
	
	
}

void swap(int i,int j)
{
	struct node *q;
	q=(struct node *)malloc(sizeof(struct node));
	q->alp=num[i]->alp;
	q->freq=num[i]->freq;
	q->left=num[i]->left;
	q->right=num[i]->right;

	num[i]->alp=num[j]->alp;
	num[i]->freq=num[j]->freq;
	num[i]->left=num[j]->left;
	num[i]->right=num[j]->right;

	num[j]->alp=q->alp;
	num[j]->freq=q->freq;
	num[j]->left=q->left;
	num[j]->right=q->right;
	
}
void sort()
{
	int i,j,k,l,r,t,p,smallest;
	for(k=0; k<=n/2-1;k++)
		for (i=(n/2)-1;i>=k;i--)
		{
			smallest = i;
			l = 2*i + 1;
			r = 2*i + 2;
			if (l < n && num[l]->freq< num[smallest]->freq)
				smallest = l;
			if (r < n && num[r]->freq < num[smallest]->freq)
				smallest = r;
			if (smallest != i)
				swap(smallest,i);
		}
	for(j=n-1;j>0;j--)
	{
		swap(j,0);
		t=0;
		while(t<j)
		{
			int l=2*t+1;
			if(l<j-1 && num[l+1]->freq < num[l]->freq)
				l++;
			if(l<j && num[l]->freq<num[t]->freq)
				swap(l,t);
			t=l;
		}
	}
}

void insert1(struct node *a,char *c,int n1)
{
	struct node2 *new,*q;
	new=(struct node2 *)malloc(sizeof(struct node2));
	new->s1=a;
	new->code=c;
	new->s_code=n1;
	new->next=NULL;
	if(r==NULL)
		r=new;
	else
	{
		q=r;
		while(q->next!=NULL)
			q=q->next;
		q->next=new;
	}
}

struct node2 *pop()
{
	struct node2 *new;
	int i;
	new=(struct node2 *)malloc(sizeof(struct node2));
	new->s1=r->s1;
	new->code=r->code;
	new->s_code=r->s_code;
	new->next=NULL;
	r=r->next;
	return new;	
}

char *append(char i,char *a,int n1)
{
	char *a1;
	int j;
	a1=(char*)malloc((n1+1)*sizeof(char));
	for(j=0;j<n1;j++)
		a1[j]=a[j];
	a1[n1]=i;
	return a1;
}

void huffman()
{
	int i;
	struct node2 *q1;
	while(r!=NULL)
	{
		q1=pop();
		if(q1->s1->left!=NULL && q1->s1->right!=NULL)
		{
			insert1(q1->s1->left,append('0',q1->code,q1->s_code),q1->s_code+1);
			insert1(q1->s1->right,append('1',q1->code,q1->s_code),q1->s_code+1);
		}
		else
		{
			printf("the alphabet is %c\tand the code is :\t",q1->s1->alp);
			for(i=0;i<q1->s_code;i++)
				printf("%c",q1->code[i]);
			printf("\n");
		}
	}
}

int main()
{
	int i;
	char z;
	struct node *a,*c,*b;
	printf("Enter The Number Of The Alphabets :\t");
	scanf("%d",&n);
	num=(struct node **)malloc(n*sizeof(struct node *));
	printf("Enter The Alphabet And Corresponding Frequency :\n");
	for(i=0;i<n;i++)
	{
		num[i]=(struct node *)malloc(sizeof(struct node));
		getchar();	
		scanf("%c%d",&num[i]->alp,&num[i]->freq);
		num[i]->left=NULL;
		num[i]->right=NULL;
	}
	sort();
	for(i=0;i<n;i++)
	{
		printf("%c\t%d\n",num[i]->alp,num[i]->freq);
	}
	printf("\n");
	s=NULL;
	for(i=0;i<n;i++)
	{
		push(i);
	}
	while(s->next!=NULL)
	{
		a=s->s1;
		s=s->next;
		b=s->s1;
		s=s->next;
		c=(struct node *)malloc(sizeof(struct node));
		c->alp=z;
		c->freq=a->freq + b->freq;
		c->left=a;
		c->right=b;
		insert(c);
	}
	r=NULL;
	char *ch;
	ch=(char *)malloc(sizeof(char));
	i=1;
	ch[0]='0';
	insert1(s->s1,ch,i);
	huffman();
	
	
}
