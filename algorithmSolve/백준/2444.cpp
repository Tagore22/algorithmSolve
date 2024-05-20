#include <iostream>

using namespace std;

// 풀이. 
// for문을 이용하여 N - 1칸만큼 공백을 출력하고 i * 2 - 1만큼 *을 출력한다.
// 그후 거꾸로 뒤집어 반복한다.

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N - i; ++j)
            cout << ' ';
        for (int j = 1; j <= i * 2 - 1; ++j)
            cout << '*';
        cout << '\n';
    }
    for (int i = N - 1; i > 0; --i)
    {
        for (int j = 1; j <= N - i; ++j)
            cout << ' ';
        for (int j = 1; j <= i * 2 - 1; ++j)
            cout << '*';
        cout << '\n';
    }
    return 0;
}