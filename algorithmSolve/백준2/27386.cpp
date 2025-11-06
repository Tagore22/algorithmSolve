#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string ann, ben;
    cin >> ann >> ben;
    ann += ben;
    sort(ann.begin(), ann.end());
    cout << ann << '\n';
    return 0;
}