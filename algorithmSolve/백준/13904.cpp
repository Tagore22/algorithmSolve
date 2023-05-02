#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// 풀이.
// 조금 복잡한 정렬문제다. 그다지 어렵지 않았으나 시간이 오래 걸렸다.
// 원리는 다음과 같다.

// 1. 최대한 많은 수의 과제를 풀어야 하기에 뒤에서부터(주어진 일수중 가장 큰수부터) 가능한 과제들을 해결한다.
// 2. 최대한 많은 점수를 획득해야 하기에 일자가 같을 경우 점수가 큰 순으로 선택한다.

// 위 원리에 의거하여 주어진 과제들을 점수가 큰순으로 점수가 같다면 남은 일수가 큰 순으로 정렬한다.
// 그 후 현재 일수와 같거나 더 큰 과제들중 점수가 큰 과제를 선택해야 한다. 다만 중복이 의미가 없기에
// 한번 선택된 과제는 삭제되어야 하는데, 나는 삭제의 처리가 복잡해질 것이기 때문에 따로 선택 여부를 체크하는
// bool 배열을 만들어 대체하였다. 즉, bool 원소가 true가 되어 있다면 이미 선택되었던 과제이기에
// 선택할수 없게 되는 것이다.

// 자세한 설명은 주석으로 남긴다.

bool check[1000];
pair<int, int> board[1000];
int N, day = 0;

// 과제들을 정렬하는 함수. 상술하였듯 점수가 큰순으로, 점수가 같다면 남은 일수가 큰순으로 정렬한다.
bool SortFunc(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
    if (lhs.second != rhs.second)
        return lhs.second > rhs.second;
    else
        return lhs.first > rhs.first;
}

void MakeAnswer()
{
    sort(board, board + N, SortFunc);
    memset(check, false, sizeof(check));

    int answer = 0;

    while (day > 0)
    {
        for (int i = 0; i < N; ++i)
            // 현재 일수보다 크거나 같으며 아직 선택되지 않은 과제들중 첫번째(점수가 큰순으로 정렬되었기에)
            // 과제를 선택한다.
            if (board[i].first >= day && !check[i])
            {
                answer += board[i].second;
                check[i] = true;
                break;
            }
        --day;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i].first >> board[i].second;
        day = max(day, board[i].first);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}