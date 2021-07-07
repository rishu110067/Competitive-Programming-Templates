ll current_answer;
ll cnt[mxN];
ll BLOCK_SIZE;

bool mo_cmp(pair<pll, ll> x, pair< pll, ll> &y)
{
    ll block_x = x.ff.ff / BLOCK_SIZE;
    ll block_y = y.ff.ff / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.ff.ss < y.ff.ss;
}

void add(int x)
{
    current_answer -= cnt[x] * cnt[x] * x;
    cnt[x]++;
    current_answer += cnt[x] * cnt[x] * x;
}

void remove(int x)
{
    current_answer -= cnt[x] * cnt[x] * x;
    cnt[x]--;
    current_answer += cnt[x] * cnt[x] * x;
}

void MOs_algo(vll &a, vector<pair< pll, ll>> &queries)
{
    ll n=a.size(), q=queries.size();
    BLOCK_SIZE = sqrt(n);
    sort(queries.begin(), queries.end(), mo_cmp);
    
    ll answers[q];
    ll mo_left = 0, mo_right = -1;
    rep(i,0,q) 
    {
        ll left = queries[i].ff.ff;
        ll right = queries[i].ff.ss;

        while(mo_right < right) {
            mo_right++;
            add(a[mo_right]);
        }
        while(mo_right > right) {
            remove(a[mo_right]);
            mo_right--;
        }
        while(mo_left < left) {
            remove(a[mo_left]);
            mo_left++;
        }
        while(mo_left > left) {
            mo_left--;
            add(a[mo_left]);
        }

        answers[queries[i].ss] = current_answer;
    }

    rep(i,0,q) cout << answers[i] << endl;
}