#include <iostream>

using namespace std;

// 27172번의 더 빠른 풀이. 기존 풀이가 나눗셈을 이용하였다면 아래 풀이는 곱셈을 이용하였다.
// 처음에 생각하기로는 나눗셈을 할때에는 제곱근의 수를 따르기 때문에 최대 1000이라 더 빠를줄 알았더니
// 오산이었다. 상술한대로 나눗셈을 기반으로 하였기 때문에 오히려 더 느렸다. 각 원소들의 최대값 maxnum을 구한후
// 모든 원소들의 순회하며 2이상부터 무제한으로 늘려가며 maxnum이하까지 곱해준다. 만약 그 수가 존재한다면 
// +-1 연산을 한다. 곱셈연산이 나눗셈연산보다 빠르다는걸 머리로는 알고 있으나 적용이 안되었다. 다시 한번 기억해두자.

// 자세한 설명은 주석으로 남긴다.

int board[100000], answer[1000001];
int N, maxnum = -1;

void MakeAnswer()
{
    // 각 모든 원소들을 순회하며 2이상부터 maxnum이하까지 무제한으로 곱해준다.
    // 이때 곱한 수가 존재한다면 +-1 연산을 한다.
    for (int i = 0; i < N; ++i)
    {
        for (int j = 2; j * board[i] <= maxnum; ++j)
        {
            if (answer[j * board[i]] != -987654321)
            {
                ++answer[board[i]];
                --answer[j * board[i]];
            }
        }
    }
    for (int i = 0; i < N; ++i)
        cout << answer[board[i]] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i <= 1000000; ++i)
        answer[i] = -987654321;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        answer[board[i]] = 0;
        maxnum = max(maxnum, board[i]);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}