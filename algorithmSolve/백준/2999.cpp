#include <iostream>
#include <cmath>

using namespace std;

// 풀이.
// 주어지는 문자열을 세로 먼저 배열에 저장후 다시 가로 먼저 출력하는 간단한 문제다.
// 각 인덱스값이 조금 귀찮았으나 치명적인 실수를 하나해서 조금 헤맸던 문제다.
// 바로 배열의 크기인데 처음의 10은 맞다. 왜냐하면 주어지는 문자열의 최대 크기가 100인데
// 100을 이루는 합성수의 작은 값이 10이기 때문이다. 하지만 뒷부분은 10이 아닌 100이여야 한다.
// 예를 들어 문자열의 길이가 77일 경우 각 가로 세로는 1과 77이 된다. 10에는 넣을수가 없다.
// 그렇기 때문에 계산하면 더 줄일수도 있겠으나 간단한게 100으로 해도 된다.

// 자세한 설명은 주석으로 남긴다.

char board[10][100];
string str;

void MakeAnswer()
{
    int ssize = str.size();
    int sqrt_num = sqrt(ssize);
    int N; // 가로
    // 어떤 수를 이루는 합성수는 그 수의 루트값까지만 구해도 된다.
    // 아리스토테네스의 체와 비슷하다.
    for (int i = 1; i <= sqrt_num; ++i)
    {
        if (ssize % i == 0)
            N = i;
    }

    int M = ssize / N;
    // 가로 먼저가 아닌 세로 먼저 배열에 문자열을 입력한다.
    for (int j = 0; j < M; ++j)
        for (int i = 0; i < N; ++i)
            board[i][j] = str[N * j + i];

    // 다시 가로 먼저 출력한다.
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cout << board[i][j];
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}