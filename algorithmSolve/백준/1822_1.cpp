#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Ǯ��.
// 1822���� �� ���� Ǯ��.
// set�� ������� �ʰ� �̺� Ž���� ���� ����ϴ� Ǯ�̴�. �� A�� B �迭�� �Է¹ް�
// A �迭�� ��ȸ�ϸ� B �迭�� �������� �ʴ� ������ ����Ѵ�. set�� ������� �ʾұ⿡
// �ӵ��� 2���̻� ������. 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n1, n2;
    cin >> n1 >> n2;
    int board1[500000], board2[500000];
    for (int i = 0; i < n1; ++i)
        cin >> board1[i];
    for (int i = 0; i < n2; ++i)
        cin >> board2[i];
    sort(board1, board1 + n1);
    sort(board2, board2 + n2);
    int num = 0;
    string answer = "";
    for (int i = 0; i < n1; ++i)
    {
        if (!binary_search(board2, board2 + n2, board1[i]))
        {
            ++num;
            answer += to_string(board1[i]) + " ";
        }
    }
    cout << num << '\n';
    cout << answer << '\n';
    return 0;
}