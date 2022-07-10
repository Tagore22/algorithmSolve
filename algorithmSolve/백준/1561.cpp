#include <iostream>
#include <vector>

using namespace std; // 놀이기구의 번호는 1번부터 m번까지

vector<int> ride;
int N, M;
const long long MAXNUM = 2000000000LL * 30;

bool CheckFirst()
{
    return N <= M ? true : false;
}

long long CalculChild(long long alltime)
{
    long long child = M;
    for (int i = 0; i < M; ++i)
        child += alltime / ride[i];
    return child;
}

long long BinaryFind()
{
    long long lo = 0;
    long long hi = MAXNUM;
    for (int i = 0; i < 100; ++i)
    {
        long long mid = (lo + hi) / 2;
        long long child = CalculChild(mid);
        if (child >= N)
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

void MakeAnswer()
{
    if (CheckFirst())
    {
        cout << N << '\n';
        return;
    }
    long long alltime = BinaryFind();
    long long child = CalculChild(alltime - 1);
    for (int i = 0; i < M; ++i)
        if (alltime % ride[i] == 0)
        {
            ++child;
            if (child == N)
            {
                cout << i + 1 << '\n';
                break;
            }
        }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    ride.assign(M, 0);
    for (int i = 0; i < M; ++i)
        cin >> ride[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}