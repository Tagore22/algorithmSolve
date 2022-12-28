#include <iostream>

using namespace std;

//풀이
//모든 배열을 순회하며 현 원소가 '-'일때에는 오른쪽이 '-'이라면 하나의 판자로 가능하기에 판자가 1개 덜들어가고,
//현 원소가 '|'일때에는 아래쪽이 '|'이라면 마찬가지로 하나의 판자로 가능하기에 1개가 덜들어간다.
//이런 방식으로 answer의 초기값은 N * M으로 한후 배열을 순회하여 남은 answer값을 출력하면 된다.

//P.S 알고리즘 분류를 보니 DFS, BFS인데 그걸로도 되나보다.

string board[50];
int N, M;

void MakeAnswer()
{
    int answer = N * M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] == '-' && j != M - 1)
            {
                if (board[i][j + 1] == '-')
                    --answer;
            }
            else if (board[i][j] == '|' && i != N - 1)
            {
                if (board[i + 1][j] == '|')
                    --answer;
            }
        }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}