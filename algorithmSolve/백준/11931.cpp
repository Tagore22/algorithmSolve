#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 문제 자체는 전혀 어렵지 않은 그냥 정렬만 하면 되는 문제다. 다만 N의 최대값이 100만으로 매우 크기 때문에
// 시간이 오래 걸린다. 우선순위 큐를 이용하기도 해보았으나 역시 한번에 정렬하는것이 더 빠르기 때문에
// 이 풀이가 그나마 더 빠른편이었다.

int N;
int board[1000000];

void MakeAnswer()
{
    sort(board, board + N, greater<>());
    for (int i = 0; i < N; ++i)
        cout << board[i] << '\n';
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