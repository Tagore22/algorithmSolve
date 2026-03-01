#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    vector<char> board;

    while (true)
    {
        cin >> str;
        if (str == "#")
            break;

        board.clear();
        int idx = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
                str[i] == 'u')
                break;
            board.push_back(str[i]);
            ++idx;
        }
        for (int i = idx; i < str.size(); ++i)
            cout << str[i];
        for (auto& c : board)
            cout << c;
        cout << "ay" << '\n';
    }
    return 0;
}