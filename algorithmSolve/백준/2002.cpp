#include <iostream>
#include <queue>
#include <set>

using namespace std;

// Ǯ��.
// �� �������� ������ ������ �����Ǵ� ��Ȳ�� �ľ��ϴ� �����̴�.
// map���� Ǯ� ������ ���� queue�� set�� �̿��ؼ� Ǯ��ô�.

// �ڼ��� ������ �ּ����� �����.

queue<string> first, second;
set<string> check;
int N;

// 1. ���� �ٸ���
// 1-1. ù��°�� �̹� ������ ���ϼ��� �ְ� �ι�°�� �߿��Ѱ��ϼ��� �ִ�.
// 1-2. ù��°�� �������� Ȯ���ϰ� ���������̶�� ù��°�� �ѱ��
// �׷��� �ʴٸ� �ι�°�� ���������̶�� üũ�ϰ� ���� 1 �ø���, �ι�°�� �ѱ��.
// 2. ���� ������ �������� üũ�ϰ� �Ѵ� �Ѿ��.

void MakeAnswer()
{
    int answer = 0;
    string from, to;
    while (!first.empty() && !second.empty())
    {
        from = first.front();
        to = second.front();

        if (from != to)
        {
            if (check.find(from) != check.end())
            {
                first.pop();
            }
            else
            {
                ++answer;
                check.insert(to);
                second.pop();
            }
        }
        else
        {
            check.insert(from);
            first.pop();
            second.pop();
        }
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        first.push(str);
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        second.push(str);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}