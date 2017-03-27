%{
#include <stdio.h>
#include <string>
#include <vector>
#include "../include/Affectation.h" 
#include "../include/Bloc.h" 
#include "../include/Declaration.h" 
#include "../include/Ligne.h" 
#include "../include/Return.h" 
#include "../include/AppelFonct.h" 
#include "../include/BlocIf.h" 
#include "../include/Enums.h" 
#include "../include/OPBinaire.h" 
#include "../include/Variable.h" 
#include "../include/BlocControle.h" 
#include "../include/BlocWhile.h" 
#include "../include/Expression.h" 
#include "../include/OPUnaire.h" 
#include "../include/VarS.h" 
#include "../include/BlocFor.h" 
#include "../include/Contenu.h"    
#include "../include/Fonction.h"     
#include "../include/Programme.h"  
#include "../include/VarTab.h"

using namespace std;

void yyerror(int *, const char *);
int yylex(void);
%}
%union {
    int ival;
	string* stringval;
	Affectation* affectation;
	Bloc* bloc;
	Declaration* declaration; 
	Ligne* ligne;
	Return* retour;
	AppelFonct* appelfonct;
	BlocIf* blocif;
	Type* type;
	OPBinaire* opbinaire;
	Variable* variable;
	BlocControle* bloccontrole;
	BlocWhile* blocwhile;
	Expression* expression;
	OPUnaire* opunaire;
	VarS* vars;
	BlocFor* blocfor;
	Contenu* contenu;
	Fonction* fonction;
	Programme* programme;
	VarTab* vartab;
	vector<Variable>* variablesliste;
	vector<Expression>* expressionsliste;	
	bool* boolean;
}

%token INT32 CHAR RETURN INT64 PLUS MINUS MUL DIV OPEN CLOSE EQUAL MULEQUAL PLUSEQUAL MINUSEQUAL DIVEQUAL LOWERTHAN UPPERTHAN LOWEROREQUALTHAN UPPEROREQUALTHAN DOUBLEEQUAL DOUBLEPLUS DOUBLEMINUS QUOTE NOTEQUAL CLOSEBRACKET OPENBRACKET OPENCURLYBRACKET CLOSECURLYBRACKET NOT AND OR MODULO INCR DECR  IF ELSE FOR WHILE SEMICOMA COMA VOID  
%token <ival> ENTIER VAR
%token <stringval> NOM
%type <bloc> bloc
%type <declaration> declaration declarationopt
%type <ligne> ligne
%type <retour> return
%type <appelfonct> af
%type <blocif> else
%type <type> typenombre typechar typebase typefonction typereturnfonction
%type <variable> var
%type <bloccontrole> bloccontrole
%type <expression> expr operation condition option val
%type <contenu> contenu  
%type <fonction> fonction    
%type <programme> prog 
%type <variablesliste> arg argbis
%type <expressionsliste> args argsbis
%type <boolean> typebases

%left COMA
%left EQUAL PLUSEQUAL MINUSEQUAL DIVEQUAL MULEQUAL 
%left AND OR 
%left DOUBLEEQUAL NOTEQUAL
%left LOWERTHAN LOWEROREQUALTHAN UPPERTHAN UPPEROREQUALTHAN 
%left PLUS MINUS
%left MUL DIV MODULO
%left INCR DECR NOT 
%left OPEN CLOSE OPENBRACKET CLOSEBRACKET

%parse-param {Programme * resultat}

%%

axiome : prog { resultat = $1; }
       ; 
