#include <iostream>

using namespace std;

int T, a, b; //a�� b���� ����.

//���� �ϳ� ũ���� �ᱹ �ʿ�� �ϴ� ���� �� ������ ���ڸ����⿡ ���� �����ذ��� ������ 10�� �ؼ� �� �������ڸ��� �����ϸ� �ȴ�.
//�ٸ� 0�϶����� 0�� ��ǻ�Ͱ� �ƴ� 10�� ��ǻ���ΰ��� ���ļ� �ѹ� Ʋ�ȴ�.

void MakeAnswer()
{
    for (int i = 0; i < T; ++i)
    {
        cin >> a >> b;
        int now = 1;
        for (int j = 0; j < b; ++j)
        {
            now *= a;
            now %= 10;
        }
        now = now == 0 ? 10 : now;
        cout << now << '\n';
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