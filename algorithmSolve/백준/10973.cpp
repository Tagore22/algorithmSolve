#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 사전순으로 오름차순으로 된 순열들을 만들때 현재 주어지는 순열의 이전 순열을 구하는 문제다.
// 복잡하게 일일이 구현할필요 없이 STL의 prev_permutation()을 이용하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[10000];
int N;

void MakeAnswer()
{
    // permutation 계열의 함수는 모두 bool을 반환한다. 다음 순열이 존재하면 true를, 존재하지 않는다면 false를 반환한다.
    // 이 문제에서는 이전 순열을 존재하는지를 반환한다.
    bool isFind = prev_permutation(board, board + N);

    // 이전 순열이 존재하면 출력한다.
    if (isFind)
    {
        for (int i = 0; i < N; ++i)
        {
            cout << board[i] << ' ';
        }
    }
    // 존재하지 않는다면 -1을 출력한다.
    else
    {
        cout << -1;
    }
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}