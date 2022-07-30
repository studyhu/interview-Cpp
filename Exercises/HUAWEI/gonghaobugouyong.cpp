#include <iostream>
#include <math.h>

using namespace std;

int main(){
    double x, y;
    cin >> x >> y;
    y = pow(26, y);
    double r = x/y;
    if(r<=1) cout << 1 <<endl;
    else{
        double res = log10(r);
        res = ceil(res);
        cout << res << endl;
    }
    return 0;
}