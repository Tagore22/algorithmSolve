#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 조건이 꽤나 많지만 평범한 DP문제다.
// 문제의 원리는 다음과 같다. 

// 25114라는 암호가 있을때

// 1. 첫번째 해석을 할때 2만을 이용하여 B를 얻는 방법과 25를 이용하여 Y를 얻는 방법이 있다.
// 즉, 주어진 문자열의 한자리 혹은 두자리를 이용하여 해석을 할수 있다.
// 2. 암호는 1부터 26이었으므로 0은 존재하지 않는다. 그러므로 현재 자리수가 0일때에는
// 해석할수 없다.
// 3. 한자리를 이용하여 해석하는 것은 상술한 0이 아니라면 언제든지 가능하나, 두자리를 이용하여
// 해석할때에는 현재 자리수 * 10 + 다음 자리수의 값이 26이하일때에만 가능하다.
// 4. 해석의 수가 매우 크므로 100만으로 나눈 나머지값을 출력한다.

// 이 4가지 조건을 만족시키는 함수를 구현하면 된다.

// 자세한 설명은 주석으로 남긴다.

int dp[5000];
string str;
const int DIV_NUM = 1000000;
int ssize;

// 실제로 문자열으 순회하며 해석값을 계산하는 함수.
int BackTrack(int idx)
{
    // 기저 조건. idx가 마지막에 도달하였을때 성공이므로 1을 반환한다.
    if (idx == ssize)
        return 1;

    // 몇번째 위치에서 해석을 시작하는지에 따라 중복이 일어날수 있기에
    // DP처리 해준다.
    int& ans = dp[idx];
    if (ans != -1)
        return ans;

    ans = 0;

    // 현재 문자가 '0'이라면 상술한 2번 조건처럼 한자리로도 두자리로도
    // 해석할수 없다. 0을 반환한다.
    if (str[idx] == '0')
        return 0;

    // 한자리를 이용하여 해석했을 경우.
    ans += BackTrack(idx + 1);

    // 현재가 마지막 위치가 아닐 경우.
    if (idx + 1 < ssize)
    {
        // 현재 위치와 다음 위치를 정수로 변환하여 그 수가 26보다 작거나 같다면
        // 두자리를 이용하여 해석이 가능하다.
        int check = (str[idx] - '0') * 10 + (str[idx + 1] - '0');
        if (check <= 26)
            // 두자리를 이용하여 해석했을 경우.
            ans += BackTrack(idx + 2);
    }

    // 모든 경우에 100만 이하 값이 출력되는데 위에서 최대 2번 더해진다.
    // 따라서 기존의 ans값은 모든 경우에 최대 200만이 안되기에 여기서 한번만 나누어주어도
    // 상관없다.
    return ans %= DIV_NUM;
}

void MakeAnswer()
{
    // dp값의 초기화.
    memset(dp, -1, sizeof(dp));
    ssize = str.size();
    int answer = BackTrack(0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}