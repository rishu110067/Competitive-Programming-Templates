struct VectorHasher {
    int operator()(const vector<ll> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};
 
unordered_map<vll,ll,VectorHasher> m;