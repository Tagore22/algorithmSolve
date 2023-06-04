#include <iostream>
#include <cstring>

using namespace std;

// 14225번의 다른 풀이.
// 이번에는 map이 아니라 bool배열로 수의 존재 여부를 체크했다.
// 최대 200만이라는 것에 지레 겁을 먹은듯하다.
// 속도도 더 빠르고 메모리도 더 적게 먹는다.

int board[20];
bool check[2000000];
int N;

void BackTrack(int idx, int sum)
{
    if (sum != 0)
        check[sum] = true;

    for (int i = idx + 1; i < N; ++i)
        BackTrack(i, sum + board[i]);
}

void MakeAnswer()
{
    memset(check, false, sizeof(check));
    BackTrack(-1, 0);
    int answer = 1;
    while (true)
    {
        if (!check[answer])
        {
            cout << answer << '\n';
            return;
        }
        ++answer;
    }
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