#include <iostream>

using namespace std;

// 풀이.
// 첫번째 라운드에 모든 문을 열고 매 라운드시 해당 라운드수의 배수에 해당하는 방의 문을
// 열거나 닫는다. 모든 라운드 이후 열려있는 방의 개수를 센다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    bool board[101];
    int T, N;
    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N;
        for (int i = 1; i <= N; ++i)
            board[i] = true;
        for (int i = 2; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                if (j % i == 0)
                    board[j] ^= 1;
        int answer = 0;
        for (int i = 1; i <= N; ++i)
            if (board[i])
                ++answer;
        cout << answer << '\n';
    }
    return 0;
}