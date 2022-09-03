#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//모든 부분합들을 두개의 벡터안에 넣어놓고 2개의 이진 탑색으로 T - sumA[i]의 값들을 찾는다.
//만약 값이 존재한다면 lower_bound와 upper_bound의 결과값이 다를 것이므로, 이 값들을 빼서 총결과값에 더한다.

vector<int> A, B, sumA, sumB;
int T, N, M;
long long answer = 0;

void MakeAB()
{
    cin >> N;
    A.resize(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    cin >> M;
    B.resize(M, 0);
    for (int i = 0; i < M; ++i)
        cin >> B[i];
}

void MakeSumAB()
{
    int now;
    for (int i = 0; i < N; ++i)
    {
        now = A[i];
        sumA.push_back(now);
        for (int j = i + 1; j < N; ++j)
        {
            now += A[j];
            sumA.push_back(now);
        }
    }
    for (int i = 0; i < M; ++i)
    {
        now = B[i];
        sumB.push_back(now);
        for (int j = i + 1; j < M; ++j)
        {
            now += B[j];
            sumB.push_back(now);
        }
    }
}

void CalculAnswer()
{
    sort(sumA.begin(), sumA.end());
    sort(sumB.begin(), sumB.end());

    for (int i = 0; i < sumA.size(); ++i)
    {
        int from = lower_bound(sumB.begin(), sumB.end(), T - sumA[i]) - sumB.begin();
        int to = upper_bound(sumB.begin(), sumB.end(), T - sumA[i]) - sumB.begin();

        answer += to - from;
    }
}

void MakeAnswer()
{
    MakeAB();
    MakeSumAB();
    CalculAnswer();
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}