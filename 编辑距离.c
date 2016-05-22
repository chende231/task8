#include<stdio.h> 
#include<string.h>  
int min_one(int left,int middle,int right); 
int compare_Distance(char strA[],char strB[]); 
int main() 
{   
	int distance; 
	char a[100],b[100]; 
	printf("第一个字符串:");
	gets(a);
	printf("第二个字符串:");
	gets(b);  //输入两组字符串
	distance=compare_Distance(a,b); //调用compare_Distance函数计算编辑距离 
	printf("最小编辑距离为:%d\n",distance);  
	return 0; 
}
  
int min_one(int left,int middle,int right)  
{  
	int min_one;   
	if(left<middle&&left<right) 
		min_one=left; //最左边的是最小的一个  
	else if(middle<right&&middle<left) 
		min_one=middle; //中间的一个是最小的一个 
	else min_one=left; //右边的是最小的一个  
	return(min_one);  
}
  
int compare_Distance(char strA[],char strB[]) 
{ 
	int i,j;   
	int m=strlen(strA)+1;
	int n=strlen(strB)+1; 
	int L[100][100];  
	for( i=0;i<m;i++) //定义第一行的距离为0到m-1 
	{ 
		L[i][0]=i; 
	}  
	for( j=0;j<n;j++) //定义第一列的距离为0到n-1 
	{  
		L[0][j]=j; 
	}  
	for(i=1;i<m;i++) 
		for(j=1;j<n;j++) 
		{  if(strA[i-1]==strB[j-1]) 
		{
		  L[i][j]=L[i-1][j-1]; //两个字符相同就等于上一个的距离。
		}
		else   
			L[i][j]=min_one(L[i-1][j-1],L[i-1][j],L[i][j-1])+1; //如果两个字符不相同，就是前三个最小的一个的距离。 
		}  
		return L[m-1][n-1];  
}