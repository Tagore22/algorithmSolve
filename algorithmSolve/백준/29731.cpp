#include <iostream>
#include <string>

using namespace std;

string board[7] = { "Never gonna give you up", "Never gonna let you down",
                  "Never gonna run around and desert you", "Never gonna make you cry",
                  "Never gonna say goodbye", "Never gonna tell a lie and hurt you",
                  "Never gonna stop" };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    cin.ignore();
    string str;
    bool isAnswer = true;
    for (int iter = 0; iter < N; ++iter)
    {
        getline(cin, str);
        if (!isAnswer)
            continue;
        bool isFind = false;
        for (int i = 0; i < 7; ++i)
        {
            if (str == board[i])
            {
                isFind = true;
                break;
            }
        }
        isAnswer = !isFind ? false : true;
    }
    cout << (isAnswer ? "No" : "Yes") << '\n';
    return 0;
}