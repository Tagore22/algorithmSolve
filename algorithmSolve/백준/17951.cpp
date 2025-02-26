#include <iostream>

using namespace std;

// 풀이.
// 주어진 것은 나눌 그룹의 개수 K와 각 시험지의 점수였다. 구해야하는 것은 순서가 변경되지 않은 상태에서
// K의 그룹으로 나눈 시험지의 최소값중 최대값이었으므로 매개 변수 탐색과 이분 탐색으로 구할수 있었다.
// 0과 모든 시험지의 총합 + 1을 시작으로 범위를 절반씩 줄여나간다. 중간값으로 K개의 그룹을 만둘수 있다면
// 범위를 큰쪽으로 옮기고 그렇지 못하다면 적은쪽으로 줄여나가면 된다.

int N, K, Sum = 0;
int Board[100000];

// 절반값 Mid가 주어질때 K개의 그룹을 구할수 있는지 확인하는 함수.
bool CheckNum(int Mid)
{
    int Cur = 0, Num = 0;
    for (int i = 0; i < N; ++i)
    {
        Cur += Board[i];
        // 현재 총합이 Mid보다 크다면 하나의 그룹을 만들고 총합을 0으로 초기화한다.
        if (Cur >= Mid)
        {
            ++Num;
            Cur = 0;
        }
    }
    return Num >= K;
}

void MakeAnswer()
{
    int From = 0, To = Sum + 1;
    while (From <= To)
    {
        int Mid = (From + To) / 2;
        if (CheckNum(Mid))
            From = Mid + 1;
        else
            To = Mid - 1;
    }
    // From == To인 마지막 순간에 성공한다면 From은 1이 증가한상태이기 때문에 -1을 해줘야하고
    // 실패한다면 From은 변화가 없으나 그 이전이 성공한 값이기 때문에 역시 -1을 해줘야한다.
    cout << From - 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> Board[i];
        Sum += Board[i];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}