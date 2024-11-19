#include <iostream>
#include <cmath>

using namespace std;

// 풀이.
// 최대 10만개에 달하는 원소들을 중복없이 서로 비교해보는 문제다. 다만 10만....+ 1개까지 최대 50억가량의
// 연산량을 필요로 하기 때문에 단순 2중 for문을 사용하는 주먹구구식 풀이는 불가능했다. 그러다가 생각해낸것은
// 에라토스테네스의 체를 응용하여 각 원소들의 약수들을 구하여 실제로 존재하는지를 확인후 +-1을 하는 것이다.
// 최대값이 100만이기에 이때의 약수를 구하는 연산량은 제곱근인 1000에 도달하기에 단순 계산으로 10만 * 1000으로
// 1억의 연산량이 나오지만 모든 수는 한번씩만 등장하기에 무조건 1억보다 작았다. 실제로 수가 존재하는지는 answer값을
// 통해 알수 있는데 초기값을 아주 큰 수 -987654321으로 해둔후에 그 수가 등장할시 0으로 수정해준다.

// 하지만 나누기 연산이 존재해서 그런가 꽤나 느렸다.

// 자세한 설명은 주석으로 남긴다.

int board[100000], answer[1000001];
int N;

void MakeAnswer()
{
    // 모든 원소값의 약수들이 존재하는지 순회하며 확인한다.
    for (int i = 0; i < N; ++i)
    {
        // 에라토스테네스의 체를 응용하여 제곱근까지만 순회해준다.
        int sqrtnum = sqrt(board[i]);
        for (int j = 1; j <= sqrtnum; ++j)
        {
            // 만약 나눌수 없다면 무시한다.
            if (board[i] % j != 0)
                continue;
            // a * b = A일때 a와 b가 다를때
            if (j != board[i] / j)
            {
                // 기존에는 -1로 구분하였는데 이건 잘못된 방법이었다.
                // 언제든지 0에서 -1이 될수 있기 때문이다. 따라서 절대로 될수없는값
                // -987654321로 비교하였다.
                // 이 값이 등장한 값이라면 +-1을 처리해준다.
                if (answer[board[i] / j] != -987654321)
                {
                    ++answer[board[i] / j];
                    --answer[board[i]];
                }
            }
            // 상술한 a * b = A에서 a의 값을 확인해준다.
            if (answer[j] != -987654321)
            {
                ++answer[j];
                --answer[board[i]];
            }
        }
    }
    for (int i = 0; i < N; ++i)
        cout << answer[board[i]] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i <= 1000000; ++i)
        answer[i] = -987654321;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        answer[board[i]] = 0;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}