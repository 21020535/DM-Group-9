#include <iostream>
#include <vector>

void balancedBrackets(int n, int open, int close, std::string s, std::vector<std::string> &ans)
{
    if (n % 2 == 1)
            return balancedBrackets(n - 1, open, close, s, ans);
    if (open == n/2 && close == n/2)
    {
        ans.push_back(s);
        return;
    }
    if (open < n/2)
    {
        balancedBrackets(n, open + 1, close, s + "{", ans);
    }
    if (close < open)
    {
        balancedBrackets(n, open, close + 1, s + "}", ans);
    }
}

int main() {
    std::vector<std::string> ans;
    int n;
    std::cin >> n;
    balancedBrackets(n, 0, 0, "", ans);
    for (auto s : ans)
    {
        std::cout << s << std::endl;
    }
    return 0;
}
