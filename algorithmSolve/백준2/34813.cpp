#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<char, string> map;
    map['F'] = "Foundation";
    map['C'] = "Claves";
    map['V'] = "Veritas";
    map['E'] = "Exploration";

    string str;
    cin >> str;
    cout << map[str[0]] << '\n';
    return 0;
}