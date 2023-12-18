#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 어떠한 집에 안테나를 지을때 다른 집들과의 거리가 가장 짧은 집을 찾는 문제다.
// 다른 집들과의 거리가 가장 짧기 위해서는 가장 중간에 위치한 집을 찾기만 하면 된다.
// 다만 한가지 문제가 가장 짧은 위치가 여러개일 경우에는 수가 작은 왼쪽의 집을 골라야하는데 이게 좀
// 헷갈렸다. 해답은 어렵지 않았는데 N이 짝수일때에는 가장 짧은 위치가 2개가 나왔고, 홀수일때에는
// 가장 가운데 하나만 나온다. 그러므로 N이 홀수일때에는 가장 가운데의 위치를 출력하면 되고
// 짝수일때에는 가장 가운데에서 한칸 왼쪽 위치를 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[200000];
int N;

void MakeAnswer()
{
    // 가장 가운데 위치를 찾기 위해 정렬한다.
    sort(board, board + N);
    int idx = N / 2;
    // N이 홀수일때는 가장 가운데 위치를, 짝수일때에는 가장 가운데에서 한칸 왼쪽 위치를 출력한다.
    cout << (N % 2 == 1 ? board[idx] : board[idx - 1]) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

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