#include <iostream>
#include <unordered_set>

using namespace std;

string S, E, Q;
unordered_set<string> students;

void Solve()
{
    string time;
    int answer = 0;
    while (cin >> time)
    {
        string name;
        cin >> name;
        if (time <= S)
        {
            students.insert(name);
        }
        else if (E <= time && time <= Q && students.find(name) != students.end())
        {
            ++answer;
            students.erase(name);
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> S >> E >> Q;
}

int main()
{
    Input();
    Solve();
    return 0;
}