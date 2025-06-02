#ifndef CERERI_H
#define CERERI_H
#include<iostream>
#include <fstream>
using namespace std;


///todo: Cereri
//la un depozit sosesc, pe rand, n clienti care solicite fiecare o cant. data de vin. Butoiul din magazinul de servire(de capacitate nelimitata)
//este initial gol. Administratorul depozitului decide daca sa ii serveasca sau nu pe fiecare client in parte. Dupa ce pleaca un clientul refuzat,
//administratorul aduce in butoiul din magazin exact cantitatea solicitata de clientul respectiv.
//Sa se det. un mod de a rasp. solicitarilor a. i. cant. de vin vanduta sa fie maxima.

inline int s[10000], c[100]{0,8,1,4,9,4,6}, n = 6;

inline void solve() {
    int max = 0;
    for(int i = 1; i < 10000; i++) {
        s[i] = -1;
    }

    s[0] = 0;
    max = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = max; j >= 0; j--) {
            if(s[j] >= c[i] && s[j + c[i]] < s[j] - c[i]) {
                s[j + c[i]] = s[j] - c[i];
                if(j + c[i] > max) max = j + c[i];
            }
        }
        s[0] += c[i];
    }
    cout << max << endl;
}

///todo:camionul
//o pers. are la dispozitie un camion cu care poate trans o greutate Gmax si vrea sa efectueze un singur transport in urma
//caruia sa obtina un profit maxim. Pers. are n obiecte cunoscand greutatea si profitul fiecaruia.

inline int g[100], p[100], Gmax;
//s[10000], n;

inline void solve2() {
    int max, rez = 0;
    s[0] = max = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = max; j >= 0; j--) {
            if(s[j + g[i]] < s[j] + p[i]) {
                s[j + p[i]] = s[j] + p[i];

                if(j + g[i] > max) max = j + g[i];
            }
        }
    }

    for(int i = 0; i <= Gmax; i++) {
        if(rez < s[i]) rez = s[i];
    }
    cout << rez << endl;
}

//se considera o livada dreptunghiulara. In fiecare patrat al livezii se afla un pom din care pot cadea cateva mere. Un arici
//se afla in coltul din stanga sus al livezii si vrea sa ajunga in coltul din dreapta jos. El are voie sa se deplaseze in dreapta
//sau in jos. Care este nr. maxim de mere pe care le poate strange ariciul

inline int a[100][100], b[100][100], m;
//int n
inline void arici() {
    b[0][0] = a[0][0];
    for(int j = 1; j < m; j++) {
        b[0][j] = b[0][j - 1] + a[0][j];
    }

    for(int i = 1; i < n; i++) {
        b[i][0] = b[i - 1][0] + a[i][0];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            b[i][j] = max(b[i - 1][j], b[i][j - 1]) + a[i][j];
        }
    }
    cout << b[n - 1][m - 1] << endl;
}

inline void solve3() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    arici();
}

//se considera o mat binara. Numim patrat o multime de elem. ce formeaza un subtablou cu lat. egale. Sa se det. aria max. a unui
//patr. din matricea data

//int n,m, a[200][200]
inline void solve4() {
    ifstream fin("D:/info/c++/ProgramareDinamica/matrice.in");
    fin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            fin >> a[i][j];
        }
    }

    int rez = 0;

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(a[i][j] == 1) {
                if(a[i - 1][j] < a[i][j - 1]) {
                    a[i][j] = min(a[i - 1][j], a[i - 1][j - 1]) + 1;
                }
                else {
                    a[i][j] = min(a[i][j - 1], a[i - 1][j - 1]) + 1;
                }
            }

            if(rez < a[i][j]) rez = a[i][j];
        }
    }
    cout << rez * rez << endl;
}

//se considera 2 siruri de nr. nat. de lungime n, respectiv m. Sa se det. lungimea celui mai lung subsir comun

inline void cmlsc(int c[100][100]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i] == b[j]) {
                c[i][j] = c[i-1][j-1] + 1;
            }
            else {
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }
    cout << c[n - 1][m - 1];
}
#endif //CERERI_H
