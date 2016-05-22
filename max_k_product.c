#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 100

void maxi(int ,int ,char *);
int conv(int ,int ,char *);

void main()
{
	int length,k;
	char str[100];
	
	printf("输入长度: ");
	scanf("%d",&length);
	printf("分段个数: ");
	scanf("%d",&k);
	printf("输入数字串: ");
	fflush(stdin);
	gets(str);
	
	maxi(length,k,str);
}

long conv(int a,int b,char str[])
{
	long sum=0;
	int i=0;
	while(i<b)
	{
		sum = sum*10+(str[a]-'0');//第一列按序排列
		a++;
		i++;
	}
	return sum;
}

void maxi(int length,int k,char str[])
{
	int i,j,w;//w控制位数
	long temp=0,m;//temp临时变量，记录最大值，m为计算所得k乘积
	long max[100][100];
	
	for(i = 1; i<=length; i++)//第一列 
	{
		max[i][1] = conv(0,i,str);
	}
	for(j = 2; j<=k; j++)
	{
		temp = -1;
		for(i = 1; i<=length; i++)
		{
			if(j>i)
				max[i][j] = 0;
			else
			{
				for(w = j-1; w<i; w++)
				{
					m = max[w][j-1]*conv(w,i-w,str);//最大值有多种情况，用循环来判断最大的k乘积并记录8
					if(temp<m)//记录k乘积
					{
						temp = m;
					}
				}
				
				max[i][j] = temp;
			}
		}
	}
	printf("最大k乘积为: %ld\n",max[length][k]);
}