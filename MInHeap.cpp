const ll MAX = 1e5 + 10;
ll a[6], b[MAX];
struct MinHeapNode 
{ 
    ll element;
    ll i;
    ll j;
}; 
void swap(MinHeapNode *x, MinHeapNode *y); 
class MinHeap 
{ 
    MinHeapNode *harr;
    ll heap_size;
public: 
    MinHeap(MinHeapNode a[], ll size); 
    void MinHeapify(ll ); 
    ll left(ll i) { return (2*i + 1); } 
    ll right(ll i) { return (2*i + 2); } 
    MinHeapNode getMin() { return harr[0]; } 
    void replaceMin(MinHeapNode x) { harr[0] = x; MinHeapify(0); } 
}; 
MinHeap::MinHeap(MinHeapNode a[], ll size) 
{ 
    heap_size = size; 
    harr = a;
    ll i = (heap_size - 1)/2; 
    while (i >= 0) 
    { 
        MinHeapify(i); 
        i--; 
    } 
} 
void MinHeap::MinHeapify(ll i) 
{ 
    ll l = left(i); 
    ll r = right(i); 
    ll smallest = i; 
    if (l < heap_size && 
        harr[l].element < harr[i].element) 
        smallest = l; 
    if (r < heap_size && 
        harr[r].element < harr[smallest].element) 
        smallest = r; 
    if (smallest != i) 
    { 
        swap(harr[i], harr[smallest]); 
        MinHeapify(smallest); 
    } 
} 