import sys
from ast import Ast


def print_truth_table(formula: str):
    try:
        tree = Ast()
        tree.parse_expression(formula)
        tree.print()
        tree.print_truth_table()
    except Exception as e:
        print(e)


def main(argv):
    if len(argv) != 2:
        print("Wrong number of argument")
        return 1
    print_truth_table(argv[1])
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))

# Subject
# | A | B | C | = |$
# |---|---|---|---|$
# | 0 | 0 | 0 | 0 |$
# | 0 | 0 | 1 | 1 |$
# | 0 | 1 | 0 | 0 |$
# | 0 | 1 | 1 | 1 |$
# | 1 | 0 | 0 | 0 |$
# | 1 | 0 | 1 | 1 |$
# | 1 | 1 | 0 | 1 |$
# | 1 | 1 | 1 | 1 |$


# My output
# | A | B | C | = |$
# |---|---|---|---|$
# | 0 | 0 | 0 | 0 |$
# | 0 | 0 | 1 | 1 |$
# | 0 | 1 | 0 | 0 |$
# | 0 | 1 | 1 | 1 |$
# | 1 | 0 | 0 | 0 |$
# | 1 | 0 | 1 | 1 |$
# | 1 | 1 | 0 | 1 |$
# | 1 | 1 | 1 | 1 |$
