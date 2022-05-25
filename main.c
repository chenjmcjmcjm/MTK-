#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	unsigned i,j,c,d=0,start; //使用int 會溢位 
	int sum=0;
	long long bigsum[200];
	long long bigA[200];
	long long bigB[200];
	long long bigC[200];
	//清空 
	for(i=0;i<200;i++)
	{
		bigsum[i]=0;
		bigA[i]=0;
		bigB[i]=0;
		bigC[i]=0;
	}
	//  bigA跟 bigB放乘數被乘數  bigC 相乘的結果
	//  bigsum相加的結果 
	for(i=1;i<=10;i++)
	{
		c=1;
		//計算舉數 
		for(j=1;j<=i+1;j++)
		{
			c=c*j;
			
		}
		
		j--;
		//大數塞矩陣 
		svsenum(bigA,c);
	
		svsenum(bigB,c/j);
		//printf("\n");
		//相乘目前實作到9!*8!沒問題 
		Mulnum(bigC,bigA,bigB);
		//相加 
		addnum(bigsum,bigC);

		//清空函數 
		for(d=0;d<200;d++)
		{
			
			
			bigC[d]=0;
		} 
	
		//printf("\n");
		
	}
	//小海豹爛死 
	for(i=99;i>=0;i--)
	{
		if(bigsum[i]!=0)
		{
			start=i;
			break;
		}
	}
	//印出 
	printf("\nAns=");
	for(i=start;i>=0;i--)
	{
		printf("%d",bigsum[i]);
	}
	
	
	


	return 0;
}
void svsenum(int *S[],unsigned s){
	int c=0,i=0;
	while(s!=0)
	{
		S[c]=s%10;
		c++;
		s=s/10;
	}
	
/*	for(i=c;i>=0;--i)
	{
		printf("%d",S[i]);
	}
	printf("\n");*/
}
//乘法函數 
void Mulnum(int *c[],int *a[],int *b[])
{
	int i,j;
	int c1=0,c2=0,c3[200],sum=0,start,s=0;
	for(i=0;i<200;i++)
	{
		c3[i]=0;
	}
	for(i=0;i<99;i++)
		
		for(j=0;j<99;j++)
		{
			
			c1=a[i];
			c2=b[j];
			c3[i+j]=c[i+j];
			sum=(c1*c2)+c3[i+j];
			if(i+j==5) printf("i+j=%d,c1=%d,c2=%d,c3=%d,sum=%d,sum/10=%d,s=%d\n" ,i+j,c1,c2,c3[i+j],sum,sum/10,s);
			
				
				if (sum>=10)
				{
					if(c[i+j+1]!=0)
					{
						s=c[i+j+1];
						if(s%10>=10)
						{
							c[i+j+2]=s%10;
						}

						
					}
					c[i+j+1]=s+sum/10;
					
					c[i+j]=sum%10;
	
					
					
				}
				else
				{
					s=0;
					c[i+j]=sum;
				}
			
			
			
		}
	printf("\n");
	for(i=99;i>=0;i--)
	{
		if(c[i]!=0)
		{
			start=i;
			break;
		}	
	}
	for(i=start;i>=0;i--)
	{
		printf("%d",c[i]);
	}
	printf("\n");
	
	
}	

void addnum(int *S[],int *c[]) 
{
	int i=0,c1,c2,c3=0,sum=0;
	
	for(i=0;i<100;i++)
	{
		c1=S[i];
		c2=c[i];
		sum=(c1+c2+c3);
		if(sum<10)
		{
			S[i]=sum;
			c3=0;
		}
		else
		{
			S[i]=sum%10;
			c3=sum/10;
		}
	}
		
}


