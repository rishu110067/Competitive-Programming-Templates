// subset or subsequence with sum s possible or not
// dp - O(n*sum)

// recursive dp 
const ll S=2e5+1;
const ll N=101;
int dp[N][S];
int subset_sum(vll &a,ll n,ll s)
{
    if(s==0) return 1;
    if(n<=0) return 0;
    if(dp[n][s]!=-1) return dp[n][s]; 
    
    if(s<a[n-1])
        return dp[n][s]=subset_sum(a,n-1,s);
    else    
        return dp[n][s]=subset_sum(a,n-1,s)||subset_sum(a,n-1,s-a[n-1]);
}

//iterative dp
bool subset_sum(vll &a,ll n,ll s)
{
    bool dp[n+1][s+1];
    rep(i,0,n+1) dp[i][0]=true;
    rep(i,1,s+1) dp[0][i]=false;
    rep(i,1,n+1) 
    {
        rep(j,1,s+1)
        {
            if(j<a[i-1]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
        }
    }
    return dp[n][s];
}
