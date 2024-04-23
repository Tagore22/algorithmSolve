#include <iostream>

using namespace std;

// 풀이.
// 자칫 잘못하면 자기자신의 함정에 빠질수 있는 문제다. 나 또한 그러할뻔했다.
// 어렵게 생각하면 매우 어렵고, 쉽게 생각하면 매우 쉬운 문제다. 고기를 뒤집어서 격자안에
// 알맞게 배치하는 문제다. 처음에는 하나씩 뒤집어서 새로 격자에 채우는 방식을 생각했는데
// 한두끝이 없었다. 그런데 상술하였듯 쉽게 생각하면 매우 쉬운 문제다. 주어지는 상태 그대로 뒤집으면 된다.
// 가로로 뒤집어도 되며, 세로로 뒤집어도 된다. 맨 처음에 격자에 꼭 알맞게 주어지기 때문이다. 
// P.S 문제가 조금 독특하다 했는데 애드 혹이었다. 이번엔 이겨냈다.

// 자세한 설명은 주석으로 남긴다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, H, W;
    cin >> T;
    char board[11][11];
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> H >> W;
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j)
                cin >> board[i][j];

        // 주어지는 격자판을 뒤집어서 출력한다. 세로로도 되고 가로로도 된다.
        // 이 풀이에는 가로로 뒤집었다.
        for (int i = 0; i < H; ++i)
        {
            for (int j = W - 1; j >= 0; --j)
                cout << board[i][j];
            cout << '\n';
        }
    }
    return 0;
}