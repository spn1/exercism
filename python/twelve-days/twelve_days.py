nth = [
    'first',
    'second',
    'third',
    'fourth',
    'fifth',
    'sixth',
    'seventh',
    'eigth',
    'ninth',
    'tenth',
    'eleventh',
    'twelth'
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
    [
        result.append('{}, '.format(phrases[v])) if v == verse else result.append('and {}.'.format(phrases[v])) \
            for v in reversed(range(0, verse))
    ]
    return result

def recite(start_verse, end_verse):
    current_verse = start_verse
    return recite_verse(current_verse)

print(recite(1,1));
print(recite(4,2));
print(recite(12,12));