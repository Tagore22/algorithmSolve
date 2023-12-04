#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// -2진법을 만드는 문제이다. 평소의 2진법과 다른점은 2를 -2진법으로 만들때를 보면 알수 있는데
// 나머지가 -1이 나오는 경우가 있다. 이 때 -2진법은 110으로 대입해보면 알수 있겠으나
// 나머지가 -1인 경우, 나머지를 강제로 1로 만든후 현재값을 -1시켜 절대값을 올려주면
// 정확하게 풀린다.

// 자세한 설명은 주석으로 남긴다.

vector<int> board;
int N;

void MakeAnswer()
{
    // 0은 -2진법으로 만들 방법이 없다.
    if (N == 0)
    {
        cout << 0 << '\n';
        return;
    }
    // N이 음수도 존재하기에 0보다 큰경우로 하면 안된다.
    while (N != 0)
    {
        int result = N % -2;
        // N을 -2로 나눈 나머지가 0이라면 상관없음.
        if (result == 0)
        {
            board.push_back(0);
            N /= -2;
        }
        // -2로 나눈 결과가 0이 아니라면 강제로 나머지값을 1로 바꾸고
        // N을 1 감소시킨후 -2로 나눈다.
        else
        {
            board.push_back(1);
            N = (N - 1) / -2;
        }
    }
    for (int i = board.size() - 1; i >= 0; --i)
        cout << board[i];
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}