#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 완전 탐색 문제지만, dp와는 다른 백트래킹 문제이다.
// 모든 순회가 끝났을때 최종값을 출력한다.

// 자세한 설명은 주석으로 남긴다.

int board[10];
int N, answer = 0;
bool check[10];

// 삭제되지 않은 가장 가까운 앞쪽의 원소값을 반환하는 함수.
int FindFront(int idx)
{
    while (true)
    {
        --idx;
        if (!check[idx])
            return idx;
    }
}

// 삭제되지 않은 가장 가까운 뒷쪽의 원소값을 반환하는 함수.
int FindBack(int idx)
{
    while (true)
    {
        ++idx;
        if (!check[idx])
            return idx;
    }
}

// 백트래킹 함수. 1번부터 N - 2번까지 아직 골라지지 않은(지워지지 않은) 번호를 하나씩
// 골라가며 에너지의 값을 증가시킨다. 이후 2개만 남았다면(맨 처음과 맨 마지막은 고를수 없기에) 현재 값을
// 최종값과 비교한다.
void BackTrack(int num, int sum)
{
    if (num == 2)
    {
        answer = max(answer, sum);
        return;
    }

    for (int i = 1; i < N - 1; ++i)
    {
        if (!check[i])
        {
            check[i] = true;
            int front = FindFront(i);
            int back = FindBack(i);
            BackTrack(num - 1, sum + board[front] * board[back]);
            check[i] = false;
        }
    }
}

void MakeAnswer()
{
    memset(check, false, sizeof(check));
    BackTrack(N, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}