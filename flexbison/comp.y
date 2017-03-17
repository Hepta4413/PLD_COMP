%{
#include <stdio.h>
void yyerror(int *, const char *);
int yylex(void);
%}
%union {
   int ival; 
}

%token NOM INT32 CHAR RETURN INT64 PLUS MINUS MUL DIV OPEN CLOSE EQUAL MULEQUAL PLUSEQUAL MINUSEQUAL DIVEQUAL LOWERTHAN UPPERTHAN LOWEROREQUALTHAN UPPEROREQUALTHAN DOUBLEEQUAL DOUBLEPLUS DOUBLEMINUS QUOTE NOTEQUAL CLOSEBRACKET OPENBRACKET OPENCURLYBRACKET CLOSECURLYBRACKET NOT AND OR MODULO INCR DECR  IF ELSE FOR WHILE SEMICOMA COMA VOID  
%token <ival> ENTIER VAR


%parse-param { int * resultat }
%left COMA
%left EQUAL PLUSEQUAL MINUSEQUAL DIVEQUAL MULEQUAL 
%left AND OR 
%left DOUBLEEQUAL NOTEQUAL
%left LOWERTHAN LOWEROREQUALTHAN UPPERTHAN UPPEROREQUALTHAN 
%left PLUS MINUS
%left MUL DIV MODULO
%left INCR DECR NOT 
%left OPEN CLOSE OPENBRACKET CLOSEBRACKET

%%

axiome : prog //{ *resultat = $1; }
       ; 
prog : 	prog fonction 
	| %empty;
fonction : typereturnfonction NOM OPEN arg CLOSE OPENCURLYBRACKET bloc CLOSECURLYBRACKET ;
arg : 	argbis 
	| %empty ;
argbis :  typefonction NOM 
	| argbis COMA typefonction NOM ;
bloc : bloc contenu 
	| %empty ;
contenu : ligne SEMICOMA 
	| bloccontrole ;
ligne : operation 
	| declaration 
	| return ;
return : RETURN expr 
	| RETURN ;
declaration : typebase NOM declarationopt
declarationopt : OPENBRACKET ENTIER CLOSEBRACKET ; 
		 | EQUAL expr 		
		 | %empty
		 ;
operation : expr 
	| %empty ;
expr :    expr MUL expr
	| expr PLUS expr
	| expr MINUS expr
	| expr DIV expr
	| expr MODULO expr
	| expr LOWERTHAN expr
	| expr UPPEROREQUALTHAN expr
	| expr LOWEROREQUALTHAN expr
	| expr UPPERTHAN expr
	| expr DOUBLEEQUAL expr
	| expr NOTEQUAL expr
	| expr AND expr
	| expr OR expr
	| var EQUAL expr
	| expr MULEQUAL expr
	| expr DIVEQUAL expr
	| expr PLUSEQUAL expr
	| expr MINUSEQUAL expr
	| val 
	| af 
	| OPEN expr CLOSE 
	| var INCR 
	| var DECR 	
	| INCR var 
	| DECR var
	| MINUS var
	| NOT var;
af : NOM OPEN args CLOSE ;
args : argsbis 
	| %empty ;
argsbis : expr 
	| argsbis COMA expr ;
bloccontrole : IF condition OPENCURLYBRACKET bloc CLOSECURLYBRACKET else 
     		| WHILE condition OPENCURLYBRACKET bloc CLOSECURLYBRACKET  
     		| FOR OPEN operation SEMICOMA expr SEMICOMA operation CLOSE OPENCURLYBRACKET bloc CLOSECURLYBRACKET 
     		;
else : ELSE OPENCURLYBRACKET bloc CLOSECURLYBRACKET
	| %empty
	;
condition : OPEN  expr CLOSE;
typenombre : INT32 
	| INT64 ;
typechar : CHAR ;
typebase : typenombre 
	| typechar ;
typefonction : typebase typebases ;
typebases : OPENBRACKET CLOSEBRACKET | %empty ;
typereturnfonction : VOID 
	| typefonction ;
var : 	NOM option
option : OPENBRACKET expr CLOSEBRACKET | %empty ;
val : 	var 
	| ENTIER ;
%%

void yyerror(int * res, const char * msg) {
   printf("Syntax error : %s\n",msg);
}

int main(void) {
   yydebug=1;
   int res = 0;
   yyparse(&res);
   printf("Résutlat : %d\n",res);
   return 0;
}

