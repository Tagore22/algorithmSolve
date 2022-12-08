#include <iostream>
#include <list>

using namespace std;

//ó���� �ƹ� ���� ���� string���� �����ߴµ� �翬�ϰԵ� �ð��ʰ��� ����. �߰��� �����ϴ� ��찡 ���� ���� list�� ���� ������.

//Ǯ��
//�־����� �Է��� �ִ� 4���� ��찡 �ִ�. �� ��쿡 ���� �ݺ����� ��ġ�� �����ذ��� ���ڿ��� �߰� Ȥ�� �����س�����.
//������ list ���� ���� �����̳��� �ݺ��ڴ� ���� �߰��ÿ��� �������� �ʴµ�, �� �״�� ���ο� ���Ұ� ���ԵǴ� ��� distance�Լ��� begin���� ������� �����Ҷ�
//���ο� ���� �������� ���� �Ÿ��� 1 �þ���� ���� �ݺ��ڸ� ���� �ǵ帮�� �ʾƵ� �˾Ƽ� �Ÿ��� �����Ѵ�.
//���� �׼��� �ݺ��ڴ� ������ ũ�� ��ȭ�� ����. ���� ����.

list<char> board;
string str;
int N;

void MakeAnswer()
{
    list<char>::iterator idx = board.end();
    char com;
    for (int i = 0; i < N; ++i)
    {
        cin >> com;
        if (com == 'L' && idx != board.begin())
        {
            --idx;
        }
        else if (com == 'D' && idx != board.end())
        {
            ++idx;
        }
        else if (com == 'B' && idx != board.begin())
        {
            --idx;
            idx = board.erase(idx);
        }
        else if (com == 'P')
        {
            char plus;
            cin >> plus;
            board.insert(idx, plus);
        }
    }

    for (auto& a : board)
        cout << a;
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str >> N;
    for (int i = 0; i < str.size(); ++i)
        board.push_back(str[i]);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}