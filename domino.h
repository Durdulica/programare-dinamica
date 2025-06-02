#ifndef DOMINO_H
#define DOMINO_H
#include <iostream>
using namespace std;

//se considera un sir de n piese de domino. El se considera bine aranjat daca, pt. oricare 2 piese asezate consecutiv, patr.
//lor alaturate sunt mercae fie cu acelasi nr. de pct., fie suma acestora este egala cu 6
//Se de det. daca se poate obtine un sir bine ordonat, avand voie sa rotim piesele, dar sa lu ne schimbam locul in sir.

inline int n, i, j, p[100][3], t[100][2];
inline bool a[100][2];

//a[i][0] = true, daca se poate obtine un sir pana in poz. i cu piesa i nerotita si false, in caz contrar
//a[i][1] = true, daca se poate obtine un sir pana in poz. i cu piesa i rotita  si  false, in caz contrar

inline void domino() {
    for(int i = 2; i <= n; i++) {
        if((p[i][1] == p[i - 1][2] || p[i][1] + p[i - 1][2] == 6) && a[i - 1][0] == true) {
            a[i][0] = true;
            t[i][0] = 0;    //i nerotita si (i-1) nerotita
        }

        else if((p[i][1] == p[i - 1][1] || p[i][1] + p[i - 1][1] == 6) && a[i - 1][1] == true) {
            a[i][0] = true;
            t[i][0] = 1;    //i nerotita si (i-1) rotita
        }

        else if((p[i][2] == p[i - 1][2] || p[i][2] + p[i - 1][2] == 6) && a[i - 1][0] == true) {
            a[i][1] = true;
            t[i][1] = 0;    //i rotita si (i-1) nerotita
        }

        else if((p[i][2] == p[i - 1][1] || p[i][2] + p[i - 1][1] == 6) && a[i - 1][1] == true) {
            a[i][1] = true;
            t[i][1] = 1;    //i rotita si (i-1) rotita
        }
    }
}

inline void solve() {
    a[1][0] = true;
    a[1][1] = true;

    cout << " Enter the number of pieces: ";
    cin >> n;

    cout << "Enter the value of each piece: ";
    for(int i = 1; i <= n;i++) {
        for(int j = 1; j <= 2; j++) {
            cin >> p[i][j];
        }
    }

    domino();

    if(a[n][0] == true) {
        j = 1;
    }
    else {
        j = 0;
    }

    for(i = 1; i <= n; i++) {
        if(j == 0) {
            cout << p[i][1] << " " << p[i][2] << " ";
        }
        else {
            cout <<  p[i][2] << " " << p[i][1] << " ";
        }
        j = t[i][j];
    }
}
#endif //DOMINO_H
