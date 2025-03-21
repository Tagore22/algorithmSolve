#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ó������ �ƹ� ���� ���� for������ ������ ������ ����ؼ� ����ϴ� ������� ����������,
// �̷� ��� �ִ� 10�� 10������ŭ�� ���귮�� �Ǿ �ð��ʰ��� ����. ������ ������ ����ϴ� 
// ������ �ܼ� for���� �ƴ� lower_bound()�� ����ؼ� �̺� Ž������ ���귮�� �ٿ����ߴ�.

// �ڼ��� ������ �ּ����� �����.

// Īȣ�� ������. ���ĵ��� ������� �ʾ� ������ �����ȴ�.
string names[100000];
int power[100000];
int N, M;

void MakeAnswer()
{
    int num;
    for (int iter = 0; iter < M; ++iter)
    {
        cin >> num;
        // �̺� Ž������ ���귮�� ���δ�.
        int idx = lower_bound(power, power + N, num) - power;
        cout << names[idx] << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> names[i] >> power[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}