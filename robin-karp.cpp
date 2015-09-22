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



int main()
{
	string str,pat;
	cin>>str>>pat;
	LL patnum = 0,strnum = 0;
    for(int i = 0 ; i<pat.size(); i++)
    {
        patnum = 10*patnum + pat[i]-'0';
    }

    if(pat.size() > str.size())
    {   cout<<"\n\nPATTERN MATCH UNSUCCESSFUL\n\n";
        return 0;
    }
    for(int i = 0 ; i<pat.size() ; i++)
    {
        strnum = strnum*10 + str[i]-'0';
    }
    if(strnum == patnum)
        cout<<"\n\nPATTERN MATCH SUCCESSFUL";
    else
    {   int m = pat.size();
        LL power = 1;
        for(int i = 0 ; i<m-1 ; i++)
            power*=10;
        for(int i = m ; i<str.size(); i++)
        {
            strnum = 10*( strnum - power* ( strnum / power ) ) + str[i]-'0';
            if(strnum == patnum)
            {   cout<<"\n\nPATTERN MATCH SUCCESSFUL\n\n";
                return 0;
            }
        }
        cout<<"\n\nPATTERN MATCH UNSUCCESSFUL\n\n";

    }


	return 0;
}
