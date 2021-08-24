/*
Problem Name: Cut and Paste
Problem Link: https://cses.fi/problemset/task/2072
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct node {
    node *left, *right;
    int weight, size;
    char value;
    node(char v) {
        left = right = NULL;
        weight = rand();
        size = 1;
        value = v;
    }
};

int size(node *treap) {
    if (treap == NULL) return 0;
    return treap->size;
}

void split(node *treap, node *&left, node *&right, int k) {
    if (treap == NULL) {
        left = right = NULL;
    } 
    else {
        if (size(treap->left) < k) {
            split(treap->right, treap->right, right, k - size(treap->left)-1);
            left = treap;
        } 
        else {
            split(treap->left, left, treap->left, k);
            right = treap;
        }
        treap->size = size(treap->left) + size(treap->right) + 1;
    }
}

void merge(node *&treap, node *left, node *right) {
    if (left == NULL) treap = right;
    else if(right == NULL) treap = left;
    else {
        if (left->weight < right->weight) {
            merge(left->right, left->right, right);
            treap = left;
        } 
        else {
            merge(right->left, left, right->left);
            treap = right;
        }   
        treap->size = size(treap->left) + size(treap->right) + 1;
    }
}

void print(node *treap) {
    if (treap == NULL) return;
    print(treap->left);
    cout << treap->value;
    print(treap->right);
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    node *treap = 0;
    int n, m; cin >> n >> m;
    string s; cin >> s;
    for (auto i: s) {
        merge(treap, treap, new node(i));
    }

    while (m--) {
        int x, y; cin >> x >> y;
        node *A, *B, *C, *D;
        split(treap, A, B, x - 1);
        split(B, D, C, y - x + 1);
        merge(treap, A, C);
        merge(treap, treap, D);
    }
    print(treap);
}