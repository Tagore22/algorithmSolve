#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//��� �κ��յ��� �ΰ��� ���;ȿ� �־���� 2���� ���� ž������ T - sumA[i]�� ������ ã�´�.
//���� ���� �����Ѵٸ� lower_bound�� upper_bound�� ������� �ٸ� ���̹Ƿ�, �� ������ ���� �Ѱ������ ���Ѵ�.

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