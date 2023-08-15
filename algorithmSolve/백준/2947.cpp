#include <iostream>

using namespace std;

// 풀이.
// 간단한 문제이다. 현재수와 다음수 비교하여 현재수가 클경우 다음수와 바꾸며
// 4번째 수까지 이동한다. 그후 1, 2, 3, 4, 5로 정렬되었다면 반복을 끝내고,
// 그렇지 않다면 다시 반복한다. 한가지 주의할점은 두 수가 바뀔때만 5개의 수를 출력한다는 것이다.
// 이것을 헷갈려서 틀릴뻔했다.

// 자세한 설명은 주석으로 남긴다.

int board[5];
int ans[5] = { 1, 2, 3, 4, 5 };

void MakeAnswer()
{
    // 수가 1, 2, 3, 4, 5로 정렬될때까지 계속 반복한다.
    while (true)
    {
        // 0 ~ 4번째 수까지 순회하며 다음수와 현재수를 비교한다.
        for (int iter = 0; iter < 4; ++iter)
        {
            // 현재수가 더 크다면 다음수와 바꾸고 이때에만 5개의 수를 출력한다.
            if (board[iter] > board[iter + 1])
            {
                swap(board[iter], board[iter + 1]);
                for (int i = 0; i < 5; ++i)
                    cout << board[i] << ' ';
                cout << '\n';
            }
        }

        // 4번째수까지 순회한 이후 현재 1, 2, 3, 4, 5로 정렬되었는지 확인하여
        // 정렬되었다면 반복문을 탈출하고 그렇지 않다면 다시 반복한다.
        bool isfind = true;
        for (int i = 0; i < 5; ++i)
        {
            if (board[i] != ans[i])
            {
                isfind = false;
                break;
            }
        }

        if (isfind)
            break;
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}