#include<stdio.h> 
#include<string.h>  
int min_one(int left,int middle,int right); 
int compare_Distance(char strA[],char strB[]); 
int main() 
{   
	int distance; 
	char a[100],b[100]; 
	printf("��һ���ַ���:");
	gets(a);
	printf("�ڶ����ַ���:");
	gets(b);  //���������ַ���
	distance=compare_Distance(a,b); //����compare_Distance��������༭���� 
	printf("��С�༭����Ϊ:%d\n",distance);  
	return 0; 
}
  
int min_one(int left,int middle,int right)  
{  
	int min_one;   
	if(left<middle&&left<right) 
		min_one=left; //����ߵ�����С��һ��  
	else if(middle<right&&middle<left) 
		min_one=middle; //�м��һ������С��һ�� 
	else min_one=left; //�ұߵ�����С��һ��  
	return(min_one);  
}
  
int compare_Distance(char strA[],char strB[]) 
{ 
	int i,j;   
	int m=strlen(strA)+1;
	int n=strlen(strB)+1; 
	int L[100][100];  
	for( i=0;i<m;i++) //�����һ�еľ���Ϊ0��m-1 
	{ 
		L[i][0]=i; 
	}  
	for( j=0;j<n;j++) //�����һ�еľ���Ϊ0��n-1 
	{  
		L[0][j]=j; 
	}  
	for(i=1;i<m;i++) 
		for(j=1;j<n;j++) 
		{  if(strA[i-1]==strB[j-1]) 
		{
		  L[i][j]=L[i-1][j-1]; //�����ַ���ͬ�͵�����һ���ľ��롣
		}
		else   
			L[i][j]=min_one(L[i-1][j-1],L[i-1][j],L[i][j-1])+1; //��������ַ�����ͬ������ǰ������С��һ���ľ��롣 
		}  
		return L[m-1][n-1];  
}