#include <iostream>
#include <vector>

using namespace std;

vector<int> answer;
vector<int> PrevVec;
int n;

int Calcul()
{
    answer[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        answer[i] = answer[i - 1] + 1;
        PrevVec[i] = i - 1;
        if (i % 3 == 0)
        {
            if (answer[i] < answer[i / 3] + 1)
                continue;
            answer[i] = answer[i / 3] + 1;
            PrevVec[i] = i / 3;
        }
        if (i % 2 == 0)
        {
            if (answer[i] < answer[i / 2] + 1)
                continue;
            answer[i] = answer[i / 2] + 1;
            PrevVec[i] = i / 2;
        }
    }
    return answer[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> n;
    answer.assign(n + 1, 0);
    PrevVec.assign(n + 1, 0);
    cout << Calcul() << '\n';
    while (true)
    {
        cout << n << ' ';
        n = PrevVec[n];
        if (n == 0)
            break;
    }
    cout << '\n';
    return 0;
}