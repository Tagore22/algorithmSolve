#include <iostream>

using namespace std;

// Ǯ��.
// �־��� ������ ���� ū ���� ���� ���� ���� ���̸� ����ϴ� ������. �� Ǯ�̿����� �Ź� �Է¹���������
// ������ ���� ū ��, ���� ���� ���Ͽ����� �迭�� �ϳ� ���� �����ϴ� Ǯ�̵� �ִ�. �ٸ� ���ڰ� ���� ���
// #include <algorithm>�� �ʿ��ϴ�.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, num, max_num = 0, min_num = 1000;
    cin >> N;
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> num;
        max_num = max(max_num, num);
        min_num = min(min_num, num);
    }
    cout << max_num - min_num << '\n';
    return 0;
}