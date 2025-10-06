#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    set<string> answer;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        answer.insert(str);
    }
    cout << (int)answer.size() << '\n';
    return 0;
}