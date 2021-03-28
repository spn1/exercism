class Matrix:
    def __init__(self, matrix_string):
        row_strings = matrix_string.split('\n')

        self.__matrix = [ [ int(v) for v in s.split(' ') ] for s in row_strings ]

        print(self.__matrix)

    def row(self, index):
        return self.__matrix[index - 1]

    def column(self, index):
        return [ row[index - 1] for row in self.__matrix ]