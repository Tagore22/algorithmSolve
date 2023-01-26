#include <iostream>

using namespace std;

//풀이
//각 문자열을 팰린드롬으로 분할할때 그 최소값을 구하는 문제이다.
//우선 i~j까지의 문자열이 팰린드롬인지 알아야 하는데, 여러개의 경우의 수에 따라 구현할수 있다.
//1. 문자가 1개일때에는 무조건 팰린드롬이다.
//2. 문자가 2개일때에는 두 문자가 동일하다면 팰린드롬이다.
//3. 문자가 3개이상일때에는 처음과 마지막 문자가 동일하며 그 사이에 있는 문자열이 팰린드롬이라면 팰린드롬이다.

//위 3가지 경우의 따라 모든 구간의 팰린드롬의 여부를 구현할수 있다.
//그 다음은 N번째 문자열까지 분할할수 있는 최소값을 DP형식으로 구해야하는데, 앞서 구한 구간의 팰린드롬의 여부와 DP의 특성을 이용해야한다.

//DP의 특성은 작은수부터 혹은 큰수부터 N번째까지의 값을 구해 그것을 응용하여 다음 답을 구해나간다. 이번의 경우에는 작은수부터
//즉 1번째 문자열까지의 팰린드롬의 최소값을 알수 있기에 1부터 N까지 나아가면 된다.
//현재 N번째 문자열의 팰린드롬의 최소값을 구한다고 치자. 최초값이자 최대값은 문자의 개수 N이다.
//이 이후로 1번째부터 N번째까지가 팰린드롬인지, 2번째부터 N번째까지가 팰린드롬인지 순회를 해야한다.
//DP[N]은 문자열의 N번째까지 구할수 있는 팰린드롬의 최소값이기에 그 이후의 문자가 팰린드롬을 생성한다면 DP[N] = min(DP[N], DP[시작값] + 1)이 되기
//때문이다.

int answer[2501];
bool IsPal[2501][2501];
string str;
int Ssize;

void CheckPal()
{
    for (int i = 1; i < Ssize; ++i)
        IsPal[i][i] = true;
    for (int i = 1; i < Ssize - 1; ++i)
        if (str[i] == str[i + 1])
            IsPal[i][i + 1] = true;
    for (int i = 2; i < Ssize - 1; ++i)
        for (int j = 1; j < Ssize - i; ++j)
            if (str[j] == str[j + i] && IsPal[j + 1][j + i - 1])
                IsPal[j][j + i] = true;
}

void MakeAnswer()
{
    CheckPal();
    answer[0] = 0;

    //시작값 from부터 끝값 to까지 팰린드롬의 여부를 구한다. from부터 to가 팰린드롬이라면 DP[to]는 DP[from-1] + 1와의 최소값이 된다.

    for (int to = 1; to < Ssize; ++to)
    {
        answer[to] = to;
        for (int from = 1; from <= to; ++from)
            if (IsPal[from][to])
                answer[to] = min(answer[to], answer[from - 1] + 1);
    }

    cout << answer[Ssize - 1] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
    str = " " + str;
    Ssize = str.size();
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}