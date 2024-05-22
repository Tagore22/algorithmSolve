#include <iostream>

using namespace std;

// 풀이.
// 처음에는 잘못 계산해서 브루트포스로는 시간초과가 나오는 것으로 알았기에 다른 방법을 강구해내느라 시간을 좀
// 썼다. 그런데 이리 뒤집고 저리 뒤집는 방식이기에 결국 브루트포스를 이용하기로 했다. 가로 세로가 최대 1000이기에
// 모든 칸을 다돌아본다고 해도 연산량은 100만을 넘지 않기에 시간내에 충분히 풀수 있다. 그 후로는 그냥 주먹구구식으로
// 4변을 모두 돌며 계산하였다.

int main()
{
    int C, R, K;
    cin >> C >> R >> K;
    bool board[1001][1001] = { false, };
    if (C * R < K)
    {
        cout << 0 << '\n';
        return 0;
    }
    pair<int, int> pos = make_pair(1, 0);
    while (true)
    {
        for (int i = 0; i <= R; ++i)
        {
            if (K == 0)
            {
                cout << pos.first << ' ' << pos.second << '\n';
                return 0;
            }
            if (pos.second + 1 > R || board[pos.first][pos.second + 1])
                break;
            ++pos.second;
            board[pos.first][pos.second] = true;
            --K;
        }
        for (int i = 0; i <= C; ++i)
        {
            if (K == 0)
            {
                cout << pos.first << ' ' << pos.second << '\n';
                return 0;
            }
            if (pos.first + 1 > C || board[pos.first + 1][pos.second])
                break;
            ++pos.first;
            board[pos.first][pos.second] = true;
            --K;
        }
        for (int i = 0; i <= R; ++i)
        {
            if (K == 0)
            {
                cout << pos.first << ' ' << pos.second << '\n';
                return 0;
            }
            if (pos.second - 1 < 1 || board[pos.first][pos.second - 1])
                break;
            --pos.second;
            board[pos.first][pos.second] = true;
            --K;
        }
        for (int i = 0; i <= C; ++i)
        {
            if (K == 0)
            {
                cout << pos.first << ' ' << pos.second << '\n';
                return 0;
            }
            if (pos.first - 1 < 1 || board[pos.first - 1][pos.second])
                break;
            --pos.first;
            board[pos.first][pos.second] = true;
            --K;
        }
    }
    return 0;
}