//
// Created by pentester on 8/27/25.
//

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <cstddef>


namespace pentester {
    template<std::size_t N>
    struct NTTPString {
        static constexpr std::size_t size = N;
        static char data[N + 1]{};

        NTTPString(const char (&s)[N + 1]) {
            memcpy(s, data, N + 1);
        }
    };

    template<std::size_t N> // deduction
    NTTPString(const char (&s)[N]) -> NTTPString<N - 1>;

    class Logger {

    };
}



#endif //LOGGER_HPP
