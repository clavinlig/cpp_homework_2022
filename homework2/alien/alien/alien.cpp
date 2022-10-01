#include <iostream>
#include <vector>
#include <string>


int main()
{
    std::vector < std::string > result;
    std::string symbol = "";
    std::string text;

    std::cout << "Enter the text :" << '\n';
    getline(std::cin, text);

    uint64_t pos = 0;
    while (pos < text.size())
    {
        if (std::isspace(text[pos]) || (std::ispunct(text[pos]) && text[pos] != '-'))
        {
            if (symbol.size())
                result.push_back(symbol);

            if (std::ispunct(text[pos]))
            {
                symbol = text[pos];
                result.push_back(symbol);
            }
            symbol = "";
        }
        else
        {
            symbol += text[pos];
        }
        ++pos;
    }

    std::cout << "Result:\n";
    for (std::string k : result)
    {
        std::cout << k << ' ';
    }

    return 0;
}