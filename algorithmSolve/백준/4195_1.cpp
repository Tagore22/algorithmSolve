#include <iostream>
#include <vector>
#include <map>

using namespace std;
int idx;
class uni
{
private:
    map<string, int> trans;
    vector<int> d;
    vector<int> parents;
    vector<int> count;
public:
    int findParents(int name);
    void fusion(string a, string b);
};

int uni::findParents(int name)
{
    if (parents[name] == name)
        return name;
    return parents[name] = findParents(parents[name]);
}

void uni::fusion(string a, string b)// b를 a에 결속시킨다.
{
    if (trans.find(a) == trans.end())
    {
        trans[a] = ++idx;
        d.push_back(0);
        parents.push_back(idx);
        count.push_back(1);
    }
    if (trans.find(b) == trans.end())
    {
        trans[b] = ++idx;
        d.push_back(0);
        parents.push_back(idx);
        count.push_back(1);
    }

    int first = findParents(trans[a]);
    int second = findParents(trans[b]);

    if (first == second)
    {
        cout << count[first] << '\n';
        return;
    }

    if (d[first] < d[second])
        swap(first, second);

    parents[second] = first;
    count[first] += count[second];
    if (d[first] == d[second])
        ++d[first];
    cout << count[first] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        uni UF;
        idx = -1;
        int F;
        cin >> F;
        for (int j = 0; j < F; ++j)
        {
            string a, b;
            cin >> a >> b;
            UF.fusion(a, b);
        }
    }
    return 0;
}