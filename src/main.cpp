#include <bits/stdc++.h>
#include "TinyFluent/numbers/number.h"
#include "TinyFluent/collections/string.h"


struct nil {std::string data = "null";};

std::istringstream& operator>>(std::istringstream& is, nil x)
{
    x.data = "not null";
    return is;
}

std::ostringstream& operator<<(std::ostringstream& is, nil x)
{
    is << x.data;
    return is;
}


//std::ostringstream operator<<(std::ostringstream is, nil x)
//{
//    x.data = "not null";
//    return is;
//}

int main() {
    const fluent::basic_string<char> a = "i love suck five cocks";

    std::wcout << (std::basic_string<wchar_t>)a;

}