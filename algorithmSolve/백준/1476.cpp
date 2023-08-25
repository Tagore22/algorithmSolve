#include <iostream>

using namespace std;

// 풀이.
// 처음에는 점화식을 이용해서 풀 생각이었는데 도무지 생각이 나질 않았다.
// 그러다가 알게 된 것은 가장 최대치가 15, 28, 19일때라는 것이다.
// 예시에서 나왔듯 그 답은 8000이 채 안되는데 결과적으로
// 1씩 증가시키면서 가장 최초로 3개의 값이 각각 E, S, M과 동일할때
// 최종값 answer을 출력해주면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[3] = { 1, 1, 1 };
int E, S, M;

void MakeAnswer()
{
    int answer = 1;
    while (true)
    {
        // 3개의 값이 각각 E, S, M과 동일할 경우 반복문을 탈출하여 답을 출력.
        if (board[0] == E && board[1] == S && board[2] == M)
            break;

        // 1씩 모두 늘려나간다. 다만 값의 최초값이 0이 아닌 1이기 때문에
        // 1증가한후 나누었을때 0이라면 직접 바꿔주어야한다.
        ++answer;
        board[0] = (board[0] + 1) % 16;
        board[0] = board[0] == 0 ? 1 : board[0];
        board[1] = (board[1] + 1) % 29;
        board[1] = board[1] == 0 ? 1 : board[1];
        board[2] = (board[2] + 1) % 20;
        board[2] = board[2] == 0 ? 1 : board[2];
    }
    cout << answer << '\n';
}

void Input()
{
    cin >> E >> S >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}