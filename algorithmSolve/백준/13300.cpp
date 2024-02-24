#include <iostream>

using namespace std;

// 풀이.
// 각 학생의 성별과 학년이 주어질때 그만큼을 저장할수 있는 2차원 배열에 저장해놓는다.
// 저장이 모두 끝난 이후 다시 모든 배열들을 순회하며 각 학생들이 필요한 방을 구하는데
// 각 배열마다 원소값을 K로 나누고 만약 나머지가 존재한다면 1개의 방을 더 추가한다.

int board[2][7];
int N, K;

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < 2; ++i)
        for (int j = 1; j <= 6; ++j)
        {
            answer += board[i][j] / K;
            answer = board[i][j] % K == 0 ? answer : answer + 1;
        }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    int s, g;
    for (int i = 0; i < N; ++i)
    {
        cin >> s >> g;
        ++board[s][g];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}