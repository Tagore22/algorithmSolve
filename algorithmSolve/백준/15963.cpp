#include <iostream>

using namespace std;

// Ǯ��.
// �־����� �� �� N�� M�� �����ϴٸ� 1��, �׷��� �ʴٸ� 0�� ����ϴ� ����.
// �ٸ�, N�� M�� �ִ밪�� 10�ڸ� �����ε� �̴� int�� �ִ밪�� 24�ﰡ���� �ս��� �Ѿ�Ƿ�
// int�� �ƴ� long long Ÿ���� ������ �����ؾ��Ѵ�.

int main()
{
    long long N, M;
    cin >> N >> M;
    cout << (N == M ? 1 : 0) << '\n';
    return 0;
}