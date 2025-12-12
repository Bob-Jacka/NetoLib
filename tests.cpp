#ifdef LIBIO_TEST
    //It can be a separate file
#include "catch_amalgamated.hpp"

    consteval auto positive = "Positive";
    consteval auto negative = "Negative";

    namespace LIB_test {
        /**
         * Tests for input functionality
         */
        namespace input_test {
            TEST_CASE("Should enter value into int variable by address", positive) {
                int var;
                SECTION("Check for parameters") {
                    input::intUserInput(var);
                    CHECK(var != 0);
                }
            }

            TEST_CASE("Should enter value into string variable by address", positive) {
                std::string var;
                SECTION("Check for parameters") {
                    input::stringUserInput(var);
                    CHECK(var != '');
                }
            }

            TEST_CASE("Should enter value long variable by address", positive) {
                long var;
                SECTION("Check for parameters") {
                    input::longUserInput(var);
                    CHECK(var != 0);
                }
            }

            TEST_CASE("Should enter value of known at compile time variable by address, using userInput", positive) {
                int var1;
                std::string var2;
                long var3;
                double var4;
                SECTION("Check for parameters") {
                    input::userInput(var1);
                    input::userInput(var2);
                    input::userInput(var3);
                    input::userInput(var4);
                    CHECK(var1 != 0);
                    CHECK(var2 != '');
                    CHECK(var3 != 0);
                    CHECK(var4 != 0.0);
                }
            }

            TEST_CASE("Should get value from userInput", positive) {
                SECTION("Check for parameters and action") {
                    CHECK(input::userInput<int>() != 0);
                    CHECK(!input::userInput<std::string>().empty());
                    CHECK(input::userInput<double>() != 0.0);
                    CHECK(input::userInput<long>() != 0);
                }
            }
        }

        /**
         * Namespace for string tests
         */
        namespace String_actions {
            TEST_CASE("Should split string into several pieces", positive) {
                const std::string test_string = "Hello World";
                SECTION("Check for parameters") {
                    auto splitted = string::split(test_string, "");
                    REQUIRE(splitted.size() == 2);
                }
            }

            TEST_CASE("Should convert string in UPPER CASE", positive) {
                const std::string test_string = "Hello World";
                SECTION("Check for parameters") {
                    auto after_action = string::change_string_register(test_string, 1);
                    REQUIRE(after_action == "HELLO WORLD");
                }
            }

            TEST_CASE("Should convert string in lower case", positive) {
                const std::string test_string = "Hello World";
                SECTION("Check for parameters") {
                    auto after_action = string::change_string_register(test_string, 2);
                    REQUIRE(after_action == "hello world");
                }
            }

            TEST_CASE("Should throw error due to wrong regis value", positive) {
                const std::string test_string = "Hello World";
                SECTION("Check for parameters") {
                    REQUIRE_THROWS(string::change_string_register(test_string, 3));
                }
            }
        }
    }

#endif
