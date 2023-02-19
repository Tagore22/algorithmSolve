#include <iostream>
#include <map>
#include <string>

using namespace std;

// Ǯ��
// �� ������ �ٽ���
//
// 1. ����Ÿ���� �������(�°�)
// 2. �Ҽ� N��°���� ����ϱ�
//
// �� 2�����̴�. ù��° ������ �����⿡�� ���Ǵµ� ������ �� �׷�� Ȥ�� � ���� �� K ���� �ϳ��� �ε��Ҽ��� Ÿ���� �ƴ϶��
// ��Ȯ�� ���� ������ �ʴ´�. ���� ��� 1 / 3 �� ���Ҷ� �Ѵ� int���̶�� 0�� ���ͼ� 0.3333�� ���ؾ� �ϴ� ������ ���Ҽ� ����.
// �׷��� ������ �� �׷���� ���ϴ� tree_num�� double�� �����ߴ�.

// �ι�° ������ precision()�� fixed�� ������ �ذ��Ҽ� �ִ�.

map<string, int> board;
double tree_num = 0;

// ���������� ���� ���ϴ� �Լ�. �� �׷������ ���� ���� K�� �׷���� ������ 100�� ���� ������� ������ ����Ѵ�.
void MakeAnswer()
{
    cout.precision(4);
    cout << fixed;
    for (auto iter = board.begin(); iter != board.end(); ++iter)
        cout << iter->first << ' ' << iter->second / tree_num * 100 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    while (getline(cin, str))
    {
        ++board[str];
        ++tree_num;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}