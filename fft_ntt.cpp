
// mod = 7340033 = 7*(2^20) + 1, root = 5, root_inv = 4404020, root_pw = 1 << 20, 
// mod = 998244353 = 7*17*(2^23) + 1, root = 3, root_inv = 332748118, root_pw = 1 << 23

const ll mod = 998244353;
const ll root = 3;
const ll root_1 = 332748118;
const ll root_pw = 1 << 23;

const ll M = mod ;
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

void fft(vector<ll> & a, bool invert) 
{
    ll n = a.size();

    for (ll i = 1, j = 0; i < n; i++) 
    {
        ll bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (ll len = 2; len <= n; len <<= 1) 
    {
        ll wlen = invert ? root_1 : root;
        for (ll i = len; i < root_pw; i <<= 1)
            wlen = (ll)(1LL * wlen * wlen % mod);

        for (ll i = 0; i < n; i += len) 
        {
            ll w = 1;
            for (ll j = 0; j < len / 2; j++) 
            {
                ll u = a[i+j], v = (ll)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (ll)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) 
    {
        ll n_1 = inverse(n, mod);
        for (ll & x : a)
            x = (ll)(1LL * x * n_1 % mod);
    }
    
}