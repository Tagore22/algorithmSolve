#include <iostream>

using namespace std;

int main()
{
    int V;
    string str;
    cin >> V >> str;
    int A = 0, B = 0;
    for (auto c : str)
    {
        if (c == 'A')
            ++A;
        else
            ++B;
    }
    if (A > B)
        cout << 'A' << '\n';
    else if (A < B)
        cout << 'B' << '\n';
    else
        cout << "Tie" << '\n';
    return 0;
}