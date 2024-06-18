#include <iostream>

using namespace std;

// 풀이.
// 모든 경우를 다 계산해보는 백트래킹 문제이다. 원래는 시작하는 idx값을 계산해서 무조건 중복되는값 없이 단순
// 재귀로만 풀려고 했는데 어디선가 중복이 된다. 결국 찾을수 없었고 bool 배열을 이용하여 걸러내기로 했다.
// 나중에 한번 더 생각해보아야겠다.

int N, answer = 0;
int board[4] = { 1, 5, 10, 50 };
bool check[10001] = { false, };

void BackTrack(int idx, int num, int sum)
{
    if (num == N)
    {
        if (!check[sum])
        {
            ++answer;
            check[sum] = true;
        }
        return;
    }

    for (int i = idx; i < 4; ++i)
        BackTrack(i, num + 1, sum + board[i]);
}

int main()
{
    cin >> N;
    BackTrack(0, 0, 0);

    cout << answer << '\n';
    return 0;
}