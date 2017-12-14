#include<bits/stdc++.h>
using namespace std;
int zarr[100005];
int calzarr(string text,string pattern)                      //this function calculates the z-array or z values of the concatenated string.
{
    string concatstr=pattern+"&"+text;  //concatenated string
    int len=concatstr.size();           //length of concatenated string
    int l,r,i,j,k;
    l=r=0;
    zarr[0]=0;
    for(k=1;k<len;k++)
    {
        if(k>r)
        {
            l=r=k;
            while(r<len && (concatstr[r]==concatstr[r-l]))
            {
                r++;
            }
            zarr[k]=r-l;
            r--;
        }
        else
        {
            i=k-l;
            if(zarr[i]<r-k+1)
            {
                zarr[k]=zarr[i];
            }
            else
            {
                l=k;
                while(r<len && concatstr[r]==concatstr[r-l])
                {
                    r++;
                }
                zarr[k]=r-l;
                r--;
            }
        }
    }
    return len;
}
void searchstr(string text,string pattern)                     //this function searches for the pattern in the text
{
    int len=calzarr(text,pattern);          //calculates the z values and return the length of the concatenated string;
    int t=pattern.size();
    //cout<<len<<" "<<t<<endl;
    for(int i=0;i<len;i++)
    {
        //cout<<zarr[i]<<" ";
        if(zarr[i]==t)
        {
            cout<<"pattern found at the index "<<(i-t)<<endl;
        }
    }
    //cout<<"NOT found"<<endl;
}
int main()
{
    string text,pattern;
    int i,j;
    cin>>text;
    cin>>pattern;
    searchstr(text,pattern);            //pattern is searched via this function
    return 0;
}
