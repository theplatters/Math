//
// Created by franzs on 24.10.22.
//

int extendedGCD(int a, int b, int& x, int&y){
    // Base Case
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = extendedGCD(b%a, a, x1, y1);

    // Update x and y using results of
    // recursive call
    x = y1 - (b/a) * x1;
    y = x1;

    return gcd;
}
