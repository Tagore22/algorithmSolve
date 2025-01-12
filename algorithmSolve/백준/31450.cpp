#include <iostream>

using namespace std;

int main()
{
    int M, K;
    cin >> M >> K;
    cout << (M % K == 0 ? "Yes" : "No") << '\n';
    return 0;
}