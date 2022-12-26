#include <iostream>
#include <vector>

using namespace std;

//풀이
//이 문제는 테트리스를 생각하면 비교적 이해하기 쉬웠다. N번째 큰수를 알기 위해서는 가장 큰수끼리 비교를 해야 했는데 마침 
//각 배열의 맨 아래에 있는 수들이 그 행에서 가장 큰수였기에 수월했다. 즉, 맨 밑 열을 순회하며 가장 큰수를 찾아 그 수를 제외한
//그 행의 모든 수를 한칸씩 아래로 내린다고 생각하고 계속 비교해낸다. 물론 이건 이해하기 쉽기 위한 개념을 풀어말한 것이며,
//실제 풀이에서는 각 열마다 현재 행을 추적하는 배열을 따로 만들어서 그 배열에 비교중인 값을 넣어두었다.

//정리하자면 하나에 배열에 현재 비교중인 각 행 번호를 넣어놓고 가장 큰수들을 비교해가며 가장 큰수가 존재하는 열의 행 번호를 하나씩
//줄여가며 N번째 큰수를 발견한다.

vector<vector<int>> board;
int N;

void MakeAnswer()
{
    vector<int> idx;
    for (int i = 0; i < N; ++i)
        idx.push_back(N - 1);

    int now, iter;
    for (int i = 0; i < N; ++i)
    {
        iter = 0;
        now = board[idx[0]][0];
        for (int j = 1; j < N; ++j)
            if (now < board[idx[j]][j])
            {
                iter = j;
                now = board[idx[j]][j];
            }
        --idx[iter];
    }

    cout << now << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}