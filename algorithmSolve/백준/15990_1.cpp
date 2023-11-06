#include <iostream>

using namespace std;

// 풀이.
// 15990번의 재귀호출을 사용하지 않고 오직 DP만을 이용한 풀이다.
// 기존에도 재귀를 사용하지 않은 방법이 생소한터라 욕심이 났다. 다만 시간이 조금 걸렸다.
// 재귀 함수를 이용한 방법과는 달리 위부터가 아니라 아래부터 올라가는 방식이기에
// 초기값들을 결정해주어야 했다. 답은 간단했다. 2차원 배열 board가 가르키는 것은 [현재값][합에서 맨 마지막값]이다.
// 따라서 후술할 내용들을 보면 [1][1], [2][2], [3][1], [3][2], [3][3]이 1이 된다.
// 예를 들어 [3][1]을 보면 현재값이 3일때 맨 마지막값이 1이라면 남은 수는 2가 되는데 2를 더이상 나눌수 없기에
// 그냥 2 하나만 들어가게 되어 경우의 수는 1이 된다. 이렇게 초기값들을 정해놓고 이 이후값부터 DP를 순회하면 된다.
// 다만 중요한 점이 하나 있는데 이 이후값들을 갱신해주어야 한다는 것이다. 다른 풀이들을 보면서 의아했던 것이
// 아래부터 올라가다보니 구한값을 또 구하고 있다는 것이었다. 그렇기에 시작값 idx를 입력받은 값 num과 비교하여
// 순회의 시작점을 계속 갱신해야 연산량을 최소한으로 줄일수 있다.

// 자세한 설명은 주석으로 남긴다.

const int DIV = 1000000009;
int board[100001][4];
int T;

void MakeAnswer()
{
    // 순회의 시작값 idx. 3까지는 값을 알기에 4부터 시작한다.
    int num, idx = 3;
    // 상술한 초기값들.
    board[1][1] = board[2][2] = board[3][1] = board[3][2] = board[3][3] = 1;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> num;

        // num까지 순회하며 값을 찾는다.
        for (int i = idx + 1; i <= num; ++i)
        {
            board[i][1] = (board[i - 1][2] + board[i - 1][3]) % DIV;
            board[i][2] = (board[i - 2][1] + board[i - 2][3]) % DIV;
            board[i][3] = (board[i - 3][1] + board[i - 3][2]) % DIV;
        }

        cout << ((board[num][1] + board[num][2]) % DIV + board[num][3]) % DIV << '\n';
        // 시작값 idx의 갱신.
        idx = max(idx, num);
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}