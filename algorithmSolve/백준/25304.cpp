#include <iostream>

using namespace std;

// Ǯ��.
// �־����� ���ݰ� �������� ������ X�� ������ Ȯ���ϴ� ����.

// �ڼ��� ������ �ּ����� �����.

int X, N, a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> X >> N;
    int answer = 0;
    // ��� ���ǵ��� ���ݰ� ������ �Է¹޾� �� ���� X�� ������ Ȯ���Ѵ�.
    for (int i = 0; i < N; ++i)
    {
        cin >> a >> b;
        answer += a * b;
    }

    // ���ٸ� Yes��, �ٸ��ٸ� No ���.
    cout << (answer == X ? "Yes" : "No") << '\n';
    return 0;
}