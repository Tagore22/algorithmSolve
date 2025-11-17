#include <iostream>
#include <deque>
#include <vector>

using namespace std;

// 풀이.
// 예전 삼성 문제 푸는 것 같다. 어려운 건 아니지만 여러개의 복잡한
// 연산들을 누더기 골렘처럼 엮어놨다. 벡터와 큐를 이용해서 풀었는데
// 회전시키는 톱니바퀴의 번호 num을 입력받아서 오른쪽, 왼쪽을 순회하며
// 맞닿는 부분이 같은 극인 최초의 번호를 찾아 그 이전까지 전부 회전시킨다.
// 그 이후 num번째 톱니바퀴를 회전시킨다. num번째 톱니바퀴를 맨 마지막에
// 홀로 회전시키는 이유는 왼쪽, 오른쪽을 순회할때 회전시키지 않은 상태여야
// 제대로 된 값을 찾을 수 있기 때문이다. 다만 코드가 너무 방대해진 감이 없지
// 않아 있다.

int T, K;
vector<deque<char>> board;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        string str;
        cin >> str;
        deque<char> cur;
        for (int j = 0; j < 8; ++j)
            cur.push_back(str[j]);
        board.push_back(cur);
    }
    cin >> K;
    for (int i = 0; i < K; ++i)
    {
        int num, dir;
        cin >> num >> dir;
        --num;

        int range = T - 1;
        for (int j = num + 1; j < T; ++j)
        {
            if (board[j][6] == board[j - 1][2])
            {
                range = j - 1;
                break;
            }
        }
        for (int z = num + 1; z <= range; ++z)
        {
            if (z % 2 == num % 2)
            {
                if (dir == 1)
                {
                    board[z].push_front(board[z].back());
                    board[z].pop_back();
                }
                else
                {
                    board[z].push_back(board[z].front());
                    board[z].pop_front();
                }
            }
            else
            {
                if (dir == 1)
                {
                    board[z].push_back(board[z].front());
                    board[z].pop_front();
                }
                else
                {
                    board[z].push_front(board[z].back());
                    board[z].pop_back();
                }
            }
        }
        range = 0;
        for (int j = num - 1; j >= 0; --j)
        {
            if (board[j][2] == board[j + 1][6])
            {
                range = j + 1;
                break;
            }
        }

        for (int z = num - 1; z >= range; --z)
        {
            if (z % 2 == num % 2)
            {
                if (dir == 1)
                {
                    board[z].push_front(board[z].back());
                    board[z].pop_back();
                }
                else
                {
                    board[z].push_back(board[z].front());
                    board[z].pop_front();
                }
            }
            else
            {
                if (dir == 1)
                {
                    board[z].push_back(board[z].front());
                    board[z].pop_front();
                }
                else
                {
                    board[z].push_front(board[z].back());
                    board[z].pop_back();
                }
            }
        }
        if (dir == 1)
        {
            board[num].push_front(board[num].back());
            board[num].pop_back();
        }
        else
        {
            board[num].push_back(board[num].front());
            board[num].pop_front();
        }
    }
    int ans = 0;
    for (int i = 0; i < T; ++i)
    {
        if (board[i][0] == '1')
            ++ans;
    }
    cout << ans << '\n';
    return 0;
}