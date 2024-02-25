#include <iostream>

using namespace std;

// 풀이.
// 배열을 생성하여 입력받은 수와 연동시키려 하였으나 범위가 -100 ~ 100이였다.
// 따라서 입력받은수 + 100을 배열과 연동시켜야했다.

int board[201];
int N, V;

int main()
{
    cin >> N;
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        ++board[num + 100];
    }
    cin >> V;
    cout << board[V + 100] << '\n';
    return 0;
}