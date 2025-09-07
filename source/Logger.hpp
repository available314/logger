//
// Created by pentester on 8/27/25.
//

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <cstddef>
#include <iostream>
#include <utility>
#include <algorithm>


namespace pentester {
    template<std::size_t N>
    struct NTTPString {
        static constexpr std::size_t size = N;
        char data[N + 1]{};

        constexpr NTTPString(const char (&s)[N + 1]) {
            std::copy_n(s, N + 1, data);
        }

        constexpr auto operator<=>(const NTTPString&) const = default;
    };

    template<std::size_t N> // deduction
    NTTPString(const char (&s)[N]) -> NTTPString<N - 1>;

    class Logger {
    public:

        template<NTTPString Str, typename ...Args>
        void log(Args&& ...args) {
            static_assert(countAmpr<Str>() == sizeof...(args));

            log_impl<Str>(0, std::forward<Args>(args)...);
        }
    private:

        template<NTTPString Str>
        void log_impl(std::size_t index) {
            while (Str.data[index]) {
                if (Str.data[index] == '&') [[unlikely]] {
                    index += 1;
                }
                std::cout << Str.data[index];
                index += 1;
            }
        }

        template<NTTPString Str, typename T, typename ...Args>
        void log_impl(std::size_t index, T&& value, Args&& ...args) {
            while (Str.data[index]) {
                if (Str.data[index] == '&') {
                    if (index + 1 < Str.size && Str.data[index + 1] == '&') [[unlikely]] {
                        index += 1;
                    } else {
                        std::cout << value;
                        log_impl<Str>(index + 1, std::forward<Args>(args)...);
                        return;
                    }
                }
                std::cout << Str.data[index];

                index += 1;
            }
        }

        template<NTTPString str>
        consteval std::size_t countAmpr() {
            std::size_t result = 0;
            for (std::size_t i = 0; i < str.size; i++) {
                if (str.data[i] == '&') {
                    if (i >= str.size || str.data[i + 1] != '&') {
                        result++;
                    } else {
                        i += 1;
                    }
                }
            }
            return result;
        }
    };
}



#endif //LOGGER_HPP
