#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 교환 논증을 이용한 그리디 문제다.
// 교환 논증이란 다음과 같다.

// 두 작업 A, B가 있을 때, A를 먼저 하는 것과 B를 먼저 하는 것 중 어느 것이 더 유리한지 비교해보면

// A 먼저 : A의 비용 = t_A × s_A, B의 비용 = (t_A + t_B) × s_B
// B 먼저 : B의 비용 = t_B × s_B, A의 비용 = (t_B + t_A) × s_A

// A를 먼저 하는 것이 유리하려면 :
// t_A × s_A + (t_A + t_B) × s_B < t_B × s_B + (t_A + t_B) × s_A
// 이를 정리하면 : t_A × s_B < t_B × s_A. 즉, t_A / s_A < t_B / s_B

// 그렇기에 결국 t / s가 작은 순으로 정렬하여 각 인덱스값을 출력하면 된다.

int N;
pair<double, int> board[1001];

bool SortFunc(const pair<double, int>& lhs, const pair<double, int>& rhs)
{
    if (lhs.first == rhs.first)
        return lhs.second < rhs.second;
    else
        return lhs.first < rhs.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int iter = 1; iter <= N; ++iter)
    {
        int t, s;
        cin >> t >> s;
        board[iter].first = static_cast<double>(t) / s;
        board[iter].second = iter;
    }
    sort(board + 1, board + N + 1, SortFunc);
    for (int iter = 1; iter <= N; ++iter)
        cout << board[iter].second << ' ';
    cout << '\n';
    return 0;
}