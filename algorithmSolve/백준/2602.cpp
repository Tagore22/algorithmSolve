#include <iostream>

using namespace std;

// 풀이.
// 오랜만에 DP였는데 역시나 빡쎘다. 문제의 흐름과 DP의 구현을 일치시키는게
// 꽤나 힘들었는데 DP에는 정해진 규격이 없이 얼마든지 커스텀이 가능하기 때문이다.

// 자세한 설명은 주석으로 남긴다.

string m, a, b;
// i번째 문자를 j번째에서 찾았을 때.
int dpA[20][100], dpB[20][100];

// 모든 경우를 찾는 함수. idx번째 문자를 here에서 찾은 경우다.
int FindNum(int here, int idx, bool isA)
{
    // 모든 문자를 찾았을 때 1을 반환한다.
    if (idx >= m.size() - 1)
        return 1;
    // DP값을 참조자를 이용하여 저장한다.
    int& ans = isA ? dpA[idx][here] : dpB[idx][here];
    if (ans != -1)
        return ans;

    // DP값의 초기화.
    ans = 0;
    string str = isA ? b : a;
    // here에서 찾았기 때문에 그 이후인 here + 1부터 순회를 시작한다.
    for (int i = here + 1; i < str.size(); ++i)
    {
        // 만약 찾았다면 재귀 함수를 호출하여 그 이후를 찾는다.
        if (str[i] == m[idx + 1])
        {
            if (isA)
                ans += FindNum(i, idx + 1, false);
            else
                ans += FindNum(i, idx + 1, true);
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> a >> b;
    // DP값들의 초기화.
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            dpA[i][j] = -1;
            dpB[i][j] = -1;
        }
    }
    int answer = 0;
    // 문자열을 순회하며 첫번째 값을 찾았을 경우에만 재귀 호출이 시작된다.
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] == m[0])
            answer += FindNum(i, 0, true);
        if (b[i] == m[0])
            answer += FindNum(i, 0, false);
    }
    cout << answer << '\n';
    return 0;
}