prog : 	prog fonction {$1->AddFonction($2); $$ = $1; }
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
declaration : typebase NOM declarationopt { $3->AddInfo($1,$2; $$ = $3;} ;
declarationopt : OPENBRACKET ENTIER CLOSEBRACKET {$$= new VarTab($2,1);}
		 | EQUAL expr { $$ = new VarS($2);}	
		 | %empty {$$ = new VarS()};
		 ;
operation : expr {$$=$1;}
	| %empty {$$= NULL;};
expr :    expr MUL expr {$$ = new OPBinaire($1, $3, Opbinaire.MUL_OB); }
	| expr PLUS expr {$$ = new OPBinaire($1, $3, Opbinaire.PLUS_OB); }
	| expr MINUS expr {$$ = new OPBinaire($1, $3, Opbinaire.MINUS_OB); }
	| expr DIV expr {$$ = new OPBinaire($1, $3, Opbinaire.DIV_OB); }
	| expr MODULO expr {$$ = new OPBinaire($1, $3, Opbinaire.MODULO_OB); }
	| expr LOWERTHAN expr {$$ = new OPBinaire($1, $3, Opbinaire.LOWERTHAN_OB); }
	| expr UPPEROREQUALTHAN expr {$$ = new OPBinaire($1, $3, Opbinaire.UPPEROREQUALTHAN_OB); }
	| expr LOWEROREQUALTHAN expr {$$ = new OPBinaire($1, $3, Opbinaire.LOWEROREQUALTHAN_OB); }
	| expr UPPERTHAN expr {$$ = new OPBinaire($1, $3, Opbinaire.UPPERTHAN_OB); }
	| expr DOUBLEEQUAL expr {$$ = new OPBinaire($1, $3, Opbinaire.DOUBLEEQUAL_OB); }
	| expr NOTEQUAL expr {$$ = new OPBinaire($1, $3, Opbinaire.NOTEQUAL_OB); }
	| expr AND expr {$$ = new OPBinaire($1, $3, Opbinaire.AND_OB); }
	| expr OR expr {$$ = new OPBinaire($1, $3, Opbinaire.OR_OB); }
	| expr COMA expr {$$ = new OPBinaire($1, $3, Opbinaire.COMA_OB); }
	| var EQUAL expr {$$ = new Affectation($1, $3, Opbinaire.EQUAL_OB); }
	| var MULEQUAL expr {$$ = new Affectation($1, $3, Opbinaire.MULEQUAL_OB); }
	| var DIVEQUAL expr {$$ = new Affectation($1, $3, Opbinaire.DIVEQUAL_OB); }
	| var PLUSEQUAL expr {$$ = new Affectation($1, $3, Opbinaire.PLUSEQUAL_OB); }
	| var MINUSEQUAL expr {$$ = new Affectation($1, $3, Opbinaire.MINUSEQUAL_OB); }
	| val { $$ = $1; }
	| af { $$ = $1; }
	| OPEN expr CLOSE {$$=$2;}
	| var INCR {$$ = new OPUnaire ($1, Opunaire.INCR_OU);}
	| var DECR {$$ = new OPUnaire ($1, Opunaire.DECR_OU);}	
	| INCR var {$$ = new OPUnaire ($2, Opunaire.INCR_OU);}
	| DECR var {$$ = new OPUnaire ($2, Opunaire.DECR_OU);}
	| MINUS expr {$$ = new OPUnaire ($2, Opunaire.NEG_OU);}
	| NOT expr {$$ = new OPUnaire ($2, Opunaire.NOT_OU);}
	;
af : NOM OPEN args CLOSE {$$=new AppelFonct($1,$3);};
args : argsbis {$$=$1;}
	| %empty {$$=NULL;};
argsbis : expr {$$=new vector<Expression>(); $$->push_back($1);}
	| argsbis COMA expr {$1->push_back($3); $$=$1};
bloccontrole : IF condition OPENCURLYBRACKET bloc CLOSECURLYBRACKET else {$6->AddIf($2,$4);$$=$6;}
     		| WHILE condition OPENCURLYBRACKET bloc CLOSECURLYBRACKET {$$= new ($2,$4);}  
     		| FOR OPEN operation SEMICOMA operation SEMICOMA operation CLOSE OPENCURLYBRACKET bloc CLOSECURLYBRACKET {$$=new BlocFor($3,$5,$7,$10);}
     		;
else : ELSE OPENCURLYBRACKET bloc CLOSECURLYBRACKET {$$=new BlocIf($3);}
	| %empty {$$=new BlocIf();}
	;
condition : OPEN expr CLOSE {$$=$2;};
typenombre : INT32 {$$=Type.INT32_T;}
	| INT64 {$$=Type.INT64_T;};
typechar : CHAR {$$=Type.CHAR_T;};
typebase : typenombre {$$=$1;}
	| typechar {$$=$1;};
typefonction : typebase typebases {$2?($1==Type.INT32_T?Type.INT32TAB_T:($1==Type.INT64_T?Type.INT64TAB_T:CHARTAB)):$1;};
typebases : OPENBRACKET CLOSEBRACKET {$$=1;}| %empty {$$=0;};
typereturnfonction : VOID {$$=Type.VOID_T;}
	| typefonction {$$=$1;};
var : 	NOM option {$$=($2==-1?new VarS($1): new VarTab($1,$2,0));};
option : OPENBRACKET expr CLOSEBRACKET {$$=$2;}| %empty {$$=-1;} ;
val : 	var {$$=$1;}
	| ENTIER {$$=new Expression(Type.CONSTVAL_T,$1);};
%%

void yyerror(int * res, const char * msg) {
   printf("Syntax error : %s\n",msg);
}

int main(void) {
   yydebug=1;
   int res = 0;
   Programme prog;
   res = yyparse(&prog);
   printf("Résutlat : %d\n",res);
   return 0;
}

