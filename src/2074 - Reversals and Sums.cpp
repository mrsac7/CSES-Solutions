/*
Problem Name: Reversals and Sums
Problem Link: https://cses.fi/problemset/task/2074
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct node {
    node *L, *R;
    int W, S, sm, V;
    bool F;
    node(int x) {
        L = R = 0;
        W = rand();
        S = 1;
        sm = x;
        V = x;
        F = 0;
    }
};

int size(node *treap) {
    return (treap == 0 ? 0 : treap->S);
}

int sum(node *treap) {
    return (treap == 0 ? 0 : treap->sm);
}

void push(node *treap) {
    if (treap && treap->F) {
        treap->F = 0;
        swap(treap->L, treap->R);
        if (treap->L) treap->L->F ^= 1;
        if (treap->R) treap->R->F ^= 1;
    }
}

void split(node *treap, node *&left, node *&right, int k) {
    if (treap == 0)
        left = right = 0;
    else {
        push(treap);
        if (size(treap->L) < k) {
            split(treap->R, treap->R, right, k - size(treap->L) - 1);
            left = treap;
        }
        else {
            split(treap->L, left, treap->L, k);
            right = treap;
        }
        treap->S = size(treap->L) + size(treap->R) + 1;
        treap->sm = sum(treap->L) + sum(treap->R) + treap->V;
    }
}

void merge(node *&treap, node *left, node *right) {
    if (left == 0) treap = right;
    else if (right == 0) treap = left;
    else {
        push(left);
        push(right);
        if (left->W < right->W) {
            merge(left->R, left->R, right);
            treap = left;
        }
        else {
            merge(right->L, left, right->L);
            treap = right;
        }
        treap->S = size(treap->L) + size(treap->R) + 1;
        treap->sm = sum(treap->L) + sum(treap->R) + treap->V;
    }
}

int find_sum(node *treap, int k) {
    if (treap == 0 || k == 0)
        return 0;
    else {
        push(treap);
        if (size(treap->L) < k) {
            return sum(treap->L) + treap->V + find_sum(treap->R, k - size(treap->L) - 1);
        }
        else {
            return find_sum(treap->L, k);
        }
    }
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    node *treap = 0;
    int n, m; cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        merge(treap, treap, new node(x));
    }

    while (m--) {
        int ch; cin >> ch;
        if (ch == 1) {
            int x, y; cin >> x >> y;
            node *A, *B, *C;
            split(treap, A, B, x - 1);
            split(B, B, C, y - x + 1);
            B->F ^= 1;
            merge(treap, A, B);
            merge(treap, treap, C);
        }
        else {
            int x, y; cin >> x >> y;
            cout << find_sum(treap, y) - find_sum(treap, x-1) << endl;
        }
    }
}