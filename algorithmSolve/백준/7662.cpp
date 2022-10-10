#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

//���� ��ü�� ������ ����. ���� �Է� �ްų� �ִ밪 Ȥ�� �ּҰ��� �����س����� �� �������� �ּҰ��� �ִ밪�� ����ϸ� �ȴ�.
//ó���� priority_queue�� 2�� ����ؼ� Ǯ���� ������, ���� ��� �ּҰ��� �����ϸ� �ִ밪�� ���� ť�� �� ���������� �� �ּҰ��� ��������
//�ʰ� ���� �ִ�. �̰� ��� ó���ؾ��ϳ� ������ ����ߴµ� map�� �̿��ؼ� �����ϸ� �����ϰ� �Ҽ� �־���.
//����, ó������ �켱���� ť�� Ÿ���� �ϳ���(�׳� priority_queue�� �̿��Ͽ� ���� ���� �� ������ -�� ���ϴ� �������) ����Ͽ��µ�
//��� 96�ۿ��� ������ ���Դ�. �����غ��� �־����� ������ 32 - @��Ʈ���� �־����µ� �� ���� -1�� ���ϴ� �������� �����÷ο찡 �ɼ� �־���.
//�׷��� �Է¹޴� ������ Ÿ���� �� ū long long���� �ٲپ��ְų� �ƴϸ� �Ʒ� ���Ե��� ť�� Ÿ���� 2���� ������ -1�� ���ϴ� ����� ���־�
//���� ���Ҽ� �ִ�.

int T, k;

void MakeAnswer()
{
    char command;
    int num;
    priority_queue<int, vector<int>, less<int>> gr;
    priority_queue<int, vector<int>, greater<int>> le;
    map<int, int> check;
    for (int i = 0; i < T; ++i)
    {
        while (!gr.empty())
            gr.pop();
        while (!le.empty())
            le.pop();
        check.clear();
        cin >> k;
        for (int j = 0; j < k; ++j)
        {
            cin >> command >> num;
            if (command == 'I')
            {
                gr.push(num);
                le.push(num);
                if (check[num] == 0)
                    check[num] = 1;
                else
                    ++check[num];
            }
            else
            {
                if (num == 1)
                {
                    while (!gr.empty() && check[gr.top()] == 0)
                        gr.pop();
                    if (!gr.empty())
                    {
                        --check[gr.top()];
                        gr.pop();
                    }
                }
                else
                {
                    while (!le.empty() && check[le.top()] == 0)
                        le.pop();
                    if (!le.empty())
                    {
                        --check[le.top()];
                        le.pop();
                    }
                }
            }
        }
        while (!gr.empty() && check[gr.top()] == 0)
            gr.pop();
        while (!le.empty() && check[le.top()] == 0)
            le.pop();

        if (gr.empty() || le.empty())
            cout << "EMPTY" << '\n';
        else
            cout << gr.top() << ' ' << le.top() << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}