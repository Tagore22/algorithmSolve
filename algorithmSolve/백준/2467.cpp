#include <iostream>

using namespace std;

// 풀이.
// 오랜만에 투포인터 문제였다. 합의 절대값이 0에 가장 가까운 두 정수를 출력하는 문제이다.
// 큰 틀을 보자면 다음과 같다.

// 1. 두개의 위치 from과 to를 만든다. 시작점은 각각 0과 N - 1이다. 또한, 최소값 min_num과 그 때의 위치값 min_pos를 만든다.
// 초기값은 from과 to의 최초값과 그 합을 두면 된다.
// 2. from과 to의 합의 절대값이 0에 가장 가까워야하므로 from과 to를 더했을때 0보다 크다면
// 줄어들기 위해 to가 1 감소하고, 0보다 작다면 증가하기 위해 from이 1 증가한다. 만약 절대값이 0이라면 더이상의 순회가
// 필요하지 않으므로 min_pos값을 갱신하고 바로 반복문을 빠져나온다.
// 3. 2번을 반복하되 매번 from과 to의 합의 절대값과 min_num의 절대값과 비교하여 min_num의 절대값보다 작다면
// min_num 및 min_pos를 갱신해준다. 또한, 서로 다른 2개의 용액을 고르기 때문에 from이 to보다 같을수 없으므로
// from이 to보다 같지않고 작을때까지만 반복한다.(while문의 조건).

// 자세한 설명은 주석으로 남긴다.

int board[100000];
int N;

void MakeAnswer()
{
    // 두개의 위치 from과 to. 초기값은 상술하였듯 0과 N - 1이다.
    int from = 0;
    int to = N - 1;
    // 현재 0에 가장 가까운 값 min_num과 그때의 위치 min_pos.
    int min_num = board[from] + board[to];
    pair<int, int> min_pos = make_pair(from, to);
    int cur;

    // 상술하였듯 문제에 서로 다른 두개의 용액을 고른다고 나와있으므로, from은 to와 같아질수 없다.
    while (from < to)
    {
        // 현재 위치의 용액을 더해보고 그 절대값을 최소값과 비교하여 매번 갱신한다.
        cur = board[from] + board[to];
        if (abs(min_num) > abs(cur))
        {
            min_pos = make_pair(from, to);
            min_num = cur;
        }
        // 현재 값이 0보다 작다면 더 늘어나야하기에 from이 1 증가한다.
        if (cur < 0)
        {
            ++from;
        }
        // 현재 값이 0보다 크다면 더 줄어들어야하기에 to가 1 감소한다.
        else if (cur > 0)
        {
            --to;
        }
        // 0을 발견하였다면 더이상의 순회는 필요하지 않기에 위치값을 갱신하고 반복문을 
        // 탈출한다.
        else
        {
            min_pos = make_pair(from, to);
            break;
        }
    }
    cout << board[min_pos.first] << ' ' << board[min_pos.second] << '\n';
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