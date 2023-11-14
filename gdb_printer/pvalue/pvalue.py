class GreedyPrinter:
    def __init__(self, value):
        self.__value = value

    def to_string(self):
        return str(self.__value.type)


def build_pretty_printer():
    pp = gdb.printing.RegexpCollectionPrettyPrinter("pvalue")
    pp.add_printer("Greedy", "^Foo", GreedyPrinter)
    return pp


gdb.printing.register_pretty_printer(
    gdb.current_objfile(),
    build_pretty_printer())

# def wrapper(aValue):
#   print("MWCK: type=", aValue.type)
#   if str(aValue.type) == "Foo": return FooPrinter(aValue)


# gdb.pretty_printers.append(wrapper)
