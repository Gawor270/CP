#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1649

// Using segment tree
std::vector<long long> tree;

long long minim(int v, int tl, int tr, int l, int r){
    if(l <= tl && tr <= r)return tree[v];
    if(tr < l || r < tl)return 1e9;

    int md = (tl + tr)/2;
    return std::min(minim(2*v,tl,md,l,r),minim(2*v+1,md+1,tr,l,r));
}

void update(int n,int v, int x){
    tree[n + v] = x;
    for(int j = (n+v)/2; j>=1; j/=2){
        tree[j] = std::min(tree[2*j],tree[2*j +1]);
    }
}


int main(){
    int n,q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for(auto&x : a)std::cin >> x;

    while(__builtin_popcount(n) != 1){
        a.push_back(1e9),n++;
    }

    tree.resize(2*n);

    for(int i=0; i<n; i++){
        tree[n+i] = a[i];
    }

    // build 
    for(int i= n-1; i>=1; i--){
        tree[i] = std::min(tree[2*i],tree[2*i +1]);
    }

    while(q--){
        int k,a,b;
        std::cin >> k >> a >> b;
        if(--k){
            std::cout << minim(1,0,n-1,a-1,b-1) << "\n";
        }
        else{
            update(n,a-1,b);
        }
    }



    return 0;
}

