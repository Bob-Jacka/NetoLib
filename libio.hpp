#ifndef LIBIO_HPP
#define LIBIO_HPP

/**
 Custom library for actions in Netology C++ course.
 Version - 1.1.0
 This library could be a module, but no...
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <filesystem>
#include <algorithm>

/**
 * Unified namespace for libio.
 */
namespace libio {
    using cint [[maybe_unused]] = const int; //constant custom integer type

    /**
     * Contains different output logic
     */
    namespace output {
        /**
         * Print given generic message in console with new line. By default, equal to "".
         * @param str
         */
        inline void println(const std::string &str = "") {
            if (std::cout.good()) {
                std::cout << str << std::endl;
            }
        }

        /**
         * Print given generic message in console without new line
         * @tparam T generic type
         * @param str
         * @param separator
         */
        template<typename T>
        void print(T str, std::string separator = "") {
            if (std::cout.good()) {
                std::cout << str << separator;
            }
        }

        /**
         * Function for array output with separator.
         * Older brother of dynamicArrayOutput
         * @param array generic array pointer
         * @param array_size size of array.
         * @param separator separator value between elements
         * @param is_inline I do not know why I do this.
         */
        template<typename T>
        void lineArrayOutput(const T *array, const int array_size, const std::string &separator = " ",
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
         * @param array generic array pointer.
         * @param size size of the array.
         * @param reverse order of array output, seq or reverse.
         * @param separator separator value between elements
         */
        template<typename T>
        void dynamicArrayOutput(const T *array, const int size, const bool reverse = false, const std::string &separator = " ") {
            if (reverse) {
                for (int i = size - 1; i >= 0; --i) {
                    std::cout << array[i] << separator;
                }
            } else {
                for (int i = 0; i < size; ++i) {
                    std::cout << array[i] << separator;
                }
            }
            std::cout << std::endl;
        }
    }

    /**
     * Contains different input logic.
     */
    namespace input {
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
    }

    /**
     * Contains arrays actions
     */
    namespace array {
        /**
     * Delete dynamically allocated array
     * @tparam T generic type.
     * @param array array of generic type.
     * @param rows rows count in this array.
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

    /**
     * Contains file actions
     */
    namespace file {
        /**
         * Creates file for read and write.
         * @param fileName name of the file, create if not exists.
         * @return file handler.
         */
        inline std::ofstream createWriteFile(const std::string &fileName) {
            std::ofstream file(fileName);
            return file;
        }

        /**
         * Read file line by line.
         * @param fileName name of the file.
         * @return vector with lines.
         */
        inline std::vector<std::string> readFile(const std::string &fileName) {
            auto lines = std::vector<std::string>();
            std::ifstream file(fileName);
            if (file.is_open()) {
                std::string line;
                while (std::getline(file, line)) {
                    lines.emplace_back(line);
                }
                file.close();
                return lines;
            } else {
                std::cerr << "Error reading file " << fileName << std::endl;
                return {};
            }
        }

        /**
         * Write file line by line.
         * @param fileName
         * @param lines
         * @return output file handler.
         */
        inline std::ofstream writeFile(const std::string &fileName, const std::vector<std::string> &lines) {
            auto out = std::ofstream(fileName);
            for (const auto &line: lines) {
                out << line << std::endl;
            }
            return out;
        }

        /**
         * Function for receiving few lines from file.
         * @tparam T generic type.
         * @param fileName name of the file.
         * @param count how many lines to get.
         * @return vector with string values
         */
        template<typename T>
        std::vector<T> get_few_lines_from(const std::string &fileName, const int count) {
            std::ifstream file(fileName);
            auto lines = std::vector<T>();
            int inner_counter = 0;
            std::string line;
            while (std::getline(file, line)) {
                inner_counter++;
                if (inner_counter == count) {
                    break;
                }
                lines.emplace_back(line);
            }
            return lines;
        }

        /**
         * Platform independent filepath getter.
         * @deprecated because crashes program.
         * @return string value of current path
         */
        inline std::string get_cwd() {
            const std::filesystem::path currentPath = std::filesystem::current_path();
            return currentPath.string();
        }
    }
}

#endif
