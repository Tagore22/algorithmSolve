#include <iostream>
#include <cstring>

using namespace std;

//풀이
//각 수의 합들의 모든 경우들을 미리 계산한다. 각 3개의 수들의 합에 대한 원소값을 1씩 증가시켜가며 계산한다.
//그 후 합들이 모인 배열들을 순회하며 가장 경우가 크되, 그중 가장 작은 수를 찾아 출력한다.
//3개의 수의 최대 크기가 각각 20, 20, 40이며, 모든 경우는 16000에 해당한다. 그렇기에 아무리 많아도
//연산량은 16000 + 16000으로 시간내에 충분히 계산가능하다.

//P.S board의 칸은 굳이 16000일 필요가 없다. 3개의 수의 합의 최대크기는 결국 20 + 20 + 40이기에 81으로도 충분하다.

int board[81];
int s1, s2, s3;

void Init()
{
    for (int i = 1; i <= s1; ++i)
        for (int j = 1; j <= s2; ++j)
            for (int k = 1; k <= s3; ++k)
                ++board[i + j + k];
}

void MakeAnswer()
{
    Init();

    int sum = 0;
    int answer;
    for (int i = 0; i <= s1 + s2 + s3; ++i)
        if (sum < board[i])
        {
            sum = board[i];
            answer = i;
        }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(board, 0, sizeof(board));

    cin >> s1 >> s2 >> s3;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}