#include <iostream>
#include <set>

using namespace std;

// Ǯ��.
// ���ڿ��� �ƴ� char �迭�� xor ������ ���ؼ� ��� ���ڿ�����
// ������ �ٽ� xor ������ ���ؼ� ���ڵ��� ����� ������ε� Ǯ �� �ִ�.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    multiset<string> board;
    for (int iter = 0; iter < N; ++iter)
    {
        string str;
        cin >> str;
        board.insert(str);
    }
    for (int iter = 0; iter < N - 1; ++iter)
    {
        string str;
        cin >> str;
        board.erase(board.find(str));
    }
    cout << *(board.begin()) << '\n';
    return 0;
}