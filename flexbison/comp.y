%code requires{
	#include <stdio.h>
	#include <string>
	#include <vector>
	#include <iostream>
	#include <fstream>
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
	#include "../include/ListeDeclaration.h"
	#include "Affectation.h"
	#include "Return.h"
	#include "BlocIf.h"

	using namespace std;

	void yyerror(Programme **, const char *);
	int yylex(void);
}

%{

%}
%locations
%define parse.error verbose
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
	ListeDeclaration* listedeclarationstmp;
	vector<Declaration*>* declarationsliste;
	vector<Expression*>* expressionsliste;
	bool boolean;
}

%token INT32 CHAR RETURN INT64 PLUS MINUS MUL DIV OPEN CLOSE EQUAL MULEQUAL OREQUAL XOREQUAL ANDEQUAL PLUSEQUAL MODEQUAL MINUSEQUAL DIVEQUAL LOWERTHAN UPPERTHAN LOWEROREQUALTHAN UPPEROREQUALTHAN DOUBLEEQUAL DOUBLEPLUS DOUBLEMINUS QUOTE NOTEQUAL CLOSEBRACKET OPENBRACKET OPENCURLYBRACKET CLOSECURLYBRACKET RSHIFT LSHIFT NOT AND ANDBIT  OR ORBIT XOR MODULO INCR DECR  IF ELSE FOR WHILE SEMICOMA COMA VOID
%token <ival> ENTIER VAR
%token <stringval> NOM
%type <bloc> bloc
%type <ligne> ligne
%type <retour> return
%type <appelfonct> af
%type <blocif> else
%type <type> typenombre typechar typebase typefonction typereturnfonction
%type <variable> var
%type <declaration> declarationopt
%type <bloccontrole> bloccontrole
%type <expression> expr operation condition option val
%type <contenu> contenu
%type <fonction> fonction
%type <programme> prog
%type <declarationsliste> arg argbis multdeclaration declaration
%type <expressionsliste> args argsbis
%type <boolean> typebases

%left COMA
%left EQUAL PLUSEQUAL MINUSEQUAL DIVEQUAL MULEQUAL MODEQUAL OREQUAL XOREQUAL ANDEQUAL
%left AND OR
%left ORBIT
%left XOR
%left ANDBIT
%left DOUBLEEQUAL NOTEQUAL
%left LOWERTHAN LOWEROREQUALTHAN UPPERTHAN UPPEROREQUALTHAN
%left RSHIFT LSHIFT
%left PLUS MINUS
%left MUL DIV MODULO
%left INCR DECR NOT
%left OPEN CLOSE OPENBRACKET CLOSEBRACKET

%parse-param {Programme ** resultat}

%%

axiome : prog { *resultat = $1; }
       ;
prog : 	prog fonction { $1->addFonction($2); $$ = $1; }
	| %empty { $$= new Programme();};
fonction : typereturnfonction NOM OPEN arg CLOSE OPENCURLYBRACKET bloc CLOSECURLYBRACKET { $$= new Fonction($1,$2,$4,$7);};
arg : 	argbis {$$=$1;}
	| %empty {$$= NULL;}
	;
argbis :  typebase NOM typebases {  	
					$$=new vector<Declaration*>();
					$3?($1==INT32_T?INT32TAB_T:($1==INT64_T?INT64TAB_T:CHARTAB_T)):$1; 
					$3?($1==INT32_T?INT32TAB_T:($1==INT64_T?INT64TAB_T:CHARTAB_T)):$1;
					$$->push_back(new Declaration($1,$2));
				 }
	| argbis COMA typebase NOM typebases {  
						$$=$1; 
						$5?($3==INT32_T?INT32TAB_T:($3==INT64_T?INT64TAB_T:CHARTAB_T)):$3;
						$1->push_back(new Declaration($3,$4));
					     }
	;
bloc : bloc contenu {$1->AddContenu($2); $$ = $1; }
	| %empty { $$= new Bloc();}
	;
contenu : ligne SEMICOMA {$$=$1;}
	| bloccontrole {$$=$1; $1->AddLigneColonne(@1.first_line,@1.first_column);}
	| error {$$ = new Ligne();}
	;
