#include <iostream>
#include <cmath>

using namespace std;

// 풀이.
// 문제를 보자마자 투포인터가 떠올랐다. 그런데 예전에 풀어서인지 명확하게 기억이 나지 않아
// 떠올리지 못했다. 여기서 다시 한번 정리를 해보자. 투포인터는 크게 2가지 경우에 쓰인다.

// 1. 두 원소의 합.
// 2. from ~ to의 부분합.

// 모두 정렬되어 있어야함은 일치한다. 첫번째는 두 첫번째 원소 from과 마지막 원소 to에서 시작한다.
// 주어진 목표값이 N이라 할때 N보다 작으면 더 커져야하니 from을 1 증가시키고 N보다 크면
// 더 작아져야 하니 to를 1 감소시킨다. N과 같으면 답을 1 증가시킨다. 이것은 배열이 2개거나 1개거나
// 동일하다.
// 두번째는 첫번째 원소에서 from과 to가 시작된다. 상술하였듯 from ~ to의 부분합이기에 초기값은
// from값 하나로 시작하며 합이 주어진 목표값 N보다 작으면 to값을 늘리고 N보다 크면 from값을 제거하여
// 범위를 줄인다.

// 어렵지 않은 개념이니 다시 한번 잘 외워두자.

// 자세한 설명은 주석으로 남긴다.

int board[100000];
int N, answer = 2100000000;

void MakeAnswer()
{
    // 두 값의 합이 0에 최대한 도달하여야 한다.
    // 따라서 양끝에서 시작한다.
    int from = 0, to = N - 1;
    while (from < to)
    {
        int next = board[from] + board[to];
        // 두 값이 0보다 작다면 값을 키워야함으로 시작값을
        // 1 증가시킨다.
        if (next < 0)
        {
            ++from;
        }
        // 0보다 크다면 줄여야함으로 끝값을 1 감소시킨다.
        else if (next > 0)
        {
            --to;
        }
        // 0이라면 0을 출력하고 탈출한다.
        else
        {
            cout << 0 << '\n';
            return;
        }
        // 절대값이 0에 가장 가까운수로 갱신한다.
        answer = abs(next) < abs(answer) ? next : answer;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

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