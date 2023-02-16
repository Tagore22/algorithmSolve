#include <iostream>
#include <list>

using namespace std;

// Ǯ��
// �� ������ Ǫ�� ��Ŀ������ �̷��ϴ�.

// 1. ���� ��õ�� �л� ��ȣ K�� �޴´�.
// 2. K�� �̹� ����Ʋ�ȿ� �����Ѵٸ� ��õȽ���� �ø��� ������.
// 3. K�� ����Ʋ�ȿ� �������� �ʴ´ٸ� ���� ����Ʋ�ȿ� �ο����� Ȯ���Ѵ�.
// 3-1. ����Ʋ�� ���� N������ �� ���� �ʾҴٸ� ��õȽ�� 1�� ����ä ����Ʋ�ȿ� �ִ´�.
// 3-2. ����Ʋ�� �̹� N������ �� ���ִٸ� �� �ȿ� �л����� ���� ��õȽ���� ���� �л���, ���� ��õȽ���� ���� Ƚ���� 2��
// �̻��̶�� �׵��� ���� ������ �л��� ���ܽ�Ű�� K�� ��õȽ�� 1�� ����ä ����Ʋ�ȿ� �ִ´�.

// �л��� ���ܽ�ų�� �� �� �߰� ����������� ������ �ֱ⿡ ������ ���� list�� ����Ͽ���. �ٸ�, �������� �л� ��ȣ������ ������ �ؾ��ϴµ�
// �Ϲ� sort()�δ� list�� ���� �׼����� �������� �ʱ⿡ ����Ҽ�����, list�� ���� �����ϴ� list::sort()�� ����ߴ�.


int N, M;

bool CompareNum(pair<int, int> lhs, pair<int, int> rhs)
{
    return lhs.first < rhs.first;
}

void MakeAnswer()
{
    // �л����� ���� ����Ʋ. �� ����Ͽ��� �� �� �߰� ��� ���ܵ��� �˼����⿡ list�� �����Ͽ���.
    list<pair<int, int>> board; // ��ȣ, ��õ��
    int cur;
    for (int i = 0; i < M; ++i)
    {
        cin >> cur;
        bool isfind = false;
        
        // ���� ��õ���� �л��� �̹� ����Ʋ�ȿ� ������ ��� ��õȽ���� 1 �ø��� ������.
        for (auto iter = board.begin(); iter != board.end(); ++iter)
            if (iter->first == cur)
            {
                ++iter->second;
                isfind = true;
                break;
            }

        // ����Ʋ�ȿ� �������� ���� ��� 2���� ���� ����������.
        if (!isfind)
        {

            // 1. ���� ����Ʋ�� N���� �л��� �������� �ʴ´ٸ� �׳� ��õȽ���� 1 ����ä ����ְ� ������.
            if (board.size() < N)
            {
                board.push_back(make_pair(cur, 1));
            }

            // 2. �̹� N������ �����ִٸ� �׵��� ��õȽ���� ���� ���� ���� �׵��� ���� ������ �л��� ���ܽ�Ű�� ��õȽ���� 1 ����ä ����Ʋ��
            // ����ִ´�.

            // �� ��쿡 ��õȽ���� ���� ���� �л����� �� �տ� �л��� ���� ������ �л����� ����Ͽ��µ�, �̴� �л��� ����Ʋ�ȿ� ���������
            // ������ �ڿ���(push_back())���� ����ֱ� �����̴�. �� �ֱٿ� �л��� �� �ڿ� �������� ����.
            else
            {
                int min_num = 1001;
                list<pair<int, int>>::iterator idx;
                for (auto iter = board.begin(); iter != board.end(); ++iter)
                    if (iter->second < min_num)
                    {
                        min_num = iter->second;
                        idx = iter;
                    }
                board.erase(idx);
                board.push_back(make_pair(cur, 1));
            }
        }
    }

    // ���� �׼����� �������� �ʴ� list�δ� �Ϲ����� sort()�� �����Ҽ� ���⿡ list���� ���� �����ϴ� �� ���� list::sort()�� �����Ͽ�
    // ����Ѵ�.
    board.sort(CompareNum);
    for (auto iter = board.begin(); iter != board.end(); ++iter)
        cout << iter->first << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}