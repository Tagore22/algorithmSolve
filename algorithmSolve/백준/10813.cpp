#include <iostream>

using namespace std;

// 풀이.
// 주어지는 원소들의 값을 교환하는 문제다.
// 처음에는 1 ~ N번의 값이 들어가 있고
// 2개의 수 from, to가 M번 주어질때 board[from]과 board[to]의 값을
// M번 교환하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[101];
int N, M;

void MakeAnswer()
{
    int from, to;
    // M번만큼 from과 to가 주어졌을때 board[from]과 board[to]를 교환한다.
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        swap(board[from], board[to]);
    }

    // 결과 출력.
    for (int i = 1; i <= N; ++i)
        cout << board[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    // 초기값은 1 ~ N번임이 문제에서 주어졌다.
    for (int i = 1; i <= N; ++i)
        board[i] = i;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}