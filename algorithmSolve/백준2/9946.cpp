#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str1, str2;
    int idx = 0;
    while (true)
    {
        cin >> str1 >> str2;
        if (str1 == "END")
            break;
        ++idx;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        cout << "Case " << idx << ": ";
        cout << (str1 == str2 ? "same" : "different") << '\n';
    }
    return 0;
}