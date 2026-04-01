#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> map;
string str;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    map["CU"] = "see you";
    map[":-)"] = "I¡¯m happy";
    map[":-("] = "I¡¯m unhappy";
    map[";-)"] = "wink";
    map[":-P"] = "stick out my tongue";
    map["(~.~)"] = "sleepy";
    map["TA"] = "totally awesome";
    map["CCC"] = "Canadian Computing Competition";
    map["CUZ"] = "because";
    map["TY"] = "thank-you";
    map["YW"] = "you¡¯re welcome";
    map["TTYL"] = "talk to you later";

    while (true)
    {
        cin >> str;
        if (map.find(str) == map.end())
            cout << str << '\n';
        else
            cout << map[str] << '\n';
        if (str == "TTYL")
            break;
    }
    return 0;
}