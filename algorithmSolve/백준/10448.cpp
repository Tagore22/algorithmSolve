#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 제일 처음 머리에 떠올랐던건 백트래킹이었다.
// 하지만 굳이 그럴필요가 없었다. 1000이라는 삼각수는 44번째밖에 되지 않았고, 3가지 수의 합이라고 미리 나와있었으며
// 겨우 3개였다. 따라서 아래 풀이처럼 45의 세제곱인 9만5천개도 안되는 연산으로 풀수 있었다.
// 너무 어렵게 생각하는것 같다. 쉬운것부터 넓혀가자.

// 자세한 설명은 주석으로 남긴다.

vector<int> board;
int T, K;

// 모든 삼각수 3개로 이루어진 수들을 구하는 함수.
void Init()
{
    int num = 1;
    while (num * (num + 1) / 2 <= 1000)
    {
        board.push_back(num * (num + 1) / 2);
        ++num;
    }
}

// 최대 45의 세제곱을 순회하여 현재수가 삼각수 3개로 이루어질수 있는지 확인하는 함수.
int Check(int num)
{
    for (int i = 0; i < board.size(); ++i)
        for (int j = 0; j < board.size(); ++j)
            for (int u = 0; u < board.size(); ++u)
                if (board[i] + board[j] + board[u] == K)
                    return 1;
    return 0;
}

void MakeAnswer()
{
    Init();
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> K;
        cout << Check(K) << '\n';
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