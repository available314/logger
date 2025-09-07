# Logger

A compile-time checked logger using string literal template parameters (NTTPs) for C++20.  
This logger allows formatting messages with placeholders `&` that are replaced by arguments at runtime.

---

## Features

- **Compile-time format checking**: The number of `&` placeholders in the format string must match the number of arguments.
- **NTTP strings**: Uses non-type template parameters (`NTTPString`) for string literals, fully constexpr.
- **Simple substitution**: Each `&` in the format string corresponds to an argument.
- **Supports escaping**: Use `&&` to print a literal `&`.

---

## Usage

```cpp
#include "Logger.hpp"

int main() {
    pentester::Logger logger;

    int value = 42;
    std::string name = "Egor";

    // Logs "Hello Egor, value = 42"
    logger.log<"& Hello &, value = &">(name, value);

    // To print literal '&', use '&&'
    logger.log<"A && B & C">(100);
    // Output: "A & B 100 C"
}
```


## Build Instructions

This project uses **CMake** to configure and build the library and examples.

### Prerequisites

- **C++20 compatible compiler**
    - GCC 10+
    - Clang 12+
    - MSVC 19.30+
- **CMake 3.20+**

---

### Steps

1. **Clone the repository** (if applicable)

    ```bash
    git clone https://github.com/available314/logger.git
    cd logger
    ```

2. **Create a build directory**

   It is recommended to use an out-of-source build:
    ```bash
    mkdir build
    cd build
    ```

3. **Run CMake to configure the project**

   Specify the compiler and build type:
    ```bash
   cmake .. -DCMAKE_CXX_STANDARD=20 -DCMAKE_BUILD_TYPE=Release
   ```
   
4. **Build the project**

    ```bash
    cmake --build .
   ```