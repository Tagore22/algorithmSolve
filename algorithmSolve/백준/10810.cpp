#include <iostream>

using namespace std;

// 풀이.
// 문제에서는 바구니에 공을 뺏다가 넣니 뭐니 하지만 결과적으로는 마지막에 각 바구니에 들어있는 공의
// 번호를 출력하면 된다. 기존의 바구니에 있는 공을 빼고 새로운 공을 넣는건 그냥 각 바구니의 값을
// 새로운 값으로 바꾸면 되는 일이다.

// 자세한 설명은 주석으로 남긴다.

int board[101];
int N, M;

void MakeAnswer()
{
    // 현재 공을 새로 집어넣는 범위의 시작값, 끝값, 새로운 공의 번호.
    int from, to, num;
    for (int i = 0; i < M; ++i)
    {
        // 범위와 공의 번호를 입력받는다.
        cin >> from >> to >> num;
        // 범위의 번호를 새로운 번호 num으로 바꾼다. 
        for (int j = from; j <= to; ++j)
        {
            board[j] = num;
        }
    }

    // 1번부터 N번까지의 바구니속 공의 번호 출력.
    for (int i = 1; i <= N; ++i)
    {
        cout << board[i] << ' ';
    }
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}