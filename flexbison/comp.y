%code requires{
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
	#include "../include/Const.h"

	using namespace std;

	void yyerror(Programme *, const char *);
	int yylex(void);

}

%{

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
	Type type;
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
	vector<Declaration*>* declarationsliste;
	vector<Expression*>* expressionsliste;
	bool boolean;
}

%token INT32 CHAR RETURN INT64 PLUS MINUS MUL DIV OPEN CLOSE EQUAL MULEQUAL PLUSEQUAL MINUSEQUAL DIVEQUAL LOWERTHAN UPPERTHAN LOWEROREQUALTHAN UPPEROREQUALTHAN DOUBLEEQUAL DOUBLEPLUS DOUBLEMINUS QUOTE NOTEQUAL CLOSEBRACKET OPENBRACKET OPENCURLYBRACKET CLOSECURLYBRACKET NOT AND OR MODULO INCR DECR  IF ELSE FOR WHILE SEMICOMA COMA VOID
%token <ival> ENTIER VAR
%token <stringval> NOM
%type <bloc> bloc
%type <ligne> ligne
%type <retour> return
%type <appelfonct> af
%type <blocif> else
%type <type> typenombre typechar typebase typefonction typereturnfonction
%type <variable> var
%type <declaration> declaration declarationopt
%type <bloccontrole> bloccontrole
%type <expression> expr operation condition option val
%type <contenu> contenu
%type <fonction> fonction
%type <programme> prog
%type <declarationsliste> arg argbis
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
prog : 	prog fonction {printf("prog "); $1->AddFonction($2); $$ = $1; }
	| %empty {printf("prog empty "); $$= new Programme();};
fonction : typereturnfonction NOM OPEN arg CLOSE OPENCURLYBRACKET bloc CLOSECURLYBRACKET {printf("Fonction "); $$= new Fonction($1,$2,$4,$7);};
arg : 	argbis {printf("arg ");$$=$1;}
	| %empty {printf("arg null ");$$= NULL;}
	;
argbis :  typefonction NOM {printf("argbis1 ");$$=new vector<Declaration*>(); $$->push_back(new Declaration($1,$2));}
	| argbis COMA typefonction NOM {printf("argbis 2 "); $$=$1; $1->push_back(new Declaration($3,$4));}
	;
bloc : bloc contenu {printf("add contenu bloc");$1->AddContenu($2); $$ = $1; }
	| %empty {printf("Create new bloc"); $$= new Bloc();}
	;
contenu : ligne SEMICOMA {$$=$1;}
	| bloccontrole {$$=$1;}
	;
ligne : operation {$$=$1;}
	| declaration {$$=$1;}
	| return {$$=$1;}
	;
return : RETURN expr {$$ = new Return($2);}
	| RETURN {$$ = new Return();}
	;
declaration : typebase NOM declarationopt { $3->AddInfos($1,$2); $$ = $3;}
	;
declarationopt : OPENBRACKET expr CLOSEBRACKET {$$= new Declaration($2);}
		 | EQUAL expr { $$ = new Declaration($2);}
		 | %empty {printf("Create new declaration"); $$ = new Declaration();}
		 ;
operation : expr {printf("Expression create");$$=$1;}
	| %empty {printf("Create new operation"); $$= NULL;}
	;
