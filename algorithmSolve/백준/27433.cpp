#include <iostream>

using namespace std;

// Ǯ��.
// 1�� �����ϴ� ������ ����� ���丮���� ����ϴ� �����̴�.
// �ٸ� �־����� N�� �ִ밪�� 20�� ��� ���� int���� ����� ������ long longŸ������ �����ؾ��Ѵ�.

int main()
{
    int N;
    cin >> N;
    long long answer = 1;
    for (int i = 1; i <= N; ++i)
        answer *= i;
    cout << answer << '\n';
    return 0;
}