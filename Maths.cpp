ll gcd(ll x,ll y) 
{ 
	if(y==0) return x; 
	return gcd(y,x%y); 
}

const ll M = MOD ; 
ll fact[mxN];
ll ifact[mxN];
 
ll modExp(ll a, ll p) {
	a %= M;
	ll res=1;
	while(p > 0) {
		if(p & 1) res = res * a % M;
		a = a * a % M; 
		p >>= 1;
	}
	return res;
}
ll modInv(ll a) {
	return modExp(a,M-2) % M ;
}
void pre() {
	fact[0] = 1 ;
	for(ll i = 1; i< mxN; i++) 
		fact[i] = i * fact[i-1] % M ;
 
	ifact[mxN-1] = modInv(fact[mxN-1]) ; 
	
	for(ll i = mxN-1 ; i>0 ; i--) 
		ifact[i-1] = ifact[i] * i % M ;
}
 
ll nCr(ll n, ll r) {
	if (n < r || r < 0 || n < 0) return 0;
	ll res = fact[n] * ifact[r] % M * ifact[n-r] % M ;
	return res ;
}

void add(ll &a, ll b) {
	b %= M;
	a = (a + b) % M;
}
void mul(ll &a, ll b) {
	b %= M;
	a = (a * b) % M;
}
void sub(ll &a, ll b) {
	b %= M;
	a = (a - b) % M;
	a = (a + M) % M;
}



const ll N = 1e6 + 1;
vector<bool> is_prime(N,1);
vll prime;
void sieve()
{
    for(ll i=2; i<N; i++)
    {
        if(is_prime[i])
        {
            prime.pb(i);
            for(ll j=2*i; j<N; j+=i)
                is_prime[j]=0;
        }
    }
	is_prime[1]=0;
	is_prime[0]=0;
}


vll phi(N);
void phi()
{
    for(ll i=0; i<N; i++) phi[i]=i;
    for(ll i=2; i<N; i++)
    {
        if(phi[i]==i)
        {
            for(ll j=i; j<N; j+=i)
                phi[j]-=phi[j]/i;
        }
    }
}


ll dearr[N];
void dearrange()
{
	ll p=1;
    for(ll i=1; i<N; i++)
    {
        if(i%2) p = (p - ifact[i] + M) % M;
        else p = (p + ifact[i]) % M;
        dearr[i] = fact[i] * p % M;
    }
}

// Faster Sieve
vector<bool> is_prime(mxN,1);
vector<int> prime;
void sieve()
{
    is_prime[0] = 0;
    is_prime[1] = 0;
    for(int i = 2; i < mxN; i++)
    {
        if(is_prime[i])
        {
            prime.pb(i);
        }
        for(int p: prime)
        {
            if(i*p >= mxN) break;
            is_prime[i*p] = 0;
            if(i%p == 0) break;
        }
    }
}


// ModInv using GCD when m is not prime but gcd(a,m) == 1
ll gcdExtended(ll a, ll b, ll* x, ll* y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
     
    // To store results of recursive call
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}

ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);

    // inverse doesn't exist
    if (g != 1) return -1;

    // m is added to handle negative x
    ll res = (x % m + m) % m;
    return res;
}
