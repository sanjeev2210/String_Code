#include<bits/stdc++.h>
using namespace std;
void kmp(char *txt,char *pat);
void computelps(int *arr,char *pat,int plen);
int main()
{
	int n,t,i,j;
	char txt[1234],pat[1234];
	cin>>txt;
	cin>>pat;
	kmp(txt,pat);
	return 0;
}

void kmp(char *txt,char *pat)
{
	int tlen=strlen(txt);
	int plen=strlen(pat);
	int *lps=(int*)malloc(sizeof(int)*plen);
	computelps(lps,pat,plen);
	int i=0,j=0;
	while(i<tlen)
	{
		if(pat[j]==txt[i])
		{
			i++;
			j++;
		}
		if(j==plen)
		{
			cout<<"pattern found at "<<i-j<<endl;
			j=lps[j-1];
		}
		else if(i<tlen && pat[j]!=txt[i])
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
	free(lps);
}

void computelps(int *lps,char *pat,int plen)
{
	int len=0,i;
	lps[0]=0;
	i=1;
	while(i<plen)
	{
		if(pat[i]==pat[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}









