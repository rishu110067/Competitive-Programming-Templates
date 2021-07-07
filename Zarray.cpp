// Z array - z[i] tells max length prefix strating from i
vll Zarray(string s)
{
    ll n=s.size();
    vll z(n,0); z[0]=n;
    ll l=1, r=1;
    for(ll i=1; i<n; i++)
    {
        if(i>=r) l=i, r=i;
        ll x=i-l;
        if(i+z[x]>=r)
        {
            l=i;
            while(r<n && s[r]==s[r-l]) r++;
            z[i]=r-i;
        }
        else z[i]=z[x];
    }
    return z;
}


// alterante implementation
vector<int> Zarray(string s)
{
    int n = s.size();
    vector<int> z(n,-1);
    int L = 0, R = 0;
    for(int i = 1; i < n; i++) 
    {
        if(i > R) 
        {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            z[i] = R-L; 
            R--;
        }
        else 
        {
            int k = i-L;
            if(z[k] < R-i+1) z[i] = z[k];
            else 
            {
                L = i;
                while (R < n && s[R-L] == s[R]) R++;
                z[i] = R-L; 
                R--;
            }
        }
    }
    return z;
}

