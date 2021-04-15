yacc -d yacc.y
lex lex.l
gcc y.tab.c lex.yy.c header.c -o app.exe
./app.exe
# lex label.l
# gcc lex.yy.c
# ./a.out
# rm a.out
# cd ..
# ./xsm -l library.lib -e Week3/translated.xsm --debug
