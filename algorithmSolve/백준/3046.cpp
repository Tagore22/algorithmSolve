#include <iostream>

using namespace std;

int main() //  s= (r1+r2)/2, 2s = r1+r2 r2 = 2s - r1
{
    int r1, s;
    cin >> r1 >> s;
    cout << s * 2 - r1;
    return 0;
}