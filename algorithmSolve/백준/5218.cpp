#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    string str1, str2;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> str1 >> str2;
        cout << "Distances: ";
        for (int i = 0; i < str1.size(); ++i)
        {
            int now = str2[i] - str1[i];
            now = now < 0 ? now + 26 : now;
            cout << now << ' ';
        }
        cout << '\n';
    }
    return 0;
}