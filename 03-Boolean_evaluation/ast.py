
OPERATOR = 0
NUMBER = 1


class InvalidToken(Exception):
    pass


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


class Number:
    def __init__(self, value):
        self.value = value
        self.type = NUMBER

    def get_value(self):
        return self.value


class Ast:
    def __init__(self):
        self.values = []
        self.first = True
        self.root = None

    def parse_expression(self, expression):
        for c in expression:
            if c in "|&>=^!+":
                values_len = len(self.values)
                if values_len == 0 or (values_len == 1 and self.first == True and c != '!'):
                    raise InvalidToken("invalid operator")
                if self.first == False and c != '!':
                    self.root = BinOp(c, self.root, Number(self.values[0]))
                    self.values.pop(0)
                elif c == '!':
                    self.values[0] = 0 if self.values[0] == 1 else 1
                else:
                    self.root = BinOp(
                        c, Number(self.values[0]), Number(self.values[1]))
                    self.values.pop(0)
                    self.values.pop(0)
                    self.first = False
            elif c in "01":
                self.values.append(int(c))
            else:
                raise InvalidToken("invalid token in expression")
        values_len = len(self.values)
        if values_len == 1 and self.root == None:
            self.root = Number(self.values[0])
        elif values_len > 0:
            raise InvalidToken("invalid number of token")

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
            if node.type == NUMBER:
                print("[" + str(node.value) + "]")
            else:
                print("[" + node.operator + "]")
                self.__print_node(
                    prefix + ("|  " if is_left == True else "   "), node.left, True)
                self.__print_node(
                    prefix + ("|  " if is_left == True else "   "), node.right, False)
