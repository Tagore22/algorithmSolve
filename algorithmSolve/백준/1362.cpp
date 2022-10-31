#include <iostream>

using namespace std;

//���� �������� �Է¹޾ƾ� �ϴ� �ñ� �� ���� �����ؾ��ϴ� �ñⰡ �����־ ������ �������� ħ���ϰ� �ϸ� ���� �ƴϴ�.   

void MakeAnswer()
{
    int o, w, iter = 0;
    while (true)
    {
        cin >> o >> w;
        if (o == 0 && w == 0)
            break;
        char act;
        int num;
        while (true)
        {
            cin >> act >> num;
            if (act == '#' && num == 0)
            {
                cout << ++iter << ' ';
                if (o / 2 < w && w < o * 2)
                    cout << ":-)" << '\n';
                else if (w <= 0)
                    cout << "RIP" << '\n';
                else
                    cout << ":-(" << '\n';
                break;
            }
            else if (act == 'F')
            {
                if (w <= 0)
                    continue;
                w += num;
            }
            else
            {
                if (w <= 0)
                    continue;
                w -= num;
            }
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}