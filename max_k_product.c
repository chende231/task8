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
	
	printf("���볤��: ");
	scanf("%d",&length);
	printf("�ֶθ���: ");
	scanf("%d",&k);
	printf("�������ִ�: ");
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
		sum = sum*10+(str[a]-'0');//��һ�а�������
		a++;
		i++;
	}
	return sum;
}

void maxi(int length,int k,char str[])
{
	int i,j,w;//w����λ��
	long temp=0,m;//temp��ʱ��������¼���ֵ��mΪ��������k�˻�
	long max[100][100];
	
	for(i = 1; i<=length; i++)//��һ�� 
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
					m = max[w][j-1]*conv(w,i-w,str);//���ֵ�ж����������ѭ�����ж�����k�˻�����¼8
					if(temp<m)//��¼k�˻�
					{
						temp = m;
					}
				}
				
				max[i][j] = temp;
			}
		}
	}
	printf("���k�˻�Ϊ: %ld\n",max[length][k]);
}