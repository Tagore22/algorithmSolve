#include <iostream>

using namespace std;

// Ǯ��.
// ó������ bool �迭 2���� ���� �θ�� �ڽ� �������� �ľ��Ͽ�
// �θ� ������ ���ų� �ڽ� ������ ���� ������ �������� �ƴ� ������
// ������ �Ͽ�����. ������ ���� �ݷʰ� �־���, ��¥ ������ ����� 
// ������ ���� �ľ��ϴ� ���ε� �� ���� 1���� �۰ų� ���ٸ� ������ ���ڶ���
// �����ϴ� �����̱⿡ �������� �� �� ����. �������� ���� ���� �־�����
// ���� Ʈ���̱� ������ ��� ������ �������� �ȴ�.

int N, Q;
int connect[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int p, c;
        cin >> p >> c;
        ++connect[p];
        ++connect[c];
    }
    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        int T, K;
        cin >> T >> K;
        if (T == 1)
            cout << (connect[K] <= 1 ? "no" : "yes") << '\n';
        else
            cout << "yes" << '\n';
    }
    return 0;
}