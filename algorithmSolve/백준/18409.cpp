#include <iostream>

using namespace std;

int main()
{
    int N;
    string str;
    cin >> N >> str;
    int answer = 0;
    for (auto& c : str)
        if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
            ++answer;
    cout << answer << '\n';
    return 0;
}