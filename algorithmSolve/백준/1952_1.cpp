#include <iostream>

using namespace std;

// ã�� ���ߴ� ��Ģ�� �̿��� Ǯ��.

int main()
{
    int M, N;
    cin >> M >> N;
    cout << (M > N ? N * 2 - 1 : M * 2 - 2) << '\n';
    return 0;
}