%{
#include <stdio.h>
#include <stdlib.h>
#include "comp.tab.h"
%}
%option noyywrap
digit [0-9]+
char [a-zA-Z]
%%
"/*"(.|\n)*"*/" { /* ignore */ }
"//".*$ 	{ /* ignore */ }
[ \n\t] 	{ /* ignore */ }
"#".*$  	{ /* ignore */ }
"<="         { return LOWEROREQUALTHAN; }
">="         { return UPPEROREQUALTHAN; }
"=="         { return DOUBLEEQUAL; }
"!="         { return NOTEQUAL; }
"++"         { return INCR; }
"--"         { return DECR; }
"&&"         { return AND; }
"||"         { return OR; }
"+="         { return PLUSEQUAL; }
"-="         { return MINUSEQUAL; }
"*="         { return MULEQUAL; }
"/="         { return DIVEQUAL; }
"+"          { return PLUS; }
"-"          { return MINUS; }
"*"          { return MUL; }
"/"          { return DIV; }
"("          { return OPEN; }
")"          { return CLOSE; }
"="          { return EQUAL; }
"<"          { return LOWERTHAN; }
">"          { return UPPERTHAN; }
"'"          { return QUOTE; }
"]"          { return CLOSEBRACKET; }
"["          { return OPENBRACKET; }
"}"          { return CLOSECURLYBRACKET; }
"{"          { return OPENCURLYBRACKET; }
"!"          { return NOT; }
"%"          { return MODULO; }
"if"         { return IF; }
"else"       { return ELSE; }
"for"        { return FOR; }
"while"      { return WHILE; }
";"          { return SEMICOMA; }
","          { return COMA; }
"void"       { return VOID; }
"int32_t"    { return INT32; }
"int64_t"    { return INT64; }
"char"       { return CHAR; }
"return"     { return RETURN; }
"'"{char}"'" { yylval.ival = yytext[1]; return ENTIER; }
[_a-zA-Z][_a-zA-Z0-9]*      { return NOM; }
{digit}      { yylval.ival = atoi(yytext); return ENTIER; }



