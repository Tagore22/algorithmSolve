#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//재귀형 DP풀이. 나에게는 좀더 직관적이나 용량도 더 많이 들고, 더 느리다

//풀이
//N을 넘지 않는 모든 제곱수들을 구해놓고, num에서 뺄수 있는 모든 경우의 수들을 빼나간다. 0이 되면 더이상 함수를 호출할수 없기에 0을 반환하며
//DP를 사용하여 최대 10만의 연산량을 가진다.

vector<int> board, cashe;
int N;

int DP(int num)
{
    if (num == 0)
        return 0;

    int& ans = cashe[num];
    if (ans != -1)
        return ans;

    ans = 100001;
    int idx = distance(board.begin(), upper_bound(board.begin(), board.end(), num));
    for (int i = 0; i < idx; ++i)
        ans = min(ans, DP(num - board[i]) + 1);

    return ans;
}

void MakeAnswer()
{
    int sqrt_num = sqrt(N);
    for (int i = 1; i <= sqrt_num; ++i)
        board.push_back(i * i);

    int answer = DP(N);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cashe.resize(N + 1, -1);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}