#include <iostream>
#include <algorithm>

using namespace std;

//투포인터의 변형 문제. 조금만 더 응용한다면 더 쉽게 풀수 있다.

//풀이
//위 상술하였듯이 투포인터의 변형 문제이다. 모든 원소를 오름차순으로 정렬한뒤 첫번째 원소부터 고정한뒤 그 이후 범위의 원소들을 대상으로
//투포인터 연산을 시행하여 3개의 원소 값의 절대값이 가장 0에 근접한 경우의 수를 출력한다.
//또한, 3개의 원소 값의 합이 음수일때에는 0에 가까워지기 위해선 무조건 양수를 더해 수가 작아져야하므로 lo가 증가하고
//그 이외에는 hi가 감소한다.
//1. 합친값이 양수이며, 비교대상보다 큼 - 더 작아져야하는데 lo를 왼쪽으로 이동시켜봤자 전에 했던 연산을 반복할뿐임. 그러므로 hi를 왼쪽으로 이동
//2. 합친값이 양수이며, 비교대상과 같음 - 경우가 여러개일 경우 아무거나 출력해도 되므로 현재 상태를 무시하고 더 작은 값(0에 가까운 값)을 찾기 위해
//                                        더 작아져야하나, 위에 상수하였듯이 lo를 이동시켜봤자 기존의 연산을 반복할뿐임.
//3. 합친값이 양수이며, 비교대상보다 작음 - 현재 원소값들을 저장하고 다시 더 작은 값을 찾기위해 더 작아져야함. 다시 이동.

//투포인터의 연산은 두종류로 사용되는데 첫번째는 이번 문제처럼 2가지 원소를 골라서 하는 연산인데, 이것은 시작점이 맨 처음와 맨 끝이고
//두번째는 연속된 원소들을 이용하는 연산으로 이것은 맨첫번째 원소부터 lo와 hi가 겹쳐서 시작한다. 잊지 말자.

long long board[5000], answer[3];
int N;

void MakeAnswer()
{
    sort(board, board + N);
    long long min_num = 3000000001;

    for (int i = 0; i < N - 2; ++i)
    {
        int lo = i + 1;
        int hi = N - 1;

        while (lo < hi)
        {
            long long now = board[i] + board[lo] + board[hi];
            if (abs(now) < min_num)
            {
                answer[0] = board[i];
                answer[1] = board[lo];
                answer[2] = board[hi];
                min_num = abs(now);
            }

            if (now < 0)
                ++lo;
            else
                --hi;
        }
    }

    for (int i = 0; i < 3; ++i)
        cout << answer[i] << ' ';
    cout << '\n';
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