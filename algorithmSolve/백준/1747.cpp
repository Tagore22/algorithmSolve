#include <iostream>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

// 풀이 
// 어떤 수 N이 주어질때(1 ~ 1,000,000) N보다 같거나 더 큰 최소한의 팰린드롬이면서 소수인 수를 구하는 문제이다.
// 즉 2부터 어떠한 최대값까지 소수인지를 미리 계산해놓고(에라토스테네스의 체), 나중에 N을 증가시키며 팰린드롬이면서 소수인지 확인해야한다.
// 이 최대값을 무엇으로 구해야 하는지 고민했는데, 그냥 9876543부터 조금씩 줄여갔다. 결국엔 1003001인 것이 밝혀졌다.

const int MAXNUM = 1300000;
bool era[MAXNUM + 1];
int N;

// 소수인지 미리 확인하는 함수. 1300000을 최대값으로 잡아놓은 상태.
void MakeEra()
{
    era[0] = false;
    era[1] = false;
    int sqrt_num = sqrt(MAXNUM);
    for (int i = 2; i <= sqrt_num; ++i)
        if (era[i])
            for (int j = i * i; j <= MAXNUM; j += i)
                era[j] = false;
}


// 팰린드롬인지 확인하는 함수. string으로 변환후 확인한다.
bool CheckPalin(int cur)
{
    string str = to_string(cur);
    for (int i = 0; i < str.size() / 2; ++i)
        if (str[i] != str[str.size() - 1 - i])
            return false;
    return true;
}

// N을 1씩 증가시키며 팰린드롬이면서 소수인 최소값을 출력한다.
void MakeAnswer()
{
    MakeEra();
    while (true)
    {
        if (era[N] && CheckPalin(N))
        {
            cout << N << '\n';
            return;
        }
        ++N;
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(era, true, sizeof(era));

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}