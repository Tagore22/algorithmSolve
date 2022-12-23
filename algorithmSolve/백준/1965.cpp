#include <iostream>

using namespace std;

//풀이
//0번째 원소부터 idx-1까지 순회하며 idx보다 작으며 넣을수 있는 상자가 가장 많은 값 now를 찾으면 idx의 넣을수 있는 최대 상자값은 now+1이 된다.
//이걸 1번째 원소부터 모두 순회하여 각 원소별 최대값을 찾고, 마지막으로 다시 모든 원소를 순회하여 그중 가장 큰 최대값을 찾아 출력한다.
//연산량은 1~999이므로 49만 가량 된다.

int board[1000], cashe[1000];
int n;

void MakeAnswer()
{
    cashe[0] = 1;

    for (int i = 1; i < n; ++i)
    {
        int now = 0;
        for (int j = 0; j < i; ++j)
            if (board[j] < board[i] && cashe[j] > now)
                now = cashe[j];
        cashe[i] = now + 1;
    }

    int answer = 0;
    for (int i = 0; i < n; ++i)
        answer = max(answer, cashe[i]);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}