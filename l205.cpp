#include <unordered_map>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int s_length = s.length();
        int t_length = t.length();
        if (s_length != t_length)
        {
            return false;
        }

        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        short i1 = 65;
        short i2 = 65;
        string temp1;
        string temp2;
        for (const auto &c : s)
        {
            // 找到的
            auto it = map1.find(c);
            if (it != map1.end())
            {
                temp1.push_back(it->second);
                continue;
            }
            map1.insert({c, static_cast<char>(i1)});
            temp1.push_back(static_cast<char>(i1));
            i1 += 1;
        }
        for (const auto &c : t)
        {
            // 找到的
            auto it = map2.find(c);
            if (it != map2.end())
            {
                temp2.push_back(it->second);
                continue;
            }
            map2.insert({c, static_cast<char>(i2)});
            temp2.push_back(static_cast<char>(i2));

            i2 += 1;
        }
        if (temp1 == temp2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    bool t = a.isIsomorphic("foo", "too");
    cout << t;
    return 0;
}
