import sys
import clang.cindex

def find_callexpr(node):
    if node.kind == clang.cindex.CursorKind.CALL_EXPR:
        print "Found %s [line=%s, col=%s]" % (
            node.spelling, node.location.line, node.location.column)
    for c in node.get_children():
        find_callexpr(c)

index = clang.cindex.Index.create()
tu = index.parse(sys.argv[1])
find_callexpr(tu.cursor)
