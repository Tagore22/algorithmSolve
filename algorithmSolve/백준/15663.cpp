#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

// 풀이.
// 어렵지는 않으나 하나를 못풀어서 좀 헤맨 문제다.
// 이 문제의 중요한 부분은 중복의 여부인데 이 중복이 2가지 경우가 있다.

// 1. 문제 예시 2번의 1, 9와 1, 9 처럼 두개의 원소가 같은 값을 가지고 있어서 중복을 일으키는 경우.
// 2. 9, 9 처럼 같은 값을 가지고 있으나 중복을 만들지 않는 경우.

// 이 2가지 경우에서 좀 헤맸다. 하나의 값을 가진 원소가 여러개여도 이번에 만드는 자리에서 여러개가 있다면 안되지만
// 이미 그중 한가지를 고른 상태에서는 상관이 없는 것이다.
// 여러 조건문을 구현하다가 결국 set을 사용해서 만들수 있는 모든 경우를 만든 후 중복 되는 경우를 거르기로 하였다.

// 자세한 설명은 주석으로 남긴다.

int board[8];
set<string> check;
bool visit[8];
int N, M;

// 문자열을 출력하는 함수.
void PrintAnswer(const string& str)
{
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == ' ')
        {
            cout << ' ';
            continue;
        }

        cout << str[i] - '0';
    }
    cout << '\n';
}

// 만들수 있는 모든 경우를 만드는 함수.
// 수열을 하나의 string으로 만들어서 다음 재귀때 넘긴다.
void BackTrack(int num, const string str)
{
    // M개의 원소를 골랐을때.
    if (num == M)
    {
        // 처음 만들어진것이라면 출력하고 set에 저장한다.
        if (check.find(str) == check.end())
        {
            PrintAnswer(str);
            check.insert(str);
        }
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        if (!visit[i])
        {
            visit[i] = true;
            BackTrack(num + 1, str + to_string(board[i]) + " ");
            visit[i] = false;
        }
    }
}

void MakeAnswer()
{
    sort(board, board + N);
    memset(visit, false, sizeof(visit));
    BackTrack(0, "");
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}