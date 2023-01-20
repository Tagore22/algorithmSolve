#include <iostream>
#include <stack>

using namespace std;

//Ǯ��
//����ǥ����� A + B�� ���� AB+�� �����ϴ°� ���Ѵ�. ��, �����ڰ� �������� ��� �׺��� �� 2���� ���� �ش� �����ڷ� ����ϸ� �Ǵµ�
//�̴� stack�� ����ϸ� ����� �ʰ� Ǯ���ִ�. �Էµ� ���� ǥ����� string�� ��Ƶ��� ��ȸ�ϵ�, ���ĺ��� ������ �ش� ���ĺ��� �����Ǵ�
//���� stack�� �����ϰ�, ���ĺ��� �ƴ϶�� stack���� 2���� ���� ������ �ش� �����ڷ� ����� �ٽ� stack�� �ֱ⸦ �ݺ��ϸ� �ȴ�.
//�ٸ�, �Ҽ��� 2�ڸ����� ����ؾ��ϹǷ� int�� �ƴ� double�� ����ؾ��ϸ�, precision ó�� ���� �������� �ȵȴ�.

string str;
int board[26];
int N;

void MakeAnswer()
{
    stack<double> sta;
    for (int i = 0; i < str.size(); ++i)     //�־��� ���� ǥ����� ��ȸ�Ѵ�.
    {
        if ('A' <= str[i] && str[i] <= 'Z')  //���ĺ��� ��� �ش� ���ĺ��� �����Ǵ� ���� ���ÿ� �ִ´�.  
        {
            sta.push(board[str[i] - 'A']);
        }
        else                                 //�������� ��� stack���� 2���� ���� ���� ����� stack�� �ִ´�.
        {
            double second = sta.top();
            sta.pop();
            double first = sta.top();
            sta.pop();

            if (str[i] == '+')              //�����ڿ� ������ ���� �ٸ� ������ ����.
                sta.push(first + second);
            else if (str[i] == '-')
                sta.push(first - second);
            else if (str[i] == '*')
                sta.push(first * second);
            else
                sta.push(first / second);
        }
    }

    cout.precision(2);         //�Ҽ��� ������ ���� �� 2�ڸ����� ��µ�.
    cout << fixed;             //�Ҽ��� ���� 2�ڸ��� ����.
    //cout.unsetf(ios::fixed); //�Ҽ��� ���ķ��� ������ ���� ���.
    cout << sta.top() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> str;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}