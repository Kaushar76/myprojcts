#include <iostream>
using namespace std;

int fact(int n) {
    int result = 1;
    for (int i = 1; i<=n; i++) {
        result = result * i;
    }
    return result;
}

int main() {
    int n,fac=1;
    cout << "Enter n: ";
    cin >> n;
    // for(int i=1;i<=n;i++){
    //     fac=fac*i;
    // }
    // cout<<fac;
    fac = fact(n);
    cout << fac;
    
    return 0;
}