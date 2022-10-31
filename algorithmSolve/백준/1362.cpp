#include <iostream>

using namespace std;

//여러 변수들의 입력받아야 하는 시기 및 값을 조정해야하는 시기가 얽혀있어서 어려운듯 보이지만 침착하게 하면 별거 아니다.   

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