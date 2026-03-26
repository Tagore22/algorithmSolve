#include <iostream>

using namespace std;

int main()
{
    int N, C, P;
    cin >> N >> C >> P;

    cout << (N <= C * P ? "yes" : "no") << '\n';
    return 0;
}