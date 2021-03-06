//A题首先将子集元素分类，分为1个元素的子集，2个元素的子集，3个元素的子集...
//然后对其进行dfs（深度优先搜索）即可。
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[10],n,k,pr[10];
void dfs(int pos,int num,int cnt) //pos表示在a数组中的位置，num表示需要多少个元素才满足，cnt表示用来存输出数组的下标
{
	if(num<=1)  //因为，dfs之前我们已经取了一个元素了，所以此时判断num<=1
	{
		for(int p=0;p<cnt;p++)
			p==0?printf("%d",pr[p]):printf(" %d",pr[p]);
		printf("\n");
		return ;
	}
	for(int j=pos+1;j<n;j++)  //说明还需要子集中还需要填充元素
	{
		pr[cnt]=a[j];    //将元素放在用来输出的数组中
		dfs(j,num-1,cnt+1); //继续调用dfs
	}
	return ;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		printf("\n");
		for(k=1;k<=n;k++)  //按照子集元素个数来输出
		{
			memset(pr,0,sizeof(pr));  //把数存在输出的数组里
			for(int j=0;j<n-k+1;j++)
			{
				pr[0]=a[j];
				dfs(j,k,1);  //dfs
			}
		}
	}
	return 0;
}
//此题虽然是递归的写法，但是涉及到了明天所要讲的内容，深度优先搜索（dfs）。
//所以大家尽量都将代码看懂，然后自己敲一遍来熟悉dfs，有助于明天的学习。