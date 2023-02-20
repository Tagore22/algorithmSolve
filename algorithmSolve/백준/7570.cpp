#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��
// �ּ� ����� �л��� �̵����� ��ȣ��� �����Ҽ� �ִ����� ���ϴ� �����̴�.
// LIS�� �����ؼ� �����ϴ� ��ȣ�� �л����� �������� �ʾƵ� �Ǵ� ���� �̿��Ҽ� ������,
// �л����� ������ �հ� �ڷθ� �̵���ų�� �ֱ⿡ ���ӵǵ��� �����ϴ� �л��鸸��
// �����ɼ� �ִ�. 
// ��, ���������� �����ϴ� ��ȣ�� �л����� ������ ������ �л����� ���� ����ϸ� �ȴ�.

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