echo "[ test ] || ((test more) && test src)"
[ fdafds ] || ((test more) && test src)

echo "(([ -d src ]))"
(([ -d src ]))

echo "([ -e src ])"
([ -e src ])

echo "([ -f src ])"
([ -f src])

echo "(([ -d src ]) && (test -d src))"
(([ -d src ]) && (test -d src))

echo "(([ -e src ]) && (test -e src))"
(([ -e src ]) && (test -e src))

echo "(([ -f src ]) && (test -f src))"
(([ -f src ]) && (test -f src))

echo "(([ -d src ]) || (test -d src))"
(([ -d src ]) || (test -d src))

echo "(([ -e src ]) || (test -e src))"
(([ -e src ]) || (test -e src))

echo "(([ -f src ]) || (test -f src))"
(([ -f src ]) || (test -f src))

echo "((([ -e src ]) || (test junk) && ls -a) && test -e src)"
((([ -e src ]) || (test junk) && ls -a) && test -e src)

echo "(((test -d src)))"
(((test -d src)))
