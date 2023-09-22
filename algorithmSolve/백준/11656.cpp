#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ����� ���� ������. �� ���̻縦 ��´ٴ� ���� �տ������� ���ڸ��� ��� ���°� �ǹ��ϴµ�
// �̰��� string�� substr()�� ���� ���������ϴ�. ���� ��� ���̻縦 ������ �̰��� �����ϰ�
// ������ָ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

string board[1000];
string str;

void MakeAnswer()
{
    int size = str.size();

    // 1. substr()�� �̿��Ͽ� ��� ���̻縦 ���Ѵ�. ���ڿ��� ���̰� �ִ� 1000�̱⿡
    // �ִ� 1000�� ���귮�� �Ҹ��Ѵ�.
    for (int i = 0; i < size; ++i)
        board[i] = str.substr(i);

    // 2. ���̻���� �������� ����Ѵ�. sort()�� �ð����⵵�� Nlogn�̱⿡ 31000������ ���귮��
    // �Ҹ�ȴ�.
    sort(board, board + size);
    for (int i = 0; i < size; ++i)
        cout << board[i] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}