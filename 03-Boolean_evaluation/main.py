import sys
from ast import Ast


def eval_formula(formula: str) -> bool:
    try:
        tree = Ast()
        tree.parse_expression(formula)
        # tree.print()
        return bool(tree.value())
    except Exception as e:
        print(e)


def main(argv):
    if len(argv) != 2:
        print("Wrong number of argument")
        return 1
    print(eval_formula(argv[1]))
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))