ligne : operation {$$=$1; $1->AddLigneColonne(@1.first_line,@1.first_column);}
	| declaration {$$ = new ListeDeclaration($1);  $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| return {$$=$1; $1->AddLigneColonne(@1.first_line,@1.first_column);}
	;
return : RETURN expr {$$ = new Return($2);}
	| RETURN {$$ = new Return();}
	;
declaration : typebase NOM declarationopt multdeclaration{ for (vector<Declaration*>::iterator it = $4->begin() ; it != $4->end(); ++it){
																(*it)->AddInfos($1, (*it)->getName());
															}
															$3->AddInfos($1,$2);
															$4->push_back($3);
															$$ = $4;
														}
			;
multdeclaration: COMA NOM declarationopt multdeclaration {
															$3->AddName($2);
															$4->push_back($3);
															$$ = $4;
														}
				| %empty { $$ = new vector<Declaration*>();}
				;
declarationopt : OPENBRACKET expr CLOSEBRACKET {$$= new Declaration($2);}
		 | EQUAL expr { $$ = new Declaration($2);}
		 | %empty {$$ = new Declaration();}
		 ;
operation : expr {$$=$1;}
	| %empty {$$= NULL;}
	;
expr :    expr MUL expr {$$ = new OPBinaire($1, $3, MULT_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| expr PLUS expr { $$ = new OPBinaire($1, $3, PLUS_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| expr MINUS expr {$$ = new OPBinaire($1, $3, MINUS_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| expr DIV expr {$$ = new OPBinaire($1, $3, DIV_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| expr MODULO expr {$$ = new OPBinaire($1, $3, MODULO_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| expr LOWERTHAN expr {$$ = new OPBinaire($1, $3, LOWERTHAN_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| expr UPPEROREQUALTHAN expr {$$ = new OPBinaire($1, $3, UPPEROREQUAL_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| expr LOWEROREQUALTHAN expr {$$ = new OPBinaire($1, $3, LOWEROREQUAL_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| expr UPPERTHAN expr {$$ = new OPBinaire($1, $3, UPPERTHAN_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| expr DOUBLEEQUAL expr {$$ = new OPBinaire($1, $3, DOUBLEEQUAL_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| expr NOTEQUAL expr {$$ = new OPBinaire($1, $3, NOTEQUAL_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| expr OREQUAL expr {$$ = new OPBinaire($1, $3, OREQUAL_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| expr ANDEQUAL expr {$$ = new OPBinaire($1, $3, ANDEQUAL_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| expr XOREQUAL expr {$$ = new OPBinaire($1, $3, XOREQUAL_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| expr AND expr {$$ = new OPBinaire($1, $3, AND_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| expr OR expr {$$ = new OPBinaire($1, $3, OR_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| expr ANDBIT expr {$$ = new OPBinaire($1, $3, ANDBIT_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| expr ORBIT expr {$$ = new OPBinaire($1, $3, ORBIT_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}	
	| expr LSHIFT expr {$$ = new OPBinaire($1, $3, LSHIFT_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| expr RSHIFT expr {$$ = new OPBinaire($1, $3, RSHIFT_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| expr XOR expr {$$ = new OPBinaire($1, $3, XOR_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| var EQUAL expr {$$ = new Affectation($1, $3, EQUAL_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| var MODEQUAL expr {$$ = new Affectation($1, $3, MODEQUAL_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| var MULEQUAL expr {$$ = new Affectation($1, $3, MULTEQUAL_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| var DIVEQUAL expr {$$ = new Affectation($1, $3, DIVEQUAL_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| var PLUSEQUAL expr {$$ = new Affectation($1, $3, PLUSEQUAL_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| var MINUSEQUAL expr {$$ = new Affectation($1, $3, MINUSEQUAL_OB); $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| val { $$ = $1; $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| af { $$ = $1; $$->AddLigneColonne(@1.first_line,@1.first_column);}
	| OPEN expr CLOSE {$$=$2;$$->AddLigneColonne(@1.first_line,@1.first_column);}
	| var INCR {$$ = new OPUnaire ($1, INCR_OU);$$->AddLigneColonne(@1.first_line,@1.first_column);}
	| var DECR {$$ = new OPUnaire ($1, DECR_OU);$$->AddLigneColonne(@1.first_line,@1.first_column);}
	| INCR var {$$ = new OPUnaire ($2, INCR_OU);$$->AddLigneColonne(@1.first_line,@1.first_column);}
	| DECR var {$$ = new OPUnaire ($2, DECR_OU);$$->AddLigneColonne(@1.first_line,@1.first_column);}
	| MINUS expr {$$ = new OPUnaire ($2, NEG_OU);$$->AddLigneColonne(@1.first_line,@1.first_column);}
	| NOT expr {$$ = new OPUnaire ($2, NOT_OU);$$->AddLigneColonne(@1.first_line,@1.first_column);}
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
	| %empty {$$=new BlocIf();}
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
	| ENTIER {$$=new Const($1);}
	;
%%

void yyerror(Programme ** res, const char * msg) {
   printf("Syntax error : %s ",msg);
   printf(" At line %d : %d\n ",yylloc.first_line,yylloc.first_column);
}

int main(void) {
   //yydebug=1;
   int res = 0;
   Programme* pro;
   res = yyparse(&pro);
   if(yynerrs  == 0)
   {
		pro->verifVariable();
	}
   //TODO arreter si error
   printf("Résutlat : %d\n",res);
   
   map<string,Fonction *> * fonctions = pro->getFonctions();
   
   vector<CFG*> cfgs;
   
   for (map<string,Fonction *>::iterator it=fonctions->begin(); it!=fonctions->end(); ++it)
   {
		Fonction* f = it->second;
		
		if(it->first != "putchar" && it->first != "getchar")
			cfgs.push_back(new CFG(f));
		
		cout << "CFG de la fonction " + it->first + " généré" << endl;
   } 
   
   ofstream codeAs("main.s", ios::out | ios::trunc);
	
	if(codeAs)
	{	
		codeAs << "\t.globl	main\n\n";
		
		for(unsigned int i = 0 ; i < cfgs.size() ; i++)
		{
			cfgs[i]->gen_asm(codeAs);
			printf("Corps fonction %ui généré\n",i);
		}
		
		codeAs.close();
	}
	else
		cerr << "Cannot open file" << endl;
	
   
   return 0;
}
