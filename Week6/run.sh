yacc -d yacc.y
lex lex.l
gcc y.tab.c lex.yy.c -g -o app.exe
./app.exe

# rm a.out
# cd ..
# ./xsm -l library.lib -e Week3/translated.xsm --debug
