#include <iostream>

using namespace std;

//예제를 보고 알수 있는 패턴은 대략 4가지인데
//1. N이 1개일때 = 무제한
//2. N이 2개일때
//2-1. board[0]과 board[1]이 같다면 앞으로도 계속 같기에 board[0]을 출력
//2-2. board[0]과 board[1]이 다르다면 무제한
//3. 그 이외에는 직접 값을 비교해봐야한다.

//a는 board[2] - board[1] / board[1] - board[0]으로 알수 있는데 이건 직접 계산해봐야한다.
//N이 3일때 첫번째 수를 x라고 두면 두번째 수는 ax + b 일테고 세번째수는 a(ax + b) + b가 된다.
//이걸 board[2] - board[1] / board[1] - board[0]하면 분자는 a((a-1)x + b)가 되고
//분모는 (a-1)x + b가 되어 나누면 a만 남는다.

//b는 앞서 구한 a를 이용해 board[1] - board[0] * a로 구하면 된다.

//이제 주어진 배열을 순회하며 이미 구한 a와 b를 이용하여 다음 원소와 비교한다.
//다만 한번이라도 값이 틀릴경우 답을 구할수 없는 경우이므로 B를 출력하고
//마지막 원소까지 다다를 경우 board[N-1] * a + b를 출력한다.

int board[50];
int N;

void MakeAnswer()
{
    if (N == 1)
    {
        cout << 'A' << '\n';
        return;
    }
    else if (N == 2)
    {
        if (board[0] == board[1])
            cout << board[0] << '\n';
        else
            cout << 'A' << '\n';
        return;
    }
    else
    {
        int a = 0;
        if (board[0] != board[1])
            a = (board[2] - board[1]) / (board[1] - board[0]);
        int b = board[1] - board[0] * a;

        for (int i = 1; i < N; ++i)
            if (board[i] != board[i - 1] * a + b)
            {
                cout << 'B' << '\n';
                return;
            }
        cout << board[N - 1] * a + b << '\n';
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