#include <iostream>

using namespace std;

// Ǯ��.
// �־����� �� N�� 4�����Ҷ����� long�� �ϳ��� ���ٿ��ָ� �ȴ�.

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N / 4; ++i)
        cout << "long ";
    cout << "int" << '\n';
    return 0;
}