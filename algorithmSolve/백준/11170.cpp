#include <iostream>

using namespace std;

// 풀이.
// 뭘 어떻게 풀어야할까 하다가 누적합으로 풀기로 했다. 최대 100만개에 길어야 최대 6번의 연산을 하기에
// 최대 연산량은 600만이 안되었다. 그렇기 때문에 미리 0 ~ 100만개의 0의 개수를 구해놓고
// [to] - [from - 1]을 구하여 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

// 0 ~ 100만을 담아야하기에 100만 1까지.
int board[1000001];
int T;

// 어떠한 수 num의 0의 개수를 구하는 함수.
int CalZero(int num)
{
    int ans = 0;
    while (num > 0)
    {
        if (num % 10 == 0)
            ++ans;
        num /= 10;
    }
    return ans;
}

// 0 ~ 100만까지의 0의 개수를 미리 구하는 함수.
void Init()
{
    int ans = 1;

    for (int i = 0; i <= 1000000; ++i)
    {
        ans += CalZero(i);
        board[i] = ans;
    }
}

void MakeAnswer()
{
    Init();
    int from, to;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> from >> to;
        cout << board[to] - board[from - 1] << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}