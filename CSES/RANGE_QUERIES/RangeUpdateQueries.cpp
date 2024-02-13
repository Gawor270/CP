#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1651

// Using segment tree
std::vector<long long> tree;

long long val(int v, int tl, int tr, int l, int r){
    if(l <= tl && tr <= r)return tree[v];
    if(tr < l || r < tl)return 0;

    int md = (tl + tr)/2;
    long long sum = val(2*v,tl,md,l,r) + val(2*v+1,md+1,tr,l,r);
    return sum + tree[v];
}

void update(int v, int tl, int tr, int l, int r,int x){
    if(l <= tl && tr <= r){
        tree[v] += x;
        return;
    }
    if(tr < l || r < tl)return;

    int md = (tl+tr)/2;
    update(2*v, tl, md, l, r, x);
    update(2*v+1, md+1, tr, l, r, x);
}


int main(){
    int n,q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for(auto&x : a)std::cin >> x;

    while(__builtin_popcount(n) != 1){
        n++;
    }

    tree.resize(2*n,0);

    for(int i=0; i<(int)a.size(); i++){
        tree[n+i] = a[i];
    }

    // build 
    // for(int i= n-1; i>=1; i--){
    //     tree[i] = tree[2*i]  + tree[2*i+1];
    // }

    while(q--){
        int s;
        std::cin >> s;
        if(--s){
            int k;
            std::cin >> k;
            k--;
            std::cout << val(1,0,n-1,k,k) << "\n";
        }
        else{
            int a,b,u;
            std::cin >> a >> b >> u;
            update(1,0,n-1,a-1,b-1,u);
        }
    }



    return 0;
}

