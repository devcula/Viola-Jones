#include<stdio.h>
#define array_value *(arr+(m-1)*size+n-1)
#define size 19
//Declarations of functions
void calc_features(double*,int,int);


void calc_features(double *arr,int p,int q)
{
	double result[63960][6]={0};
	int count_result=0;
	int i,j,w,h;
	//Storing Feature(a)
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=size;j++)
		{
			for(w=1;j+2*w-1<=size;w++)
			{
				for(h=1;i+h-1<=size;h++)
				{
					double s1=0,s2=0;
					int m,n;
					for(m=i;m<i+h-1;m++)
					{
						for(n=j;n<=j+w-1;n++)
						{
							s1+=array_value;
						}
						for(n=j+w;n<=j+2*w-1;n++)
						{
							s2+=array_value;
						}
					}
					result[count_result][0]=1;
					result[count_result][1]=i;
					result[count_result][2]=j;
					result[count_result][3]=w;
					result[count_result][4]=h;
					result[count_result][5]=s1-s2;
					count_result++;
				}
			}
		}
	}
	//Storing Feature(b)
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=size;j++)
		{
			for(w=1;j+3*w-1<=size;w++)
			{
				for(h=1;i+h-1<=size;h++)
				{
					double s1=0,s2=0,s3=0;
					int m,n;
					for(m=i;m<i+h-1;m++)
					{
						for(n=j;n<=j+w-1;n++)
						{
							s1+=array_value;
						}
						for(n=j+w;n<=j+2*w-1;n++)
						{
							s2+=array_value;
						}
						for(n=j+2*w;n<=j+3*w-1;n++)
						{
							s3+=array_value;
						}
					}
					result[count_result][0]=2;
					result[count_result][1]=i;
					result[count_result][2]=j;
					result[count_result][3]=w;
					result[count_result][4]=h;
					result[count_result][5]=s1-s2+s3;
					count_result++;
				}
			}
		}
	}
	//Storing Feature(c)
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=size;j++)
		{
			for(w=1;j+w-1<=size;w++)
			{
				for(h=1;i+2*h-1<=size;h++)
				{
					double s1=0,s2=0;
					int m,n;
					for(m=i;m<i+h-1;m++)
					{
						for(n=j;n<=j+w-1;n++)
						{
							s1+=array_value;
						}
					}
					for(m=i+h;m<i+2*h-1;m++)
					{
						for(n=j;n<=j+w-1;n++)
						{
							s2+=array_value;
						}
					}
					result[count_result][0]=3;
					result[count_result][1]=i;
					result[count_result][2]=j;
					result[count_result][3]=w;
					result[count_result][4]=h;
					result[count_result][5]=s1-s2;
					count_result++;
				}
			}
		}
	}
	//Storing Feature(d)
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=size;j++)
		{
			for(w=1;j+w-1<=size;w++)
			{
				for(h=1;i+3*h-1<=size;h++)
				{
					double s1=0,s2=0,s3=0;
					int m,n;
					for(m=i;m<i+h-1;m++)
					{
						for(n=j;n<=j+w-1;n++)
						{
							s1+=array_value;
						}
					}
					for(m=i+h;m<i+2*h-1;m++)
					{
						for(n=j;n<=j+w-1;n++)
						{
							s2+=array_value;
						}
					}
					for(m=i+2*h;m<i+3*h-1;m++)
					{
						for(n=j;n<=j+w-1;n++)
						{
							s3+=array_value;
						}
					}
					result[count_result][0]=4;
					result[count_result][1]=i;
					result[count_result][2]=j;
					result[count_result][3]=w;
					result[count_result][4]=h;
					result[count_result][5]=s1-s2+s3;
					count_result++;
				}
			}
		}
	}
	//Storing Feature(e)
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=size;j++)
		{
			for(w=1;j+2*w-1<=size;w++)
			{
				for(h=1;i+2*h-1<=size;h++)
				{
					double s1=0,s2=0,s3=0,s4=0;
					int m,n;
					for(m=i;m<i+h-1;m++)
					{
						for(n=j;n<=j+w-1;n++)
						{
							s1+=array_value;
						}
					}
					for(m=i+h;m<i+2*h-1;m++)
					{
						for(n=j;n<=j+w-1;n++)
						{
							s2+=array_value;
						}
					}
					for(m=i;m<i+h-1;m++)
					{
						for(n=j+w;n<=j+2*w-1;n++)
						{
							s3+=array_value;
						}
					}
					for(m=i+h;m<i+2*h-1;m++)
					{
						for(n=j+w;n<j+2*w-1;n++)
						{
							s4+=array_value;
						}
					}
					result[count_result][0]=5;
					result[count_result][1]=i;
					result[count_result][2]=j;
					result[count_result][3]=w;
					result[count_result][4]=h;
					result[count_result][5]=s1-s2-s3+s4;
					count_result++;
				}
			}
		}
	}
	FILE *fp;
	fp=fopen("features.txt","w");
for(i=0;i<63960;i++)
{
	for(j=0;j<6;j++)
	fprintf(fp,"%lf     ",result[i][j]);
	putc('\n',fp);
}
fclose(fp);
}


