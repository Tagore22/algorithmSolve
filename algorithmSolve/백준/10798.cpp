#include <iostream>

using namespace std;

// 풀이.
// 평범한 순회 방향 문제이다.
// 다만 한가지 실수한점이 있는데 MakeAnswer()에서 2번째 for문에 있는 조건문이다.
// size()와 비교하기 때문에 한칸 적게 비교해야하는데 그 부분을 깜빡했다.
// 사소한 것에도 주의하자.

// 자세한 설명은 주석으로 남긴다.

string board[5];
int max_size = 0;

void MakeAnswer()
{
    for (int iter = 0; iter < max_size; ++iter)
        for (int i = 0; i < 5; ++i)
        {
            // 상술하였듯 이 부분에서 실수가 있었다. size()와 비교하기 때문에 iter와 같다면 출력할수 없다.
            if (board[i].size() <= iter)
                continue;
            cout << board[i][iter];
        }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; ++i)
    {
        cin >> board[i];
        int cur_size = board[i].size();
        max_size = max(max_size, cur_size);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}