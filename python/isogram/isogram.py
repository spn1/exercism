invalid_characters = ['-', ' ']

def is_isogram(string):
    for letter in string:
        if letter not in invalid_characters and \
            (string.count(letter.lower()) + string.count(letter.upper()) > 1): return False
    return True
