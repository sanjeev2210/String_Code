#include<bits/stdc++.h>
#define pri 101
#define ll long long int
using namespace std;
ll calhash(string patt,ll len)
{
    ll hash=0;
    for(ll i=0;i<len;i++)
    {
        hash=hash+((int(patt[i]))*pow(pri,i));
    }
    return hash;
}
ll recalhash(string text,ll oldidx,ll newidx,ll oldhash,ll plen)
{
    ll newhash=oldhash-(int)text[oldidx];
    newhash=(newhash/pri);
    newhash=newhash+((int)text[newidx]*pow(pri,plen-1));
    return newhash;
}
bool checkequal(string txt,string pattern)
{
    return (txt==pattern)?1:0;
}
void rabkpsearch(string text,string patt)
{
    ll tlen=text.size();
    ll plen=patt.size();
    ll thash=calhash(text,plen);
    ll phash=calhash(patt,plen);
    bool flag=0;
    for(ll i=0;i<=tlen-plen;i++)
    {
        if(thash==phash && checkequal(text.substr(i,plen),patt))
        {
            flag=1;
            cout<<"Pattern found at index "<<i<<endl;
        }
        if(i<(tlen-plen))
        {
            thash=recalhash(text,i,i+plen,thash,plen);
        }
    }
    if(!flag)
    {
        cout<<"Pattern not found"<<endl;
    }
}
int main()
{
    string str,pattern;
    cin>>str>>pattern;
    rabkpsearch(str,pattern);
    return 0;
}
