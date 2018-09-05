#include <iostream>

using namespace std;

const int N = 1000;
int p[11];
int r[N], s[N];

// initializer for prieces and optimal solutions
void init() {
    for(int i=0;i<=N;i++){

        r[i] = -1;
    }
    r[0] = 0;
    p[0] = 0;
    p[1] = 1;
    p[2] = 5;
    p[3] = 8;
    p[4] = 9;
    p[5] = 10;
    p[6] = 17;
    p[7] = 17;
    p[8] = 20;
    p[9] = 24;
    p[10] = 30;
}

// bottom-up solution that maintains not only the best price but also the "required cut" for such solution
int extendedButtomUpCutRod(int n) {
    if (r[n] != -1)
        return r[n];
    for (int j = 1; j <= n; ++j) {
        int q = -1000000;
        for (int i = 1; i <= j; ++i)
            if (q < p[i] + r[j - i]) {
                q = p[i] + r[j - i];
                s[j] = i;
            }
        r[j] = q;
    }
    return r[n];
}

// prins the extended method's output
void printCutRodSoln(int n) {
    do
        cout << s[n] << " ";
    while ((n -= s[n]) > 0);
}

int main() {
    init();
    int n;
    cout << "Enter Length of Rod. " << endl;
    cin >> n;

    cout << "Answer: " << endl;
    cout << extendedButtomUpCutRod(n) << endl;
    printCutRodSoln(n);
    return 0;
}
