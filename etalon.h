#ifndef ETALON_H
#define ETALON_H
#include<iostream>
using namespace std;

//sa considera o multime de n etaloane de greutati cunoscute folosite petnru cantarirea cu ajutorul unui taler.
//sa se det.  o submult. de etaloane care pot fi folosite pt. masurarea unei greutati k

inline int n, k, a[10001], t[10001];
inline char s[10001];

inline void citire() {
    cout << " Enter the number of weights: ";
    cin >> n;
    cout << "Enter the value to scale: ";
    cin >> k;

    cout << "Enter the weights: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

inline void subm() {
    int mx = 0;
    s[0] = 1;
    t[0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = mx; j >= 0; j--) {
            if(s[j] && !s[j + a[i]] && j + a[i] <= k) {
                s[j + a[i]] = 1;
                t[j + a[i]] = a[i];

                if(j + a[i] > mx) mx = j + a[i];
            }
        }
    }
}

inline void drum(int k) {
    if(k != 0) {
        cout << t[k] << " ";
        drum(k - t[k]);
    }
}

inline void solve() {
    citire();
    subm();
    drum(k);
}
#endif //ETALON_H
