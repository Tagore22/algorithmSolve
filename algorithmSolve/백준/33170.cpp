#include <iostream>

using namespace std;

const int JACK = 21;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a + b + c <= JACK ? 1 : 0) << '\n';
    return 0;
}