#include <iostream>

using namespace std;

// Ǯ��.
// ó������ �� ����� ������� ������ ������ �߾��µ�, �ٽ� �����غ��� �׷� �ʿ䰡 ����.
// �Ź� �Է��� ������ �޾ƾ��ϱ⿡ �� ���¿��� �Ź� �ִ뷮�� �����س����� �ȴ�.
// ������ ��ư� Ǫ�� ����� ���� ��� ����. ���ĳ�����.

// �ڼ��� ������ �ּ����� �����.

int T, N;

void MakeAnswer()
{
    // �Ź� �����س����� ������ answer.
    pair<string, int> answer = make_pair("", 0);
    // ���簪�� �����ϴ� cur.
    pair<string, int> cur;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N;
        // N���� �Է��� �޵� ������ �ʿ���� �Ź� �Է¹��������� �������� �����س�����.
        for (int i = 0; i < N; ++i)
        {
            cin >> cur.first >> cur.second;
            answer = answer.second < cur.second ? cur : answer;
        }
        cout << answer.first << '\n';
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