#include <iostream>
#include <vector>

using namespace std;

// 풀이
// 선행되는 작업은 모두 자신의 번호보다 작은 것들이고, 1번 작업은 무조건 선행작업없이 가능하다.
// 그러므로 1번부터 N번까지 순회를 돌며 작업 시간을 구하면 된다.
// 주어진 입력값들중 현재 작업 i의 선행작업이 모두 완료되어야 하기에 선행작업들중 가장 시간이 오래걸리는 작업 + i번의 작업시간을 구하면
// i번의 최종 작업시간이 나오며, 상술하였듯 N번까지 순회하여 가장 큰 작업시간을 출력하면 된다.

vector<vector<int>> board;
vector<int> answer;
int N;

void MakeAnswer()
{
    int max_time;
    for (int i = 1; i <= N; ++i)
    {
        max_time = 0;
        for (int j = 0; j < board[i].size(); ++j)
            max_time = max(max_time, answer[board[i][j]]);

        answer[i] += max_time;
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i)
        ans = max(ans, answer[i]);

    cout << ans << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.resize(N + 1, vector<int>());
    answer.resize(N + 1, 0);
    int time, num;
    for (int i = 1; i <= N; ++i)
    {
        cin >> time >> num;
        answer[i] = time;
        int first;
        for (int j = 0; j < num; ++j)
        {
            cin >> first;
            board[i].push_back(first);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}