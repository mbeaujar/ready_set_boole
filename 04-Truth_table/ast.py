class InvalidToken(Exception):
    pass


OPERATOR = 0
LETTER = 1


class BinOp:
    def __init__(self, operator, left, right):
        self.operator = operator
        self.type = OPERATOR
        self.left = left
        self.right = right

    def get_value(self):
        if self.operator == '|':
            return self.left.get_value() | self.right.get_value()
        elif self.operator == '&':
            return self.left.get_value() & self.right.get_value()
        elif self.operator == '>':
            return not(self.left.get_value() == True and self.right.get_value() == False)
        elif self.operator == "=":
            return self.left.get_value() == self.right.get_value()
        elif self.operator == '^':
            return self.left.get_value() ^ self.right.get_value()
        # elif self.operator == '!':


class Letter:
    def __init__(self, name, value):
        self.name = name
        self.value = value
        self.type = LETTER

    def get_value(self):
        return self.value


class Ast:
    def __init__(self):
        self.values = []
        self.letters = []
        self.first = True
        self.root = None

    def __add_letter(self) -> Letter:
        for i in range(len(self.letters)):
            if self.letters[i].name == self.values[0]:
                self.values.pop(0)
                return self.letters[i]
        # print("name", name)
        new_letter = Letter(self.values[0], 0)
        self.values.pop(0)
        self.letters.append(new_letter)
        return new_letter

    def parse_expression(self, expression):
        for c in expression:
            if c in "|&>=^!+":
                values_len = len(self.values)
                if values_len == 0 or (values_len == 1 and self.first == True):
                    raise InvalidToken("expression can't begin by an operator")
                if self.first == False:
                    new_letter = self.__add_letter()
                    self.root = BinOp(c, self.root, new_letter)
                else:
                    first_letter = self.__add_letter()
                    second_letter = self.__add_letter()
                    self.root = BinOp(c, first_letter, second_letter)
                    self.first = False
            elif c.isalpha():
                self.values.append(c.upper())
            else:
                raise InvalidToken("invalid token in expression")
        values_len = len(self.values)
        if values_len == 1 and self.root == None:
            self.root = self.__add_letter()
        elif values_len > 0:
            raise InvalidToken("invalid number of token")

    def print_truth_table(self):
        number = 0
        letters_len = len(self.letters)
        print("|", end=" ")
        for i in range(letters_len):
            print(self.letters[i].name, end=" | ")
        # print("= |", end="\n|")
        # for i in range(letters_len + 1):
        #     print("---|", end="")
        # print()
        print("= |")
        print("|" + ((letters_len + 1) * "---|"))
        # print("---|", end="")
        # print()
        while number >> letters_len == 0:
            print("|", end=" ")
            for i in range(letters_len):
                # print(self.letters[i].name, end=" ")
                # print("{0:03b}".format((1 << (i - 1)) & number), end=" ")
                self.letters[i].value = 1 if (
                    (1 << ((letters_len - 1) - i)) & number) else 0
                # print(self.letters[i - 1].value, end=" | ")
                print(self.letters[i].value, end=" | ")
            print(self.value(), "|")
            number += 1

    def value(self):
        if self.root != None:
            return self.root.get_value()

    def print(self):
        self.__print_node("", self.root, False)

    def __print_node(self, prefix, node, is_left):
        if node != None:
            print(prefix, end="")
            if is_left == True:
                print("├──", end="")
            else:
                print("└──", end="")
            if node.type == LETTER:
                print("[" + str(node.name) + "]")
            else:
                print("[" + node.operator + "]")
                self.__print_node(
                    prefix + ("|  " if is_left == True else "   "), node.left, True)
                self.__print_node(
                    prefix + ("|  " if is_left == True else "   "), node.right, False)
