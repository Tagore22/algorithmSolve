#include <iostream>
#include <set>

using namespace std;

//Ǯ��
//��� ������ �ѹ��� ������ ���������� �� ���� �پ��⿡ ���� ���� ������ ���ذ��� ���־� �������� �پ���.
//���������, multiset��(�ߺ��� ���� ������ �����Ƿ�) �Է°����� �����Ͽ� �������� �տ��� 2������ �����Ͽ�
//���ϰ� �� �������� �ٽ� �����ϴ� ���� multiset�� �� �ϳ��� ���Ҹ� ���������� �ݺ��Ѵ�.
//�� ������ ���Ұ��� �ٷ� ������������ ����Ѵ�.

multiset<int> board;
int N;

void MakeAnswer()
{
    int answer = 0;
    while (board.size() > 1)
    {
        int first = *board.begin();
        board.erase(board.begin());
        int second = *board.begin();
        board.erase(board.begin());

        board.insert(first + second);
        answer += first + second;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        board.insert(num);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}