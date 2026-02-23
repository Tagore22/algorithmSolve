#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 너무 어렵게 생각해서 구현한 풀이. 격자를 순회하되 다른
// 원소와 겹치는 값들중 현재에서 부족한 값만을 추가하는 방식.

int N;
int board[1000][1000];
int answer[1000];
vector<int> bits;

void CalBit(int num)
{
    bits.clear();
    while (num > 0)
    {
        bits.push_back(num % 2);
        num /= 2;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];

    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            CalBit(board[i][j]);
            for (int k = 0; k < bits.size(); ++k)
            {
                if (bits[k] == 0)
                    continue;
                if ((answer[i] & (1 << k)) == 0)
                    answer[i] |= (1 << k);
                if ((answer[j] & (1 << k)) == 0)
                    answer[j] |= (1 << k);
            }
        }
    }
    for (int i = 0; i < N; ++i)
        cout << answer[i] << ' ';
    cout << '\n';
    return 0;
}