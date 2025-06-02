#ifndef SUBSIRMAXIMAL_H
#define SUBSIRMAXIMAL_H
#include <iostream>
using namespace std;

//se considera o val. nat. x si un sir A cresc. de n elem. nat. Sa se det. un subsir de lungime max. in car dif. intre oricare doua
//elem. alaturate este mai mare sau egala cu x
inline int n, Lm, p, x, L[101], v[101];

void dinamica() {
    L[1] = 1;
    for (int i = 2; i <= n; i++) {
        int max = 0;
        for(int j = 1; j < i; j++)
            if(L[j] > max && v[j] + x <= v[i])
                max = L[j];

        L[i] = max + 1;
        if(Lm < L[i]) {
            Lm = L[i];
            p = i;
        }
    }
}

void drum(int lm, int p, int urm) {
    if(!p)return;

    if(L[p] == lm && (urm == -1 || v[p] + x <= v[urm])) {
        drum(lm - 1, p - 1, p);
        cout << v[p] << " ";
    }
    else if(lm > 0) drum(lm, p - 1, urm);
}

void solve() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    dinamica();
    drum(Lm, p, -1);
}

//
#endif //SUBSIRMAXIMAL_H
