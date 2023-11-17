import gdb


class GreedyPrinter:
    def __init__(self, value):
        self.__value = value

    def to_string(self):
        return str(self.__value.type)


class StdOptionalPrinter:
    def __init__(self, value):
        self.__value = value

    def to_string(self):
        if not bool(self.__value['_M_payload']['_M_engaged']):
            return "std::nullopt"
        return str(self.__value['_M_payload']['_M_payload']['_M_value'])


def build_pretty_printer():
    pp = gdb.printing.RegexpCollectionPrettyPrinter("pvalue")
    pp.add_printer("Greedy", "^Foo", GreedyPrinter)
    pp.add_printer("StdOptional", "std::optional<.*>", StdOptionalPrinter)
    return pp


gdb.printing.register_pretty_printer(
    gdb.current_objfile(),
    build_pretty_printer())
