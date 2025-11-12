#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 처음에는 스택으로 풀 수 있을 것 같았는데 짝이 2개여서 그런지 도무지 풀 수 없었다.

string dna;
int dp[500][500];

int main()
{
    cin >> dna;
    memset(dp, 0, sizeof(dp));

    int dsize = dna.size();

    for (int len = 2; len <= dsize; ++len)
    {
        for (int i = 0; i + len - 1 < dsize; ++i)
        {
            int j = i + len - 1;

            if ((dna[i] == 'a' && dna[j] == 't') || (dna[i] == 'g' && dna[j] == 'c'))
            {
                if (len == 2)
                {
                    dp[i][j] = 2;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
            }

            for (int k = i; k < j; ++k)
            {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }

    cout << dp[0][dsize - 1] << '\n';
    return 0;
}
