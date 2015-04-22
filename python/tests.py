import mystery
import timeit

def test_string_with_one_number_returns_number():
    content = '7'
    assert mystery.CalculateSecretNumber(content) == 7

def test_string_with_two_numbers_ordered():
    content = '6 7'
    assert mystery.CalculateSecretNumber(content) == -1

def test_string_with_two_numbers_unordered():
    content = '7 6'
    assert mystery.CalculateSecretNumber(content) == -1

def test_string_with_two_numbers_and_strings():
    content = '6 out of every 7 C++ developers admit to "liking it"'
    assert mystery.CalculateSecretNumber(content) == -1

def test_written_numbers_up_to_twelve():
    content = 'one'
    assert mystery.CalculateSecretNumber(content) == 1

    content = 'two'
    assert mystery.CalculateSecretNumber(content) == 2

    content = 'three'
    assert mystery.CalculateSecretNumber(content) == 3

    content = 'four'
    assert mystery.CalculateSecretNumber(content) == 4

    content = 'five'
    assert mystery.CalculateSecretNumber(content) == 5

    content = 'six'
    assert mystery.CalculateSecretNumber(content) == 6

    content = 'seven'
    assert mystery.CalculateSecretNumber(content) == 7

    content = 'eight'
    assert mystery.CalculateSecretNumber(content) == 8

    content = 'nine'
    assert mystery.CalculateSecretNumber(content) == 9

    content = 'ten'
    assert mystery.CalculateSecretNumber(content) == 10

    content = 'eleven'
    assert mystery.CalculateSecretNumber(content) == 11

    content = 'twelve'
    assert mystery.CalculateSecretNumber(content) == 12

def test_written_numbers_capitalized_up_to_twelve():
    content = 'One'
    assert mystery.CalculateSecretNumber(content) == 1

    content = 'Two'
    assert mystery.CalculateSecretNumber(content) == 2

    content = 'Three'
    assert mystery.CalculateSecretNumber(content) == 3

    content = 'Four'
    assert mystery.CalculateSecretNumber(content) == 4

    content = 'Five'
    assert mystery.CalculateSecretNumber(content) == 5

    content = 'Six'
    assert mystery.CalculateSecretNumber(content) == 6

    content = 'Seven'
    assert mystery.CalculateSecretNumber(content) == 7

    content = 'Eight'
    assert mystery.CalculateSecretNumber(content) == 8

    content = 'Nine'
    assert mystery.CalculateSecretNumber(content) == 9

    content = 'Ten'
    assert mystery.CalculateSecretNumber(content) == 10

    content = 'Eleven'
    assert mystery.CalculateSecretNumber(content) == 11

    content = 'Twelve'
    assert mystery.CalculateSecretNumber(content) == 12

def test_mixed_string():
    content = 'One person and maybe 300 others'
    assert mystery.CalculateSecretNumber(content) == -299

def calculate_from_sample_file():
    return mystery.CalculateSecretNumberFromFile('book.txt')

def test_sample_file():
    assert calculate_from_sample_file() == -571

def test_sample_file_speed():
    assert min(timeit.repeat(calculate_from_sample_file, number=10)) == 0
