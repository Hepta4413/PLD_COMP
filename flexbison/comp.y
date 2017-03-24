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

axiome : prog { *resultat = $1; }
       ; 
prog : 	prog fonction {$1->Add($2); $$ = $1; }
	| %empty {$$= new Fonction();};
fonction : typereturnfonction NOM OPEN arg CLOSE OPENCURLYBRACKET bloc CLOSECURLYBRACKET {$$= new Fonction($1,$2,$4,$7);};
arg : 	argbis {$$=$1;}
	| %empty {$$= NULL;};
argbis :  typefonction NOM {$$=new vector<Variable>(); $$->push_back(new Variable($1,$2));}
	| argbis COMA typefonction NOM {$$=$1; $1->push_back(new Variable($3,$4));};
bloc : bloc contenu {$1->AddContenu($2); $$ = $1; }
	| %empty {$$= new Bloc();};
contenu : ligne SEMICOMA {$$=$1;}
	| bloccontrole {$$=$1;};
ligne : operation {$$=$1;}
	| declaration {$$=$1;}
	| return {$$=$1;};
return : RETURN expr {$$ = new Return($2);}
	| RETURN {$$ = new Return();};
declaration : typebase NOM declarationopt { $$ = new VarS($2,$3,$1);} ;
declarationopt : OPENBRACKET ENTIER CLOSEBRACKET  
		 | EQUAL expr 		
		 | %empty
		 ;
operation : expr {$$=$1;}
	| %empty ;
expr :    expr MUL expr {$$ = new OPBinaire($1, $3, Opbinaire.MUL); }
	| expr PLUS expr {$$ = new OPBinaire($1, $3, Opbinaire.PLUS); }
	| expr MINUS expr {$$ = new OPBinaire($1, $3, Opbinaire.MINUS); }
	| expr DIV expr {$$ = new OPBinaire($1, $3, Opbinaire.DIV); }
	| expr MODULO expr {$$ = new OPBinaire($1, $3, Opbinaire.MODULO); }
	| expr LOWERTHAN expr {$$ = new OPBinaire($1, $3, Opbinaire.LOWERTHAN); }
	| expr UPPEROREQUALTHAN expr {$$ = new OPBinaire($1, $3, Opbinaire.UPPEROREQUALTHAN); }
	| expr LOWEROREQUALTHAN expr {$$ = new OPBinaire($1, $3, Opbinaire.LOWEROREQUALTHAN); }
	| expr UPPERTHAN expr {$$ = new OPBinaire($1, $3, Opbinaire.UPPERTHAN); }
	| expr DOUBLEEQUAL expr {$$ = new OPBinaire($1, $3, Opbinaire.DOUBLEEQUAL); }
	| expr NOTEQUAL expr {$$ = new OPBinaire($1, $3, Opbinaire.NOTEQUAL); }
	| expr AND expr {$$ = new OPBinaire($1, $3, Opbinaire.AND); }
	| expr OR expr {$$ = new OPBinaire($1, $3, Opbinaire.OR); }
	| expr COMA expr {$$ = new OPBinaire($1, $3, Opbinaire.COMA); }
	| var EQUAL expr {$$ = new OPBinaire($1, $3, Opbinaire.EQUAL); }
	| var MULEQUAL expr {$$ = new OPBinaire($1, $3, Opbinaire.MULEQUAL); }
	| var DIVEQUAL expr {$$ = new OPBinaire($1, $3, Opbinaire.DIVEQUAL); }
	| var PLUSEQUAL expr {$$ = new OPBinaire($1, $3, Opbinaire.PLUSEQUAL); }
	| var MINUSEQUAL expr {$$ = new OPBinaire($1, $3, Opbinaire.MINUSEQUAL); }
	| val { $$ = $1; }
	| af { $$ = $1; }
	| OPEN expr CLOSE {$$=$2;}
	| var INCR {$$ = new OPUnaire ($1, Opunaire.INCR);}
	| var DECR {$$ = new OPUnaire ($1, Opunaire.DECR);}	
	| INCR var {$$ = new OPUnaire ($2, Opunaire.INCR);}
	| DECR var {$$ = new OPUnaire ($2, Opunaire.DECR);}
	| MINUS expr {$$ = new OPUnaire ($2, Opunaire.NEG);}
	| NOT expr; {$$ = new OPUnaire ($2, Opunaire.NOT);}
af : NOM OPEN args CLOSE ;
args : argsbis {$$=$1;}
	| %empty {$$=NULL;};
argsbis : expr {$$=new vector<Expression>(); $$->push_back($1);}
	| argsbis COMA expr {$1->push_back($3); $$=$1};
bloccontrole : IF condition OPENCURLYBRACKET bloc CLOSECURLYBRACKET else 
     		| WHILE condition OPENCURLYBRACKET bloc CLOSECURLYBRACKET  
     		| FOR OPEN operation SEMICOMA operation SEMICOMA operation CLOSE OPENCURLYBRACKET bloc CLOSECURLYBRACKET 
     		;
else : ELSE OPENCURLYBRACKET bloc CLOSECURLYBRACKET
	| %empty
	;
condition : OPEN  expr CLOSE;
typenombre : INT32 {$$=Type.INT32;}
	| INT64 {$$=Type.INT64;};
typechar : CHAR {$$=Type.CHAR;};
typebase : typenombre {$$=$1;}
	| typechar {$$=$1;};
typefonction : typebase typebases ;
typebases : OPENBRACKET CLOSEBRACKET | %empty ;
typereturnfonction : VOID {$$=Type.VOID;}
	| typefonction {$$=$1;};
var : 	NOM option ;
option : OPENBRACKET expr CLOSEBRACKET | %empty ;
val : 	var {$$=$1;}
	| ENTIER {$$=new ;};
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

