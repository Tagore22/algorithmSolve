#include <iostream>

using namespace std;

struct man
{
    string name;
    int old;
    int weight;
};

int CompareMan(const man& ins)
{
    if (ins.name == "#" && ins.old == 0 && ins.weight == 0)
        return -1;
    else if (ins.old > 17 || ins.weight >= 80)
        return 1;
    else
        return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        man ins;
        cin >> ins.name >> ins.old >> ins.weight;
        int answer = CompareMan(ins);
        if (answer == -1)
            break;
        else if (answer == 1)
            cout << ins.name << ' ' << "Senior" << '\n';
        else
            cout << ins.name << ' ' << "Junior" << '\n';
    }
    return 0;
}