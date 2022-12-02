#include <iostream>

using namespace std;

//오랜만에 백트래킹 문제라서 좀 헷갈린 감이 없지 않아 있었다. 감각을 잘 살릴것.

//풀이
//문제 특성상 어떤 원소는 더하고 어떤 원소는 제외하는 식으로 모든 경우의 수를 확인해봐야한다. 또한, N의 크기가 최대 20으로 적으므로 충분히 백트래킹으로 가능하다.
//주의할점은 내가 그랬는데, 마지막 원소에 도달하기 전에 S와 현재 sum값이 같아도 answer에 포함하면 안된다는 것이다. 3 0 0 0 0의 반례로 확인했을때 상술한것처럼
//풀면 아무것도 안더하고 2번째에서 하나 더한것과 그 이후 마지막까지 아무것도 더하지 않은 것이 결과적으로 같은 값이 되어 결과값이 겹쳐버린다. 그렇기에 맨 마지막 원소에
//도착할때까지 대기하다가 확인을 마지막에 단 한번 해야한다.

int board[20];
int N, S, answer = 0;

void CalAnswer(int sum, int idx, int num)
{
    if (idx > N)
        return;
    if (sum == S && num >= 1 && idx == N)
        ++answer;
    CalAnswer(sum, idx + 1, num); //현재 원소를 더하지 않았을 경우.
    CalAnswer(sum + board[idx], idx + 1, num + 1); //현재 원소를 더했을 경우.
}

void MakeAnswer()
{
    CalAnswer(0, 0, 0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}