#ifndef ETAPE_H
#define ETAPE_H
#include <iostream>
#include <fstream>
using namespace std;

inline int n, i, j, p, q, b[101][2], t[100][2], a[100][2];

inline void trace(int i, int j) {
    if(t[i][j] != 0 && i > 0 && j > 0) {
        trace(i - a[t[i][j]][0], j - a[t[i][j]][1]);
        cout << a[t[i][j]][0] << " " << a[t[i][j]][1] << endl;
    }
}

inline void etape() {
    int x = a[0][0];
    int y = a[0][1];
    b[x][y] = 1;
    t[x][y] = 1;

    for(i = 1; i < n; i++) {
        for(j = x; j >= 0; j--) {
            for(int k = y; k >= 0; k--) {
                if(b[j][k] != 0 && b[j + a[i][0]][k + a[i][1]] == 0) {
                    b[j + a[i][0]][k + a[i][1]] = b[j][k] + 1;
                    t[j + a[i][0]][k + a[i][1]] = i;
                }

                if(b[a[i][0]][a[i][1]] == 0) {
                    b[a[i][0]][a[i][1]] = 1;
                    t[a[i][0]][a[i][1]] = i;
                }

                x = x + a[i][0];
                y = y + a[i][1];
            }
        }
    }
}

inline void solve() {
    ifstream fin("matrice.in");

    fin >> n >> p >> q;

    for(int i = 0; i < n; i++) {
        fin >> a[i][0] >> a[i][1];
    }

    etape();
    trace(p, q);
}
#endif //ETAPE_H
