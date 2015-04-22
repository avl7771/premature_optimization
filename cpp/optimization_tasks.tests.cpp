#include "optimization_tasks.hpp"

#include "measure_utilization.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"    // https://github.com/philsquared/Catch

TEST_CASE("String with one number returns number", "[single_number]") {
    std::string content("7");
    REQUIRE(CalculateSecretNumber(content) == 7);
}

TEST_CASE("String with two numbers returns first - second",
          "[two_numbers_ordered]") {
    std::string content("6 7");
    REQUIRE(CalculateSecretNumber(content) == -1);
}

TEST_CASE("Order of numbers is not important", "[two_numbers_unordered]") {
    std::string content("7 6");
    REQUIRE(CalculateSecretNumber(content) == -1);
}

TEST_CASE("String with two numbers and unimportant strings",
          "[two_numbers_with_extra_content]") {
    std::string content("6 out of every 7 C++ developers admit to 'liking it'");
    REQUIRE(CalculateSecretNumber(content) == -1);
}

TEST_CASE("Written numbers up to twelve", "[written_numbers]") {
    {
        std::string content("one");
        REQUIRE(CalculateSecretNumber(content) == 1);
    }

    {
        std::string content("two");
        REQUIRE(CalculateSecretNumber(content) == 2);
    }

    {
        std::string content("three");
        REQUIRE(CalculateSecretNumber(content) == 3);
    }

    {
        std::string content("four");
        REQUIRE(CalculateSecretNumber(content) == 4);
    }

    {
        std::string content("five");
        REQUIRE(CalculateSecretNumber(content) == 5);
    }

    {
        std::string content("six");
        REQUIRE(CalculateSecretNumber(content) == 6);
    }

    {
        std::string content("seven");
        REQUIRE(CalculateSecretNumber(content) == 7);
    }

    {
        std::string content("eight");
        REQUIRE(CalculateSecretNumber(content) == 8);
    }

    {
        std::string content("nine");
        REQUIRE(CalculateSecretNumber(content) == 9);
    }

    {
        std::string content("ten");
        REQUIRE(CalculateSecretNumber(content) == 10);
    }

    {
        std::string content("eleven");
        REQUIRE(CalculateSecretNumber(content) == 11);
    }

    {
        std::string content("twelve");
        REQUIRE(CalculateSecretNumber(content) == 12);
    }
}

TEST_CASE("Written numbers with one capital letter up to twelve",
          "[written_numbers_capitalized]") {
    {
        std::string content("One");
        REQUIRE(CalculateSecretNumber(content) == 1);
    }

    {
        std::string content("Two");
        REQUIRE(CalculateSecretNumber(content) == 2);
    }

    {
        std::string content("Three");
        REQUIRE(CalculateSecretNumber(content) == 3);
    }

    {
        std::string content("Four");
        REQUIRE(CalculateSecretNumber(content) == 4);
    }

    {
        std::string content("Five");
        REQUIRE(CalculateSecretNumber(content) == 5);
    }

    {
        std::string content("Six");
        REQUIRE(CalculateSecretNumber(content) == 6);
    }

    {
        std::string content("Seven");
        REQUIRE(CalculateSecretNumber(content) == 7);
    }

    {
        std::string content("Eight");
        REQUIRE(CalculateSecretNumber(content) == 8);
    }

    {
        std::string content("Nine");
        REQUIRE(CalculateSecretNumber(content) == 9);
    }

    {
        std::string content("Ten");
        REQUIRE(CalculateSecretNumber(content) == 10);
    }

    {
        std::string content("Eleven");
        REQUIRE(CalculateSecretNumber(content) == 11);
    }

    {
        std::string content("Twelve");
        REQUIRE(CalculateSecretNumber(content) == 12);
    }
}

TEST_CASE("Mixed digits and written numbers", "[mixed_numbers])") {
    std::string content("One person and maybe 300 others");
    REQUIRE(CalculateSecretNumber(content) == -299);
}

TEST_CASE("Sample file", "[sample_file]") {
    std::string content(ReadFile("book.txt"));
    REQUIRE(CalculateSecretNumber(content) == -571);
}

TEST_CASE("Sample file speed", "[sample_file_speed]") {
    MeasureUtilization measure;
    std::string content(ReadFile("book.txt"));
    REQUIRE(CalculateSecretNumber(content) == -571);

    WARN("Utilization: " << measure.GetUtilization());
}
