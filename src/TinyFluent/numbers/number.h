#ifndef TINYFLUENT_NUMBER_H
#define TINYFLUENT_NUMBER_H

namespace fluent {

    template<typename Type>
    concept numberable = requires(Type left, Type right) {
        {left + right} -> std::same_as<Type>;
        {left - right} -> std::same_as<Type>;
        {left * right} -> std::same_as<Type>;
        {left / right} -> std::same_as<Type>;

        {left <=> right};
    };


    template<typename DataType>
    requires
        numberable<DataType>
    struct number {
        DataType data;



        number<DataType>& reverse() const {
//            str
        }

        [[nodiscard]] std::string to_string() const {
            //std::ostringstream stream;
            //stream << data;
            //return stream.str();
        }




        template<typename OtherType>
        /*not explicit*/ operator OtherType() const {
            return number<OtherType>{data};
        }

        template<typename OtherType>
        requires
        std::convertible_to<OtherType, DataType>
        void operator=(const OtherType& other) {
            data = (OtherType)other;
        }

        template<typename OtherType>
        requires
            std::convertible_to<OtherType, DataType>
        void operator=(const number<OtherType>& other) {
            data = (OtherType)other.data;
        }

        template<typename OtherType>
        requires
            std::convertible_to<OtherType, DataType>
        auto operator+(const number<OtherType>& other) const {
            return number<DataType>{data + (DataType)other.data};
        }

        template<typename OtherType>
        requires
            std::convertible_to<OtherType, DataType>
        auto operator-(const number<OtherType>& other) const {
            return number<DataType>{data - (DataType)other.data};
        }

        template<typename OtherType>
        requires
            std::convertible_to<OtherType, DataType>
        auto operator*(const number<OtherType>& other) const {
            return number<DataType>{data * (DataType)other.data};
        }

        template<typename OtherType>
        requires
            std::convertible_to<OtherType, DataType>
        auto operator/(const number<OtherType>& other) const {
            return number<DataType>{data / (DataType)other.data};
        }

        template<typename OtherType>
        requires
            std::convertible_to<OtherType, DataType>
        auto operator<=>(const number<OtherType>& other) const {
            return data <=> (DataType)other.data;
        }

        template<typename OtherType>
        requires
        std::convertible_to<OtherType, DataType>
        auto operator+=(const number<OtherType>& other) {
            data += (DataType)other.data;
        }

        template<typename OtherType>
        requires
            std::convertible_to<OtherType, DataType>
        void operator-=(const number<OtherType>& other) {
            data -= (DataType)other.data;
        }

        template<typename OtherType>
        requires
            std::convertible_to<OtherType, DataType>
        void operator*=(const number<OtherType>& other) {
            data *= (DataType)other.data;
        }

        template<typename OtherType>
        requires
            std::convertible_to<OtherType, DataType>
        void operator/=(const number<OtherType>& other) {
            data /= (DataType)other.data;
        }
    };

}

#endif //TINYFLUENT_NUMBER_H
