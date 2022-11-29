#include <iostream>
#include <algorithm>

using namespace std;

int board[50];
int N;

//풀이
//y = |x| + |x-3| + |x-6| + |x-9|의 그래프에서 y값의 개수는 x절편값인 0, 3, 6 ,9를 오름차순 정렬하여 그 중앙값인 3부터 6임을 함수 그래프를 통해 알수 있다.
//또한 n이 홀수인 n차식에서는 그 중앙값이 단 한개뿐이기에 최소값 또한 한개다.

void MakeAnswer()
{
    sort(board, board + N);
    if (N % 2 == 1)
        cout << 1 << '\n';
    else
        cout << (board[N / 2] - board[N / 2 - 1] + 1) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        board[i] = a - b;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}