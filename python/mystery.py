import string

def FindWrittenNumber(content, written_number, number):
    numbers = []
    found_pos = string.find(content, written_number)
    while found_pos != -1:
        numbers.append(number)
        content = content[found_pos + len(written_number):]
        found_pos = string.find(content, written_number)

    return numbers

def CalculateSecretNumber(content):
    numbers = []
    current_number = ''
    for character in content:
        if character in string.digits:
            current_number += character
        else:
            if current_number:
                numbers.append(int(current_number))
                current_number = ''
    if current_number:
        numbers.append(int(current_number))

    numbers.extend(FindWrittenNumber(content, 'one', 1))
    numbers.extend(FindWrittenNumber(content, 'One', 1))
    numbers.extend(FindWrittenNumber(content, 'two', 2))
    numbers.extend(FindWrittenNumber(content, 'Two', 2))
    numbers.extend(FindWrittenNumber(content, 'three', 3))
    numbers.extend(FindWrittenNumber(content, 'Three', 3))
    numbers.extend(FindWrittenNumber(content, 'four', 4))
    numbers.extend(FindWrittenNumber(content, 'Four', 4))
    numbers.extend(FindWrittenNumber(content, 'five', 5))
    numbers.extend(FindWrittenNumber(content, 'Five', 5))
    numbers.extend(FindWrittenNumber(content, 'six', 6))
    numbers.extend(FindWrittenNumber(content, 'Six', 6))
    numbers.extend(FindWrittenNumber(content, 'seven', 7))
    numbers.extend(FindWrittenNumber(content, 'Seven', 7))
    numbers.extend(FindWrittenNumber(content, 'eight', 8))
    numbers.extend(FindWrittenNumber(content, 'Eight', 8))
    numbers.extend(FindWrittenNumber(content, 'nine', 9))
    numbers.extend(FindWrittenNumber(content, 'Nine', 9))
    numbers.extend(FindWrittenNumber(content, 'ten', 10))
    numbers.extend(FindWrittenNumber(content, 'Ten', 10))
    numbers.extend(FindWrittenNumber(content, 'eleven', 11))
    numbers.extend(FindWrittenNumber(content, 'Eleven', 11))
    numbers.extend(FindWrittenNumber(content, 'twelve', 12))
    numbers.extend(FindWrittenNumber(content, 'Twelve', 12))

    numbers = sorted(numbers)

    result = 0
    multiplier = 1
    for number in numbers:
        result += number * multiplier
        multiplier *= -1

    return result

def CalculateSecretNumberFromFile(path):
    content = ''
    with open(path) as f:
        for line in f:
            content += line

    return CalculateSecretNumber(content)
