yacc -d yacc.y
lex lex.l
gcc header.c y.tab.c lex.yy.c  -o app.exe
./app.exe

# rm a.out
# cd ..
# ./xsm -l library.lib -e Week3/translated.xsm --debug
