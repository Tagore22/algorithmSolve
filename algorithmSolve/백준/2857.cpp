#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> answer;
    for (int iter = 1; iter <= 5; ++iter)
    {
        string str;
        cin >> str;

        if (str.find("FBI") != string::npos)
            answer.push_back(iter);
    }
    if (answer.empty())
    {
        cout << "HE GOT AWAY!" << '\n';
    }
    else
    {
        for (auto& n : answer)
            cout << n << ' ';
        cout << '\n';
    }
    return 0;
}