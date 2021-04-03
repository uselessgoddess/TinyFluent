#ifndef TINYFLUENT_STRING_H
#define TINYFLUENT_STRING_H

namespace fluent
{
    template<typename CharType>
    struct basic_string {
        std::basic_string<CharType> data; // check std::string realisation
        using base = std::basic_string<CharType>;


        template<typename... Args>
        requires
            requires(Args ...args) {base(args...);}
        basic_string(Args ...args) : data(args...) {}





        auto reverse() const {
            auto str = data;
            std::reverse(str.begin(), str.end());
            return basic_string<CharType>(str);
        }

        auto range(int left, int right) const noexcept {
            if(left >= data.size() || right >= data.size() || left > right)
                throw std::logic_error("error: incorrect range format");

            return basic_string<CharType>(data.begin() + left, data.begin() + right + 1);
        }



        template<typename OtherChar>
        operator std::basic_string<OtherChar>() const noexcept {
            return std::basic_string<OtherChar>(data.begin(), data.end());
        }



        template<typename Arg>
        requires
            requires(base object, Arg arg) {{object[arg]};}
        auto operator[](const Arg &arg) const noexcept {
            if(arg >= data.size())
                throw std::logic_error("error: index out of range");

            return data[arg];
        }

        template<typename Arg>
        requires
            requires(base object, Arg arg) {object = arg;}
        auto operator=(const Arg &arg) noexcept {
            return data = arg;
        }

        template<typename Arg>
        requires
            requires(base object, Arg arg) {object += arg;}
        auto operator+(const Arg &arg) const noexcept {
            return data + arg;
        }

        template<typename Arg>
        requires
            requires(base object, Arg arg) {object += arg;}
        auto operator+=(const Arg &arg) noexcept {
            return data += arg;
        }
    };



    /// A string of @c char
    typedef basic_string<char>    string;

    /// A string of @c wchar_t
    typedef basic_string<wchar_t> wstring;

    /// A string of @c char8_t
    typedef basic_string<char8_t> u8string;

    /// A string of @c char16_t
    typedef basic_string<char16_t> u16string;

    /// A string of @c char32_t
    typedef basic_string<char32_t> u32string;



}

#endif //TINYFLUENT_STRING_H