expr :    expr MUL expr {$$ = new OPBinaire($1, $3, MULT_OB); }
	| expr PLUS expr {printf("Create new plus"); $$ = new OPBinaire($1, $3, PLUS_OB); }
	| expr MINUS expr {$$ = new OPBinaire($1, $3, MINUS_OB); }
	| expr DIV expr {$$ = new OPBinaire($1, $3, DIV_OB); }
	| expr MODULO expr {$$ = new OPBinaire($1, $3, MODULO_OB); }
	| expr LOWERTHAN expr {$$ = new OPBinaire($1, $3, LOWERTHAN_OB); }
	| expr UPPEROREQUALTHAN expr {$$ = new OPBinaire($1, $3, UPPEROREQUAL_OB); }
	| expr LOWEROREQUALTHAN expr {$$ = new OPBinaire($1, $3, LOWEROREQUAL_OB); }
	| expr UPPERTHAN expr {$$ = new OPBinaire($1, $3, UPPERTHAN_OB); }
	| expr DOUBLEEQUAL expr {$$ = new OPBinaire($1, $3, DOUBLEEQUAL_OB); }
	| expr NOTEQUAL expr {$$ = new OPBinaire($1, $3, NOTEQUAL_OB); }
	| expr AND expr {$$ = new OPBinaire($1, $3, AND_OB); }
	| expr OR expr {$$ = new OPBinaire($1, $3, OR_OB); }
	| var EQUAL expr {$$ = new Affectation($1, $3, EQUAL_OB); }
	| var MULEQUAL expr {$$ = new Affectation($1, $3, MULTEQUAL_OB); }
	| var DIVEQUAL expr {$$ = new Affectation($1, $3, DIVEQUAL_OB); }
	| var PLUSEQUAL expr {$$ = new Affectation($1, $3, PLUSEQUAL_OB); }
	| var MINUSEQUAL expr {$$ = new Affectation($1, $3, MINUSEQUAL_OB); }
	| val { $$ = $1; }
	| af { $$ = $1; }
	| OPEN expr CLOSE {$$=$2;}
	| var INCR {$$ = new OPUnaire ($1, INCR_OU);}
	| var DECR {$$ = new OPUnaire ($1, DECR_OU);}
	| INCR var {$$ = new OPUnaire ($2, INCR_OU);}
	| DECR var {$$ = new OPUnaire ($2, DECR_OU);}
	| MINUS expr {$$ = new OPUnaire ($2, NEG_OU);}
	| NOT expr {$$ = new OPUnaire ($2, NOT_OU);}
	;
af : NOM OPEN args CLOSE {$$=new AppelFonct($1,$3);}
	;
args : argsbis {$$=$1;}
	| %empty {$$=NULL;}
	;
argsbis : expr {$$=new vector<Expression*>(); $$->push_back($1);}
	| argsbis COMA expr {$1->push_back($3); $$=$1;}
	;
bloccontrole : IF condition OPENCURLYBRACKET bloc CLOSECURLYBRACKET else {$6->AddIf($2,$4);$$=$6;}
     		| WHILE condition OPENCURLYBRACKET bloc CLOSECURLYBRACKET {$$= new BlocWhile($2,$4);}
     		| FOR OPEN operation SEMICOMA operation SEMICOMA operation CLOSE OPENCURLYBRACKET bloc CLOSECURLYBRACKET {$$=new BlocFor($3,$5,$7,$10);}
     		;
else : ELSE OPENCURLYBRACKET bloc CLOSECURLYBRACKET {$$=new BlocIf($3);}
	| %empty {printf("Create new blocIF"); $$=new BlocIf();}
	;
condition : OPEN expr CLOSE {$$=$2;}
	;
typenombre : INT32 {$$=INT32_T;}
	| INT64 {$$=INT64_T;}
	;
typechar : CHAR {$$=CHAR_T;}
	;
typebase : typenombre {$$=$1;}
	| typechar {$$=$1;}
	;
typefonction : typebase typebases {$2?($1==INT32_T?INT32TAB_T:($1==INT64_T?INT64TAB_T:CHARTAB_T)):$1;}
	;
typebases : OPENBRACKET CLOSEBRACKET {$$=1;}| %empty {$$=0;}
	;
typereturnfonction : VOID {$$=VOID_T;}
	| typefonction {$$=$1;}
	;
var : 	NOM option {$$=($2==NULL?(Variable*) new VarS($1): (Variable*) new VarTab($1,$2));}
	;
option : OPENBRACKET expr CLOSEBRACKET {$$=$2;}| %empty {$$=NULL;}
	;
val : 	var {$$=$1;}
	| ENTIER {printf("Create new const"); $$=new Const($1);}
	;
%%

void yyerror(Programme * res, const char * msg) {
   printf("Syntax error : %s\n",msg);
}

int main(void) {
   //yydebug=1;
   int res = 0;
   Programme prog;
   res = yyparse(&prog);
   printf("Résutlat : %d\n",res);
   return 0;
}
