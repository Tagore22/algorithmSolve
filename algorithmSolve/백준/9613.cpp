#include <iostream>

using namespace std;

// 풀이.
// 최대공약수를 구하는 문제다. 종만북에서 많이 봤기에 어렵지 않았다.
// 주어지는 케이스마다 모든 원소들을 한쌍으로 묶어 최대공약수를 구해 그 값들을
// 최종값 answer에 더한후 출력하면 된다.

// 다만 한가지 실수를 했었는데 어떤 쌍의 최대 공약수가 최대값 100만이라고 할때
// 왠지 모르겠는데 한번에 케이스에서 100을 곱해 최대값이 1억이라고 가정하였다.
// 실제로는 한 케이스의 원소가 최대값인 100개가 주어질때 99 + 98 + ... + 1까지 총 4950번이 주어져
// 40억을 훌쩍 뛰어넘게 된다. 따라서 최종값 answer는 int가 아닌 long long으로 구현해야한다.

// 자세한 설명은 주석으로 남긴다.

int board[100];
int T, N;

// 최대공약수를 구하는 함수.
int GCD(int a, int b)
{
    if (b == 0)
        return a;

    return GCD(b, a % b);
}

void MakeAnswer()
{
    // 위 상술하였듯 answer는 한 케이스에서 최대 40억을 넘을수 있으므로 int가 아닌 long long으로 구현해야한다.
    long long answer;
    for (int i = 0; i < T; ++i)
    {
        cin >> N;
        answer = 0;
        for (int j = 0; j < N; ++j)
        {
            cin >> board[j];
        }

        // 모든 원소들을 한쌍으로 묶어 최대공약수를 구하고 그 값들을 최종값 answer에 더한다.
        for (int from = 0; from < N - 1; ++from)
        {
            for (int to = from + 1; to < N; ++to)
            {
                answer += GCD(board[from], board[to]);
            }
        }

        cout << answer << '\n';
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