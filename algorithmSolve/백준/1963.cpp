#include <iostream>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

//풀이
//주어지는 시작수 from부터 도착수 to까지 자리수 4개중 하나만 바꿔나간다. 다만, 이미 도달했던 수에 도달하는 경우에는 무한루프의 경우가 되기에
//따로 bool배열을 갱신해가며 사전에 방지한다.

bool board[10000], check[10000];
int T, from, to;

void Era() //에라토스테네스의 체.
{
    board[0] = board[1] = false;
    for (int i = 2; i <= 100; ++i)
        if (board[i])
        {
            for (int j = i * i; j <= 9999; j += i)
                board[j] = false;
        }
}

void BFS()
{
    memset(check, false, sizeof(check)); //테스트케이스가 여러개라 이곳에서 매번 방문한 수의 여부를 초기화해주어야한다.
    queue<pair<int, int>> que;
    que.push(make_pair(from, 0)); //초기값은 시작점과 0(변경한 횟수).
    check[from] = true;
    while (!que.empty())
    {
        int now = que.front().first;
        int num = que.front().second;
        que.pop();

        if (now == to)
        {
            cout << num << '\n';
            return;
        }

        for (int i = 0; i < 4; ++i)       //자리수 4개중 하나를 0~9로 바꾸어준다. 변경된 수가 이미 도달했거나, 1000~9999의 범위를 벗어났거나,
            for (int j = 0; j < 10; ++j)  //소수가 아니라면 무시하고 그 이외에는 큐에 넣는다.
            {
                string str = to_string(now);
                str[i] = j + '0';
                int next = stoi(str);

                if (check[next] || !board[next] || next < 1000 || 10000 <= next)
                    continue;

                check[next] = true;
                que.push(make_pair(next, num + 1));
            }
    }
    cout << "Impossible" << '\n';
}

void MakeAnswer()
{
    Era();
    for (int i = 0; i < T; ++i)
    {
        cin >> from >> to;
        BFS();
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(board, true, sizeof(board));

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}