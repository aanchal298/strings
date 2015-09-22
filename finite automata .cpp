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

int numChars = 256;

vector < vector <int> > statematch;
int nextState(string P, int state, int j)
{
    int lenpat = P.size();

    if(state < lenpat && P[state] == char(j))
    {
        ++state;
        return state;
    }

    for(int ns = state; ns > 0; ns--)
    {
        if(P[ns-1] == j)
        {   int i;
            for( i = 0 ; i<ns-1; i++)
                if(P[i]!=P[state-ns+1+i])
                    break;

            if(i == ns-1)
                return ns;
        }
    }

    return 0;
}

void evalStateFn( string P )
{
    int lenpat = P.size();

    statematch.resize(lenpat+1);

    for(int i = 0 ; i <= lenpat; i++)
    {   statematch[i].resize(numChars);
        fill(statematch[i].begin(), statematch[i].end(), 0);
    }

    for(int state = 0; state <= lenpat; state++)
        for(int j = 0 ; j<numChars; j++)
            statematch[state][j] = nextState(P,state,j);

}


int main()
{
    string T,P;

    cin>>T>>P;


    int n = T.size(), m = P.size();

    evalStateFn(P);


    for(int i = 0 ; i<=m; i++)
    {   cout<<i<<"          ";
        for(int j = 'a' ; j<'d'; j++)
            cout<<statematch[i][j]<<" ";
        cout<<endl;
    }

    int i, state = 0;
    for(int i = 0 ; i<n ; i++)
    {
        state = statematch[state][int(T[i])];
        if(state > 0)
            cout<<"\nprefix at "<<i<<endl;;
        //if(state == m)
          //  cout<<"pattern found at "<<i-m+1<<endl;

    }

	return 0;
}
