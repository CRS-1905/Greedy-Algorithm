#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
	char job;
	int time;
	int cost;
}node;
node *num;
float *a;
int n;

void swap(int i,int j)
{
	node c;
	c=num[j];
	num[j]=num[i];
	num[i]=c;
}
void sort()
{
	int i,j,smallest,l,r,t;	
	for (i = n / 2 - 1; i >= 0; i--)
	{
		smallest = i;
		l = 2*i + 1;
		r = 2*i + 2;
		if (l < n && a[l] < a[smallest])
			smallest = l;
		if (r < n && a[r] < a[smallest])
			smallest = r;
		if (smallest != i)
			swap(i,smallest);
	}

	for(j=n-1;j>0;j--)
	{
		swap(j,0);
		t=0;
		while(t<j)
		{
			l=2*t+1;
			
			if(l<j-1 && a[l+1]<a[l])
				l++;
			if(l<j && a[l]<a[t])
				swap(l,t);
			t=l;
		}
	}
}
int main()
{
	int i;
	printf("Enter The Number Of Tasks :\t");
	scanf("%d",&n);
	num=(node *)malloc(n*sizeof(node));
	a=(float *)malloc(n*sizeof(float));
	printf("Enter The Name Of The Job\tTimes Taken By It\tCost Of The job\n");
	getchar();
	for(i=0;i<n;i++)
	{
		scanf("%c%d%d",&num[i].job,&num[i].time,&num[i].cost);
		getchar();
	}
	for(i=0;i<n;i++)
		a[i]=num[i].cost/num[i].time;
	sort();
	printf("The schedules are given by :\n");
	for(i=0;i<n;i++)
		printf("job:%c\ttime:%d\tcost%d\n",num[i].job,num[i].time,num[i].cost);
	printf("\n");
}
