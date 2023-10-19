#include <iostream>
#include <list>

using namespace std;

// Ǯ��.
// ���Ḯ��Ʈ�� �̿��Ͽ� ���Ҹ� ������ ��ȸ�ϴ� ������.
// ������ �����Ͽ��� Ǯ���� ���� ���������θ� ��ȸ�߱⿡ ����ϰ� Ǯ���µ�
// �̰� �������ε� ��ȸ�ؾ��߱⿡ �����ϰ� �������� ������.

// �ڼ��� ������ �ּ����� �����.

list<pair<int, int>> board;
int N;

void MakeAnswer()
{
    // �̵��İ��� ���簪.
    list<pair<int, int>>::iterator there = board.begin();
    list<pair<int, int>>::iterator here;
    int cost;
    while (!board.empty())
    {
        here = there;
        cost = here->second;
        // �̵��� �������̶�� ���簪�� ����� ���� �̵��İ��� �̸� ���������� �̵���Ų��.
        if (cost > 0)
        {
            ++there;
            // �̵��İ��� �����̶�� ó������ �ű��.
            if (there == board.end())
                there = board.begin();
        }
        // �����̶�� �������� �̸� �ű��.
        else
        {
            // ���۰����� ���̻� �������� �ű�� ������ �������� �Ű� �������� �̵���Ų��.
            if (there == board.begin())
                there = board.end();
            --there;
        }
        // ���� ��ȣ�� ����ϰ� �����Ѵ�.
        cout << here->first << ' ';
        board.erase(here);

        // ����Ʈ�� �ֺ���ٸ� Ż���Ѵ�.
        if (board.empty())
            break;

        // �ѹ� �̵���Ų �����̱⿡ cost - 1��ŭ �̵���Ų��.
        for (int i = 0; i < abs(cost) - 1; ++i)
        {
            if (cost > 0)
            {
                ++there;
                if (there == board.end())
                    there = board.begin();
            }
            else
            {
                if (there == board.begin())
                    there = board.end();
                --there;
            }
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int num;
    for (int i = 1; i <= N; ++i)
    {
        cin >> num;
        board.push_back(make_pair(i, num));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}