#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 문제 자체는 어려운게 아니다. 말 그대로 다음 순열을 찾고 출력하되,
// 이번이 마지막 순열이라면 -1을 출력하면 된다. 다행히 STL에 다음 순열을 찾아주는 
// next_permutation()이 존재한다. 이 함수는 다음 순열이 존재할경우 현재 배열을 다음 순열로
// 재정렬하고, 이번이 마지막 순열일 경우 값은 바뀌되, false를 출력한다.

// bool next_permutation(~.begin(), ~.end())
// 다음 순열로 배열을 재정렬함. 이번 순열이 마지막 순열일 경우(재정렬했을때 값이 적어지는 경우)에는
// false를 반환한다. 시간복잡도는 많아야 모든 원소의 수 / 2이다.

// 이것만 알면 사실 어려울게 없는 문제다. 하지만 이것을 모르면 조금 복잡했을 것 같다.

// 자세한 설명은 주석으로 남긴다.

int board[10000];
int N;

void MakeAnswer()
{
    // 다음 순열로 재정렬했을때 무엇을 반환하는가.
    bool isEnd = next_permutation(board, board + N);

    // true라면 다음 순열이 존재함으로 재정렬된 배열을 출력함.
    if (isEnd)
    {
        for (int i = 0; i < N; ++i)
            cout << board[i] << ' ';
    }
    // false라면 이번 순열이 마지막 순열이었으므로 -1을 출력함.
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
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}