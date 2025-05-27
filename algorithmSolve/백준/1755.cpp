#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 전혀 어렵지 않은 문제였으나 정렬의 범위를 잘못 설정해서 있지도 않은 틀린 곳을 한참 찾았다.
// 범위 내의 수들을 순회하며 문자열로 바꾼후 pair<>에 넣어 정렬을 하고
// 10개마다 끊어서 출력하면 된다.

const int MAX = 100;
pair<string, int> board[MAX];
string alpha[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
int M, N;

void CheckStr(int num)
{
    string str = "";
    int idx = num;
    while (num >= 0)
    {
        int cur = num >= 10 ? num / 10 : num;
        str += alpha[cur];
        num = num >= 10 ? num % 10 : -1;
    }
    board[idx] = { str, idx };
}

void Solve()
{
    for (int i = M; i <= N; ++i)
        CheckStr(i);
    sort(board + M, board + N + 1);
    int jump = 0;
    for (int i = M; i <= N; ++i)
    {
        cout << board[i].second << ' ';
        ++jump;
        if (jump == 10)
        {
            cout << '\n';
            jump = 0;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;
}

int main()
{
    Input();
    Solve();
    return 0;
}