#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//Ǯ��
//���ڿ� l�� s�� �޾Ƽ� l���� s�� ��� ���� �ִ����� ���� ������. �ٸ� l���� s�� �߰��ϸ� �� �κ��� �����ϰ� �����κп������� �ٽ� ����� �Ѵ�.
//�׷��⿡ string::find �Լ��� ����ϵ� �������� �Ǵ� idx�� s�� ���̸�ŭ �÷���� �ߺ����� ���� �ƴ��Ѵ�.
//����, �Է¹޴� l, s�� ������ �����Ҽ� �ֱ⿡ ����ó�� cin�� �ƴ� getline�� ���������Ѵ�.

string l, s;

void MakeAnswer()
{
    int answer = 0, idx = 0;

    while (true)
    {
        idx = l.find(s, idx);
        if (idx == string::npos)
            break;
        idx += s.size();
        ++answer;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    getline(cin, l);
    getline(cin, s);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}