#include <iostream>
#include <cstring>

using namespace std;

// 풀이
// 최소 몇명의 학생을 이동시켜 번호대로 정렬할수 있는지를 구하는 문제이다.
// LIS를 대입해서 증가하는 번호의 학생들은 움직이지 않아도 되는 것을 이용할수 있으나,
// 학생들을 무조건 앞과 뒤로만 이동시킬수 있기에 연속되도록 증가하는 학생들만이
// 고정될수 있다. 
// 즉, 연속적으로 증가하는 번호의 학생들을 제외한 나머지 학생들의 수를 출력하면 된다.

int DP[1000001];
int N;

void MakeAnswer()
{
    int num, answer = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        DP[num] = DP[num - 1] + 1;
        answer = max(answer, DP[num]);
    }

    cout << N - answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(DP, 0, sizeof(DP));

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}