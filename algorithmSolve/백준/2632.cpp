#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// �����հ� �̺�Ž���� ����ϴ� ������. A���� ����� �ִ� ��� ���հ� B���� ����� �ִ� ��� ������ �����Ŀ�
// A�� ��ȸ�ϸ� �� ũ�� - ���� A���� ����� �ִ� ũ�⸦ B���� ����� �ִ� ����� ���� ��� ���Ͽ� ����ϸ� �ȴ�.
// �� ����� ���� upper_bound(), lower_bound()�� �̿��ؼ� ���Ҽ� �־��µ�, upper_bound()�� �־����� ������ 
// ū ù��° ������ ��ġ��, lower_bound()�� ���ų� ū ù��° ������ ��ġ�� ��ȯ�ϱ� ������ �� ��ġ���� ���̰�
// �� ������ ��ġ�ϱ� �����̴�. �ٸ�, �� A�� B�� ����� ���� ���� �����ϰ� �Ҽ� ���� �� ������ �� �κ��� �ƽ���.

// �ڼ��� ������ �ּ����� �����.

vector<int> boardA, boardB, sumA, sumB;

int S, N, M;

void MakeAnswer()
{
    int vsize = boardA.size();
    // A���� ����� �ִ� ��� ��츦 ���Ѵ�.
    for (int idx = 0; idx < vsize; ++idx)
    {
        int next = idx, sum = boardA[idx];
        int prev = idx - 1 < 0 ? vsize - 1 : idx - 1;
        while (next != prev)
        {
            sumA.push_back(sum);
            next = (next + 1) % vsize;
            sum += boardA[next];
        }
    }
    vsize = boardB.size();
    // A���� ����� �ִ� ��� ��츦 ���Ѵ�.
    for (int idx = 0; idx < vsize; ++idx)
    {
        int next = idx, sum = boardB[idx];
        int prev = idx - 1 < 0 ? vsize - 1 : idx - 1;
        while (next != prev)
        {
            sumB.push_back(sum);
            next = (next + 1) % vsize;
            sum += boardB[next];
        }
    }
    // A�� ��ȸ�ϸ� B�� �����ִ� �����̱⿡ B�� �����ص� �ȴ�.
    sort(sumB.begin(), sumB.end());
    int answer = 0;
    // A�� ��ȸ�ϸ� A���� ����� ���� ������ ũ�⸦ B���� ����� �ִ��� Ȯ���ϰ�
    // �� ����� ���� �����ش�.
    for (auto& now : sumA)
    {
        int here = S - now;
        if (here < 0)
            continue;
        answer += upper_bound(sumB.begin(), sumB.end(), here) -
            lower_bound(sumB.begin(), sumB.end(), here);
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> S >> N >> M;
    int num, sum = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        boardA.push_back(num);
        sum += num;
    }
    sumA.push_back(sum);
    sumA.push_back(0);
    sum = 0;
    for (int i = 0; i < M; ++i)
    {
        cin >> num;
        boardB.push_back(num);
        sum += num;
    }
    sumB.push_back(sum);
    sumB.push_back(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}