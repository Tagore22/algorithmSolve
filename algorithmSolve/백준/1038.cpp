#include <iostream>
#include <vector>
#include <queue>

//최초의 원소 0~9를 벡터에 넣고 그 수의 뒤에 수를 추가해 나간다.
//ex) 1 >>> 10
//다만 감소하는 수이기에 바로 앞자리보다 더 작은수들이 추가되어야 하기에
//현재 수를 10으로 나누어 가장 최근 수를 구해서 그 수보다 작은 수들로 채운다.
//또한, 가장 큰 감소하는 수인 9876543210보다 현재 수가 넘어 갔을때 혹은 큐가 비었을 때에는 그 수를 구하지 못한다.
//ex) 9876543210이 1022번째 수이기에 그보다 큰 1500등은 구할수가 없어 -1를 출력해야함.

using namespace std;

vector<long long> board;
int N;
const int MAXNUM = 1000000;

void CalFirst()
{
    queue<long long> que;
    for (int i = 0; i < 10; ++i)
    {
        board.push_back(i);
        que.push(i);
    }
    while (board.size() <= N && !que.empty())
    {
        long long now = que.front();
        que.pop();
        int div = now % 10;
        for (int i = 0; i < div; ++i)
        {
            long long next = now * 10 + i;
            que.push(next);
            board.push_back(next);
        }
    }
}

void MakeAnswer()
{
    CalFirst();
    if (board.size() - 1 >= N)
        cout << board[N] << '\n';
    else
        cout << -1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}