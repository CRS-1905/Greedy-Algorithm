#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	char a[10];
	int s_t;
	int f_t;
}act;

act *num; 
int n;

void swap(int i,int j)
{
	char p[10];
	int q,r,k;

	for(k=0;k<10;k++)
		p[k]=num[i].a[k];
	q=num[i].s_t;
	r=num[i].f_t;

	for(k=0;k<10;k++)
		num[i].a[k] = num[j].a[k];
	num[i].s_t=num[j].s_t;
	num[i].f_t=num[j].f_t;

	for(k=0;k<10;k++)
		num[j].a[k]=p[k];
	num[j].s_t=q;
	num[j].f_t=r;
}

void sort()
{
	int i,j,t,largest,l,r;
	for (i = n / 2 - 1; i >= 0; i--)
	{
		largest = i;
		l = 2*i + 1;
		r = 2*i + 2;
		if (l < n && num[l].f_t > num[largest].f_t)
			largest = l;
		if (r < n && num[r].f_t > num[largest].f_t)
			largest = r;
		if (largest != i)
			swap(largest,i);
	}
	for(j=n-1;j>0;j--)
	{
		swap(j,0);
		t=0;
		while(t<j)
		{
			int l=2*t+1;
			if(l<j-1 && num[l+1].f_t>num[l].f_t)
				l++;
			if(l<j && num[l].f_t>num[t].f_t)
				swap(l,t);
			t=l;
		}
	}
}

int main()
{
	int i,s,j;
//	struct node *q;
	printf("Enter The Number Of Class :\t");
	scanf("%d",&n);
	num=(act *)malloc(n*sizeof(act));
	printf("Enter The Name Of The Class\tStarting Time Of The Class \t End Time Of The Class\n");
	getchar();
	for(i=0;i<n;i++){
		scanf("%s%d%d",num[i].a,&num[i].s_t,&num[i].f_t);
		getchar();
		}
	sort();
	for(i=0;i<n;i++)
	{
		printf("%s\t%d\t%d\n",num[i].a,num[i].s_t,num[i].f_t);
	}
	printf("\n");
	i=0;
	s=0;
	printf("The Activity Schedules ARE Given by :\n");
	while(i<n)
	{
		
		printf("%s\t%d\t%d\n",num[i].a,num[i].s_t,num[i].f_t);
		s++;
		for(j=i+1;j<n;j++)
		{
			if(num[j].s_t>=num[i].f_t)
				break;
		}
		i=j;
	}
	printf("Total Activity is :%d\n",s);
	
} 
