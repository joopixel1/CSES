#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>

using namespace std;
using ll = long long;

constexpr ll LL_SIZE = CHAR_BIT * sizeof(ll);

struct Node{
    ll val=0;
    Node* left;
    Node* right;
};

void insertTrie(Node* n, ll prexor){
    for(ll i = LL_SIZE-1LL; i >= 0LL; i--){
        ll direction = prexor & (1LL << i);
        if (direction) {
            if (!n->right) n->right = new Node();
            n = n->right;
        } else {
            if (!n->left) n->left = new Node();
            n = n->left;
        }
    }
    n->val = prexor;
}

ll queryTrie(Node* n, ll prexor){
    for(ll i = LL_SIZE-1LL; i >= 0LL; i--){
        ll direction = prexor & (1LL << i);
        if(direction) n = n->left ? n->left : n-> right;
        else n = n->right ? n->right : n-> left;
    }
    return n->val;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector< ll > v(n);
    for(ll i=0LL; i<n; i++) cin >> v[i];

    
    ll maxim = 0LL, prexor = 0LL;
    Node* root = new Node();
    insertTrie(root, prexor);
    for(ll i=0; i<n; i++){
        prexor ^= v[i];
        insertTrie(root, prexor);

        maxim = max(maxim, prexor^queryTrie(root, prexor));
    }

    cout << maxim << "\n";

    return 0;
}