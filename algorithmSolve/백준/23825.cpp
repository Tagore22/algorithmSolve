#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    cout << min(N / 2, M / 2) << '\n';
    return 0;
}