import gdb
import re


def test(variable, expected_output):
    output = gdb.execute('print ' + variable, to_string=True)
    print(f"Output: {output}")

    search = re.search('{.*}', output)
    if search:
        output = search.group(0)

    if not expected_output == output:
        print(f"For {variable} variable: expected: {expected_output}, actual: {output}")
        gdb.execute('quit -1')


gdb.execute('source gdb_printer/pvalue/pvalue.py')
gdb.execute('file gdb_printer/pvalue/test/types')

test("theBar", "{b = Foo}")

gdb.execute('quit')
