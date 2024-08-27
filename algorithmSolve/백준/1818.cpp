#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// ������ ��û Ǯ��ô� LIS ������. ������ �������̶� �׷��� ���� ������ �ȳ� ���� Ǯ�̸� �ô�.
// ��������δ� �ϳ��� vector�ȿ� �� ó�� ���Һ��� �־�鼭 vector�� ���� ū ���Һ��� ���� �������� �ϴ�
// ���Ұ� �� ũ�ٸ� �״�� �ְ� �׷��� �ʴٸ� lower_bound()�� �̿��Ͽ� ���ο� ��ġ�� ��� ������ �����̴�.
// �׷��� vector�� ���̰� LIS�� ���̰� �Ǵµ� N���� �̰��� ���ָ� �ȴ�. �ֳ��ϸ� LIS�� ���ԵǴ� ���ҵ���
// �̹� ��ġ�� �������ֱ� ������ �ǵ帱 �ʿ䰡 ���� ������ ���ҵ��� �ּ� �ѹ����� �������־�� �ϱ� �����̴�.
// LIS�� ���̻Ӹ� �ƴ϶� �� ���ҵ��� �˾ƾ��ϴ� Ǯ�̴� 14003�� �ִ�. ��¦�� ������ڸ� �ϳ��� vector �̿ܿ�
// pair<int, int> ������ vector�� �����Ͽ� ���� ����־��ֵ�, ù��° int�� �ε������� �־��ش�. ��� ���� ����
// �� �ں��� �ٽ� ��ȸ�ϸ� LIS�� ������ ��ġ�ϴ� ���ҵ��� ������ answer�� �־��ش�. �̰͵��� �ٷ� LIS�� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

vector<int> answer;
int board[200000];
int N;

void MakeAnswer()
{
    // �� ù��° ���Ҵ� �񱳰� �Ұ����ϱ⿡ ������ ����־��ش�.
    answer.push_back(board[0]);
    for (int iter = 1; iter < N; ++iter)
    {
        // ���� ������ �ִ� ������ ���� ū ���Һ��� ���� �������� �ϴ� ���Ұ� �� ũ�ٸ�
        // �׳� ����ִ´�.
        if (answer.back() < board[iter])
        {
            answer.push_back(board[iter]);
        }
        // �׷��� �ʴٸ� lower_bound()�� �̿��Ͽ� �� ��ġ�� ã�� ������ش�.
        // �̰��� �ٽ��̴�.
        else
        {
            int idx = lower_bound(answer.begin(), answer.end(), board[iter]) - answer.begin();
            answer[idx] = board[iter];
        }
    }
    // ����Ѵ�� LIS�� ���ҵ��� �̹� ��ġ�� �����ٰ� �����ϰ� �� �̿��� �͵��� �ּ��� �ѹ����� �̵��� ���־��
    // �ϱ⿡ N - LIS�� ���̸� ����Ѵ�.
    cout << N - answer.size() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int cur;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}