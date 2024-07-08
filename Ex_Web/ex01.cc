#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m, a;
    cin >> n >> m >> a;

    long long ladrilhos;

    if ( n % a == 0 ){
       ladrilhos = n/a;
    } else {
       ladrilhos = ceil(n/a) + 1;
    }

    if ( m % a == 0) {
        ladrilhos *= m/a;
    } else {
        ladrilhos *= ceil(m/a) + 1;
    }

    cout << ladrilhos << endl;
}
