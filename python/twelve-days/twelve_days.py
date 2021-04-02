nth = [
    'first',
    'second',
    'third',
    'fourth',
    'fifth',
    'sixth',
    'seventh',
    'eighth',
    'ninth',
    'tenth',
    'eleventh',
    'twelfth'
]

phrases = [
    "a Partridge in a Pear Tree",
    "two Turtle Doves",
    "three French Hens",
    "four Calling Birds",
    "five Gold Rings",
    "six Geese-a-Laying",
    "seven Swans-a-Swimming",
    "eight Maids-a-Milking",
    "nine Ladies Dancing",
    "ten Lords-a-Leaping",
    "eleven Pipers Piping",
    "twelve Drummers Drumming",
]

def recite_verse(verse):
    result = ['On the {} day of Christmas my true love gave to me: '.format(nth[verse - 1])]

    for day in reversed(range(0, verse)):
        result.append('{}'.format(phrases[day])) if day != 0 or verse == 1 else result.append('and {}'.format(phrases[day]))
        result.append(', ') if day > 0 else result.append('.')

    return ''.join(result)

def recite(start_verse, end_verse):
    result = []

    for current_verse in range(start_verse, end_verse + 1):
        verse = recite_verse(current_verse)
        result.append(verse)

    return result