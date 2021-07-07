//------------------------ Un, Deux, Trois, Quatre, Cinq -----------------------//
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

//Shorthands
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long 
#define ld long double
#define vll vector<ll>
#define vv vector<vll>
#define pb push_back
#define lb lower_bound2
#define ub upper_bound
#define pll pair<ll,ll>
#define vpll vector<pll>
#define ff first
#define ss second
#define tll tuple<ll,ll,ll>
#define vtll vector<tll> 
#define mt make_tuple
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define vect(a,n) vll a(n); rep(i,0,n) cin>>a[i];
#define all(a) a.begin(),a.end()
#define sortall(a) sort(a.begin(),a.end());
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));

//Debug
#define printv(a) rep(i,0,a.size()) cout<<a[i]<<" "; cout<<endl;
#define pout(p) cout<<"("<<p.ff<<","<<p.ss<<")"<<" ";
#define printvp(a) rep(i,0,a.size()) cout<<"("<<a[i].ff<<","<<a[i].ss<<")"<<" "; cout<<endl;
#define tout(t) cout<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")"<<endl;
#define trace(x) cout<< '>' << #x << ':' << (x) << "\n";
#define trace2(x,y) cout<< '>' << #x << ':' << (x) << " | " << #y << ':' << (y) << "\n";
#define trace3(a,b,c) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n";
#define trace4(a,b,c,d) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n";

//Constants
const ll INF = 1e12;
const ll MOD = 1e9 + 7;
const ll mod = 998244353;
const ll mxN = 1e5+1;

//Input-Output File
void fileio(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
}
//-------------------------- Six, Sept, Huit, Neuf, Dix ------------------------//

const ll M=MOD;
const ll N=11;
void multiply(ll mat[N][N],ll res[N][N])
{   
    ll temp[N][N];
    rep(i,0,N)
    {
        rep(j,0,N)
        {
            ll c=0;
            rep(k,0,N) c=(c+mat[i][k]*res[k][j]%M)%M;
            temp[i][j]=c;
        }
    }
    rep(i,0,N) rep(j,0,N) res[i][j]=temp[i][j];
}
void matrixExpo(ll mat[N][N], ll k)
{
    ll res[N][N];
    rep(i,0,N) 
    {
        rep(j,0,N) 
        {
            if(i==j) res[i][j]=1;
            else res[i][j]=0;
        }
    }
    while(k>0)
    {
        if(k&1) multiply(mat,res);
        k/=2;
        multiply(mat,mat);
    }
    rep(i,0,N) rep(j,0,N) mat[i][j]=res[i][j];
}


void solve() 
{
    ll n; cin>>n;
    vll a(n+1); 
    rep(i,1,n+1) cin>>a[i];
    vll c(11,0);
    rep(i,1,n+1) c[a[i]]++;

    ll q; cin>>q;
    while(q--)
    {
        ll k,r; cin>>k>>r;
        map<ll,ll> m;
        rep(i,0,k) 
        {
            ll x; cin>>x;
            if(x<=n) m[x]=1;
        }
        for(auto x:m) c[a[x.ff]]--;

        vll dp(11,0), s(11,0);
        rep(i,1,11) 
        {
            dp[i]=c[i];
            rep(j,1,11)
            {
                if(i-j<=0) break;
                dp[i]+=c[j]*dp[i-j]%M;
                dp[i]%=M;
            }
            s[i]=(s[i-1]+dp[i])%M;
        }
        for(auto x:m) c[a[x.ff]]++;

        if(r<=10){ cout<<s[r]<<endl; continue; }

        ll mat[11][11];
        mat[0][0]=1;
        mat[1][0]=0;
        rep(i,1,11) mat[0][i]=mat[1][i]=c[11-i];
        rep(i,2,11)
        {
            rep(j,0,11) mat[i][j]=0;
            mat[i][i-1]=1;
        }
        matrixExpo(mat,r-10);

        ll ans=mat[0][0]*s[10]%M;
        rep(i,1,11){ ans+=mat[0][i]*dp[11-i]%M; ans%=M; }
        cout<<ans<<endl;
    }
}


int main() 
{
	fastio; fileio();
 	solve();
}