#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���������� �Ÿ��� �ƴ� ���������� �Ÿ��̹Ƿ�, ������ ������� ���� ����� ������ ��ġ�� ã���� �ȴ�.
// ó�� �Է½� ����� ���� ���� ���� Sum�� �����س��� �� ���� ��ġ�������� ��ȸ�ϱ� ���� ��ġ�� ��������
// ��� ������ �����Ѵ�. �� ������ ��ȸ�ϸ� �ٽ� ���� ������� ���� Cur�� ���ϴµ� Cur�� Sum��
// ���� Ȥ�� �� �̻��� �Ǵ� ������ ��ġ�� ���ϸ� �ȴ�. �̶� Sum�� ������ �ܼ��� Sum / 2�� �ƴ�
// (Sum + 1) / 2�� ���ؾ��ϴµ� Sum�� Ȧ���ϼ��� �ֱ� �����̴�. ���� Cur�� (Sum + 1) / 2�� ���ٴ� ����
// �� ������ ��� ������� ���� ����ϴ� ���� �����̶�� ���̰� ũ�ٴ� ���� ��� �������� ���Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int N;
pair<int, int> Board[100000];
long long Sum = 0; // �־����� �� ������ ������� �ִ� 10���̹Ƿ� int���� ����� �ִ�.

void MakeAnswer()
{
    // �� ���� ��ġ�� ã���� �ֵ��� ��ġ�� �������� �����Ѵ�.
    sort(Board, Board + N);
    long long Cur = 0;
    for (int i = 0; i < N; ++i)
    {
        // �� ������ ��ȸ�ϸ� ���� ���� Cur�� ���Ѵ�.
        // Cur�� Sum�� ���ݺ��� ���ų� ũ�ٸ� �� ��ġ�� ��ü���� �������Ѵ�.
        Cur += Board[i].second;
        if (Cur >= (Sum + 1) / 2)
        {
            cout << Board[i].first << '\n';
            break;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> Board[i].first >> Board[i].second;
        Sum += Board[i].second;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}