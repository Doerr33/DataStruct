#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getnext(char *p,int *next)
{
	int len=strlen(p);
	int k=-1;
	int j=0;
	next[0]=-1;
	printf("\n j= %d next[0]%d",j,next[j]);
	while(j<len-1)
	{
		if(k==-1||p[k]==p[j])
		{
			k++;
			j++;
			next[j]=k;
			printf("\n j= %d next[%d]%d",j,j,next[j]);
					}
		else{
			k=next[k];
		}
		
	}
	
}
int kmp(char *s,char *p,int *next)
{
	int i = 0;
	int j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	while(i<sLen&&j<pLen) 
	{
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]    
			//next[j]即为j所对应的next值      
			j=next[j];
	}
		

	}
	if(j>=pLen)
		return(i-j);
	return 0;

} 
int main(){
	int next[50],n;
	char s[100] = "babababababababacabaabbababaabaababacabababababbcababbabababcababba";
    char p[50] = "ababacab";
    printf("\n实现如下:");
    printf("\n s[] =%s:",s);
    printf("\n p[] =%s:",p);
    getnext(p,next);
    n=kmp(s,p,next);
    printf("\n匹配的位置为 %d",n);
    return 0;
	 
} 
