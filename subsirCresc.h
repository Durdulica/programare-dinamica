#ifndef ALGORITMI_H
#define ALGORITMI_H
#include<iostream>
using namespace std;

inline int n, Lm, L[101], v[101];

void dinamica() {
    L[n] = 1;
    for(int i = n - 1; i >= 1; i--) {
        int max = 0;
        for(int j = i + 1; j <= n; j++) {
            if(L[j] > max && v[i] <= v[j]) {
                max = L[j];
            }
        }
        L[i] = max + 1;
        if(Lm < L[i]) Lm = L[i];
    }
}

void drum() {
    int t = 0;
    int p = 1;
    do {
        while(L[p] != Lm || v[t] > v[p]) {
            p++;
        }
        cout << v[p] << " ";
        t = p;
        Lm--;
    }while(Lm);

}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    dinamica();
    drum();
}
#endif //ALGORITMI_H
