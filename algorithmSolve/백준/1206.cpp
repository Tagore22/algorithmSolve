#include <iostream>
#include <string>

//�Ѹ� ȭ�� ���� ������. ���� �Ϸ����� �� ������ ��� �־���. �Ф�
//�� ������ ����Ʈ��� �����Ѱ� �翬�ϰ�����, �� ������ �ο����� ������ ������� ���̴�. ó���� (������) % (�ο���) = (�������)��
//������ Ǯ���� �ߴµ�, ������ ���� ������ �ʾҴ�. �˰��� �ε��Ҽ��� ���� �����̾���, �ڵ忡�� double�� ���� ��ü�� ���־��ߴ�.
//����, �Է� ���� �Ҽ����� ���ֱ� ���� double�� ���� �ʰ� string���� �޾Ƽ� �Ҽ��� ���ڸ��� �ٽ� int�� ��ȯ�Ͽ���.

//Ǯ��
//�ִ� �Ҽ����� 3�ڸ��̱⿡ �ִ� �ο��� 1000������ ��Ƶ� �����ϴ�. ����, �ִ� ������ �Ѹ��� 0~10���� �ټ� �ֱ⿡ 10000���̴�.
//�̰� �̿��ؼ� 1����� �ִ� 1000�����, 1������ �ο� * 10���� ��ȸ�� �ϸ� �Է¹��� int �迭��� ���Ѵ�.

//p.s ���� �ǹ��ε� �������� �ʹ� �������...
//�ε��Ҽ��� ���꿡 �����϶�� �������� �۱Ͱ� �ڲ� ���� ���ϴ�..

using namespace std;

int board[50];
int N;

void MakeAnswer()
{
    for (int i = 1; i <= 1000; ++i)
    {
        int find_num = 0;
        for (int j = 0; j < N; ++j)
        {
            for (int iter = 0; iter <= i * 10; ++iter)
                if (iter * 1000 / i == board[j])
                {
                    ++find_num;
                    break;
                }
        }
        if (find_num == N)
        {
            cout << i << '\n';
            break;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        board[i] = stoi(str.substr(str.find('.') + 1));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}