#include <iostream>

using namespace std;

// 풀이.
// 처음에는 우선순위 큐를 이용하여 가장 긴 막대를 절반씩 나누어가며 구하려고 했는데
// 복잡하기만 하고 정확도도 떨어졌다. 이분 탐색으로 mid를 늘리거나 줄여가며 구하면 되었다.
// 다만, 과자길이의 총합이 M보다 작다면 아예 나누어줄수가 없기 때문에 0을 출력하여 예외를
// 처리하는것에 주의해야한다.

int board[1000000];
int M, N;
long long sum = 0;

// 길이 mid인 과자의 개수를 구하는 함수.
bool IsOverMid(int mid)
{
    int ans = 0;
    for (int i = 0; i < N; ++i)
        ans += board[i] / mid;
    return ans >= M;
}

void MakeAnswer()
{
    // 아예 과자를 나누어줄 수 없다면 0을 출력한다.
    if (sum < M)
    {
        cout << 0 << '\n';
        return;
    }
    // from을 0부터 시작했었는데 이러면 나중에 0을 나누게 되는 경우가 생긴다.
    // 따라서 1부터 시작해야함에 유의하자.
    int from = 1, to = 1000000001;
    while (from <= to)
    {
        int mid = (from + to) / 2;
        if (IsOverMid(mid))
            from = mid + 1;
        else
            to = mid - 1;
    }
    cout << from - 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        sum += board[i];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}