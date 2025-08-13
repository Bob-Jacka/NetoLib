#ifndef LIBIO_HPP
#define LIBIO_HPP

/**
 Custom library for actions in Netology C++ course.
 Version - 1.0.13
 This library could be a module, but no...
*/

#include <iostream>

/**
 * Unified namespace for libio.
 */
namespace libio {

    using cint [[maybe_unused]] = const int; //constant custom integer type

    /**
     *
     * @param str
     */
    inline void println(const std::string &str = "") {
        if (std::cout.good()) {
            std::cout << str << std::endl;
        }
    }

    /**
     *
     * @tparam T generic type
     * @param str
     * @param separator
     */
    template<typename T>
    void print(T str, std::string separator = "") {
        if (cout.good()) {
            std::cout << str << separator;
        }
    }

    /**
     * Writes down int value into variable by address
     * @param variableAddress
     */
    inline void intUserInput(int &variableAddress) {
        if (std::cin.good()) {
            std::cin >> variableAddress;
        }
    }

    /**
     * Writes down long value into variable by address
     * @param variableAddress
     */
    inline void longUserInput(long &variableAddress) {
        if (std::cin.good()) {
            std::cin >> variableAddress;
        }
    }

    /**
     * Writes down string into variable by address
     * @param variableAddress
     */
    inline void stringUserInput(std::string &variableAddress) {
        if (std::cin.good()) {
            std::cin >> variableAddress;
        }
    }

    /**
     * Writes down value into variable by address
     * @tparam T generic type
     * @param variableAddress
     */
    template<typename T>
    void userInput(T &variableAddress) {
        if (std::cin.good()) {
            std::cin >> variableAddress;
        }
    }

    /**
     * Function for array output with separator.
     * Older brother of dynamicArrayOutput
     * @param array
     * @param array_size
     * @param separator
     * @param is_inline
     */
    template<typename T>
    inline void lineArrayOutput(const T *array, const int array_size, const std::string &separator = " ",
                                const bool is_inline = false) {
        for (int i = 0; i < array_size - 1; i++) {
            std::cout << array[i] << separator;
        }
        std::cout << array[array_size - 1];

        if (!is_inline) {
            std::cout << std::endl;
        }
    }

    /**
     * New technology parametrized function for array output with old innovations
     * @tparam T generic type
     * @param array
     * @param size
     * @param reverse
     * @param separator
     */
    template<typename T>
    void dynamicArrayOutput(T *array, const int size, const bool reverse = false, const string &separator = " ") {
        if (reverse) {
            for (int i = size - 1; i >= 0; --i) {
                std::cout << array[i] << separator;
            }
        } else {
            for (int i = 0; i < size; ++i) {
                std::cout << array[i] << separator;
            }
        }
        std::cout << endl;
    }

    /**
     *
     * @tparam T generic type
     * @param array
     * @param rows
     */
    template<typename T>
    void deleteDynamicArray(T *array, const int rows) {
        for (int i = 0; i < rows; ++i) {
            delete[] array[i];
        }
        delete[] array;
    }

    /**
     * Inline function for creating 2d int array
     * @param rows rows of the array
     * @param cols columns of the array`
     * @return: initialized 2d int array
     */
    template<typename T>
    T **create2DArray(const int rows, const int cols) {
        const auto dyn_array = new T *[rows];
        for (int i = 0; i < rows; i++) {
            dyn_array[i] = new int[cols];
        }
        return dyn_array;
    }
}
