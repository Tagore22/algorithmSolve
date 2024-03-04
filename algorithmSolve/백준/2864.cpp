#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 2개의 수를 입력받아 각 수마다 최대값과 최소값을 생성후
// 2개의 최소값과 2개의 최대값을 각각 더하여 출력한다.

int main()
{
    string a, b;
    cin >> a >> b;
    string a_Min = "", a_Max = "";
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] == '5' || a[i] == '6')
        {
            a_Min += "5";
            a_Max += "6";
        }
        else
        {
            a_Min += a[i];
            a_Max += a[i];
        }
    }
    string b_Min = "", b_Max = "";
    for (int i = 0; i < b.size(); ++i)
    {
        if (b[i] == '5' || b[i] == '6')
        {
            b_Min += "5";
            b_Max += "6";
        }
        else
        {
            b_Min += b[i];
            b_Max += b[i];
        }
    }
    cout << stoi(a_Min) + stoi(b_Min) << ' ' << stoi(a_Max) + stoi(b_Max) << '\n';
    return 0;
}