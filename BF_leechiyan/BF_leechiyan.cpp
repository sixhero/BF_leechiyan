// BF_leechiyan.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
#include <string>
using namespace std;

//串模式匹配算法
class Solution
{
public:
    /// @brief 串模式算法
    /// @param str 主串
    /// @param sub 子串
    /// @param pos 主串的开始匹配位置
    /// @return 字串在主串出现的起始位置，失败返回0
    int BF(string str, string sub, int pos)
    {
        int i = pos, j = 0;
        while (i < str.length() && j < sub.length())
        {
            if (str[i] == sub[j])
            {
                ++j;
                ++i;
            }
            else
            {
                i = i - j + 1;
                j = 0;
            }
        }
        if (j == sub.length())
        {
            return i - sub.length();
        }
        else
        {
            return 0;
        }
    }

    /// @brief 参数以及返回值同上BF,对一些特殊情况的值有提升
    /// @param str 
    /// @param sub 
    /// @param pos 
    /// @return 
    int BF_leechiyan(string str, string sub, int pos)
    {
        int i = pos, j = 0;
        while (i < str.length() && j < sub.length())
        {
            if (str[i] == sub[j])
            {
                ++j;
                ++i;
            }
            else
            {
                while (i < str.length())
                {
                    i++;
                    if (str[i] == sub[j])
                    {
                        break;
                    }
                }
                if (i < str.length())
                {
                    i = i - j;
                    j = 0;
                }
            }
        }
        if (j == sub.length())
        {
            cout << str.substr(i-sub.length(), sub.length());
            return i - sub.length();
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    Solution su;
    int pos = su.BF("1234567890", "456",0);
    int pos_lechiyan = su.BF_leechiyan("asdfghjklqwerjdhsgfuhidgeygdhjshfhsygufhdbxnbjhgfjsygyugeuhjshdgshghgfjgffuygefjsgdfusgesjfgsjtyuuoiprpcnjasdg", "usgesjfg", 0);
    std::cout << "Hello World!\n";
}
