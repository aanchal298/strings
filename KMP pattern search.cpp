#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<climits>
#include<cstring>
#include<cmath>
#include<set>
#include<stack>
#include<string>
#include<map>

using namespace std;


#define VI vector<int>
#define VIT vector<int>::iterator
#define VLL vector<long long>
#define VLLT vector<long long>::iterator
#define all(v) v.begin(),v.end()
#define MID int mid = (ss+se)/2
#define FOR(i,n) for(int i = 0 ; i<n ; i++)
#define FORR(i,x,n,y) for(int i = x ; i<n ; i+=y)
#define SF(a) scanf("%d",&a)
#define LL long long
#define MOD 1000000007

#ifdef ONLINE_JUDGE
 inline void inp( int &n )
 {
    n=0;
    int ch=getchar();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}

    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar();
    n=n*sign;
  }
#else
inline void inp(int &n){
 cin>>n;
}
#endif

VI fail;

void failfn( string pat, int len_pat)
{   cout<<pat<<endl;
    int i = 1, j = 0 ;
    fail[0] = 0;

    while( i < len_pat )
    {
        if(pat[i] == pat[j])
        {
            j++;
            fail[i++] = j;
        }

        else if(j > 0 )
                j = fail[j-1];

        else if(j == 0)
                fail[i++] = 0;

    }
}

int KMPmatch(string text,int len_text, string pat,int len_pat)
{
    int i = 0 , j = 0;

    while(i < len_text)
    {
        if(text[i] == pat[j] )
        {
            if(j == len_pat-1)
                return i-len_pat+1;
            else
            {
                i++;
                j++;
            }
        }
            else
            {
                if(j>0)
                    j = fail[j-1];
                else
                    i++;
            }

    }

    return 0;

}
int main()
{
	string text, pat;
    cin>>(text);
    cin>>(pat);

    int len_text = text.size();
    int len_pat = pat.size();

    fail.resize(len_pat);

    failfn(pat,len_pat);

    FOR(i,len_pat)
        cout<<fail[i]<<" ";

    cout<<KMPmatch(text, len_text, pat, len_pat);
	return 0;
}
