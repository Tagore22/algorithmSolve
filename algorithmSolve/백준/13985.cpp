#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int from = stoi(str.substr(0, 1));
    int to = stoi(str.substr(4, 1));
    int result = stoi(str.substr(8, 1));
    cout << ((from + to == result) ? "YES" : "NO") << '\n';
    return 0;
}