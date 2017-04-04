%{
#include <stdio.h>
#include <stdlib.h>
#include "comp.tab.h"
#define YY_USER_ACTION \
    yylloc.first_line = yylloc.last_line; \
    yylloc.first_column = yylloc.last_column; \
    for(int i = 0; yytext[i] != '\0'; i++) { \
        if(yytext[i] == '\n') { \
            yylloc.last_line++; \
            yylloc.last_column = 0; \
        } \
        else { \
            yylloc.last_column++; \
        } \
    }
%}
%option noyywrap
digit [0-9]+
char [a-zA-Z]
%%
"'"{char}"'" { yylval.ival = yytext[1]; return ENTIER; }
"'\\"."'" { yylval.ival = yytext[1]; return ENTIER; }
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
"%="         { return MODEQUAL; }
"/="         { return DIVEQUAL; }
"&="         { return ANDEQUAL; }
"^="         { return XOREQUAL; }
"|="         { return OREQUAL; }
"<<"         { return LSHIFT; }
">>"         { return RSHIFT; }
"&"          { return ANDBIT; }
"|"          { return ORBIT; }
"^"          { return XOR; }
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
[_a-zA-Z][_a-zA-Z0-9]*      {yylval.stringval = new string(yytext); return NOM; }
{digit}      { yylval.ival = atoi(yytext); return ENTIER; }

    
    
    
    
    
