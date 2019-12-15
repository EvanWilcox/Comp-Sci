		               /* ---- PROLOGUE ---- */
%{
#include <iostream>
using namespace std;

int lines = 0;
int lexemes = 0;
%}
		              /* ---- DEFINITIONS ---- */
%option noyywrap

NEWLINE     \n
TAB         \t
SPACE       [ ]
NONZERO     [1-9]
DIGIT		    0|{NONZERO}
ALPH        [a-zA-Z]
HEX         {DIGIT}|[ABCDEF]
SIGN        [+-]


INTEGER     {SIGN}?{DIGIT}+
DECIMAL     {INTEGER}\.{DIGIT}+
SCIENTIFIC  {DECIMAL}E{SIGN}?{NONZERO}{DIGIT}*
HEXADECIMAL {HEX}+H
BINARY      [01]+B
PHONE       (({DIGIT}{DIGIT}{DIGIT}[.]{DIGIT}{DIGIT}{DIGIT}[.]{DIGIT}{DIGIT}{DIGIT}{DIGIT}|({DIGIT}{DIGIT}{DIGIT}-{DIGIT}{DIGIT}{DIGIT}-{DIGIT}{DIGIT}{DIGIT}{DIGIT}))|(\({DIGIT}{DIGIT}{DIGIT}\){DIGIT}{DIGIT}{DIGIT}-{DIGIT}{DIGIT}{DIGIT}{DIGIT}))
KEYWORD     (IF|THEN|ELSE|WHILE|END|PROC|PRINT)
IDENTIFIER  {ALPH}({ALPH}|{DIGIT})*
STRING      \"({ALPH}|{DIGIT}|{SPACE})*\"
OPERATOR    [\+\-\*\/\<\>\=]
COMMENT     \%(.)+

%%  		              /* ---- REGULAR EXPRESSIONS ---- */

{SPACE}|{TAB}   { ; }
{NEWLINE}       { lines++; }
{INTEGER}       { cout << "#" << lexemes++ << ": TOKEN: INTCONST   LEXEME: " << yytext << endl; }
{DECIMAL}       { cout << "#" << lexemes++ << ": TOKEN: DECCONST   LEXEME: " << yytext << endl; }
{SCIENTIFIC}    { cout << "#" << lexemes++ << ": TOKEN: SCICONST   LEXEME: " << yytext << endl; }
{HEXADECIMAL}   { cout << "#" << lexemes++ << ": TOKEN: HEXCONST   LEXEME: " << yytext << endl; }
{BINARY}        { cout << "#" << lexemes++ << ": TOKEN: BINCONST   LEXEME: " << yytext << endl; }
{PHONE}         { cout << "#" << lexemes++ << ": TOKEN: PHCONST    LEXEME: " << yytext << endl; }
{KEYWORD}       { cout << "#" << lexemes++ << ": TOKEN: KEYWORD    LEXEME: " << yytext << endl; }
{IDENTIFIER}    { cout << "#" << lexemes++ << ": TOKEN: IDENT      LEXEME: " << yytext << endl; }
{STRING}        { cout << "#" << lexemes++ << ": TOKEN: STRCONST   LEXEME: " << yytext << endl; }
{OPERATOR}      { cout << "#" << lexemes++ << ": TOKEN: OPERATOR   LEXEME: " << yytext << endl; }
{COMMENT}       { ; }
.               { cout << "#" << lexemes++ << ": TOKEN: ?          LEXEME: " << yytext << endl; } 

%%  		              /* ---- EPILOGUE ---- */

int main()
{
    yylex();
    cout << lines << " lines processed." << endl;
    return 0;
}

