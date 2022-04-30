%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	int yylex(void);
	int yyerror(const char *s);
	int success = 1;
	int current_data_type;
	int expn_type = -1;
	int temp;
	int idx = 0;
	int table_idx = 0;
	int tabs = 0;
	char loop_var[30];
	int array_dims[2];
	struct symbol_table{char var_name[30]; int type;} sym_table[20];
	extern int lookup_in_table(char var[30]);
	extern void insert_to_table(char var[30], int type);
	extern void indent();
	char var_list[20][30];
	int string_or_var[20];
	extern int *yytext;
%}

%union{
int data_type;
char var_name[30];
int value;
char text[30];
}

%token COMMENT FUNC MAIN START COLON HIPHEN END VAR_DECL INT CHAR FLOAT DOUBLE PRINT READ FOR TO OF DO ENDFOR IF ELSEIF ELSE ENDIF RERUN UNTIL WHILE ENDWHILE ARROW LB RB SC COMA ASSIGNMENT LAND LOR GEQ LEQ GT LT NEQ DEQ PLUS MINUS MUL DIV MOD NOT TEXT VAR NUMBER ARRAY

%left LAND LOR GEQ LEQ NOT GT LT NEQ DEQ PLUS MINUS MUL DIV MOD

%token<data_type>INT
%token<data_type>CHAR
%token<data_type>FLOAT
%token<data_type>DOUBLE

%type<data_type>DATA_TYPE
%type<var_name>VAR
%type<value>NUMBER
%type<text>TEXT

%start prm
%%

prm: FUNC MAIN LB RB START COLON { printf("#include<stdio.h>\nint main()\n{\n");  }
     PROG_STATEMENTS END COLON { printf("\n}"); }

PROG_STATEMENTS: PROG_STATEMENTS PROG_STATEMENT | ;

PROG_STATEMENT: VAR_DECL DATA_TYPE VAR_LIST SC {
                if(current_data_type == 0) { printf("int "); }
                else if(current_data_type == 1) { printf("char "); }
                else if(current_data_type == 2) { printf("float "); }
                else if(current_data_type == 3) { printf("double "); }

                for(int i=0; i<idx-1; i++)
                {
                    printf("%s, ", var_list[i]);
                }
                printf("%s;\n", var_list[idx-1]);
                idx = 0;
                }
              | VAR {
                    printf("%s", $1);
                    if((temp=lookup_in_table($1))!=-1)
              					{
              						if(expn_type==-1)
              						{
              							expn_type=temp;
              						}
                          else if(expn_type!=temp)
              						{
              							printf("\ntype mismatch in the expression\n");
              							yyerror("");
              							exit(0);
              						}
              					}
                        else
              					{
              						printf("\n variable \"%s\" undeclared\n",$1);
              						yyerror("");
              						exit(0);
              					}
              					expn_type=-1;

                    }
                    ASSIGNMENT { printf("="); } A_EXPN SC { printf(";\n"); } //Handles var := something.

              |READ LB TO_READ RB SC {
              printf("scanf(\"");
              for(int i=0; i<idx; i++)
              {
                if((temp=lookup_in_table(var_list[i])) != -1)
                {
                  if(temp==0) { printf("%%d"); }
                  else if(temp==1) { printf("%%c"); }
                  else if(temp==2) { printf("%%f"); }
                  else if(temp==3) { printf("%%lf"); }
                }
                else
                {
                  printf("Undeclared variable %s !", yylval.var_name);
                  yyerror("");
                  exit(0);
                }
              }
              printf("\"");
              for(int i=0; i<idx; i++)
              {
                printf(",&%s", var_list[i]);
              }
                printf(");\n");
                idx=0; //done checking and printing, reuse var_list.
              }

              | PRINT LB { printf("printf(\""); } TO_WRITE RB SC {
                printf("\"");
                for(int i=0; i<idx; i++)
                {
                  printf(",%s", var_list[i]);
                }
                printf(");\n");
                idx = 0;
              }

							| VAR_DECL VAR_LIST COLON ARRAY {
							 		int j = 0;
									for(int i=0; i<strlen(yytext); i++)
									{
										if(isdigit(yytext[i]))
											{
												array_dims[j] = (int)yytext[i];
												j++;
											}
										}
									}

							OF DATA_TYPE SC {
                if(current_data_type == 0) { printf("int "); }
                else if(current_data_type == 1) { printf("char "); }
                else if(current_data_type == 2) { printf("float "); }
                else if(current_data_type == 3) { printf("double "); }
								else { printf("Invalid data type"); }

								printf(var_list[idx - 1]);
								idx = 0;

								for(int i=0; i<2; i++)
								{ printf("[%d]", array_dims[i]); }
								printf(";\n");
							}

              |IF_BLOCK ENDIF
              |IF_BLOCK ELSEIF_BLOCKS ELSE_BLOCK ENDIF
              |WHILE LB { printf("while("); } A_EXPN RB { printf("){\n"); } DO PROG_STATEMENTS ENDWHILE { printf("}\n"); }
              |RERUN { printf("do{\n");  } PROG_STATEMENTS UNTIL LB { printf("} while("); } A_EXPN RB { printf(");\n"); }
              |FOR LB { printf("for("); } VAR { strcpy(loop_var, yylval.var_name); printf(loop_var); }
               ARROW { printf("="); }
               TERMINAL { printf("; %s", loop_var); } TO { printf("<="); }
               A_EXPN { printf("; %s++", loop_var); }
               RB DO { printf("){\n");   }
               PROG_STATEMENTS ENDFOR {  printf("}\n");}
              |VAR COLON { printf("%s:\n", yylval.var_name); }
              |COMMENT { printf("/%s/\n", yylval.var_name); }

IF_BLOCK: IF LB {   printf("if("); } A_EXPN RB { printf("){\n");   } PROG_STATEMENTS {   printf("}\n"); }

ELSEIF_BLOCKS: ELSEIF_BLOCKS ELSEIF_BLOCK | ;
ELSEIF_BLOCK: ELSEIF { printf("else if("); } A_EXPN RB { printf("){\n"); } PROG_STATEMENT { printf("\n}\n"); }

ELSE_BLOCK: ELSE { printf("else{\n"); } PROG_STATEMENTS { printf("\n}\n"); }

TO_READ: VAR { strcpy(var_list[idx], yylval.var_name); idx++; } COMA TO_READ
       | VAR { strcpy(var_list[idx], yylval.var_name); idx++; }

TO_WRITE: TEXT { printf("%s", yylval.text); } COMA TO_WRITE
        | VAR {
                if((temp=lookup_in_table($1)) != -1)
                {
									if(temp==0)
										printf("%%d");
									else if(temp==1)
										printf("%%c");
									else if(temp==2)
										printf("%%f");
									else
										printf("%%lf");
								}
								else
								{
									printf("Cannot read undeclared variable %s !", yylval.var_name);
									yyerror("");
									exit(0);
								}
                strcpy(var_list[idx], yylval.var_name); idx++; } TO_WRITE
        | TEXT { printf("%s", yylval.text); }
        | VAR { if((temp=lookup_in_table($1)) != -1) {
									if(temp==0)
										printf("%%d");
									else if(temp==1)
										printf("%%c");
									else if(temp==2)
										printf("%%f");
									else
										printf("%%lf");
								}
								else
								{
									printf("Cannot read undeclared variable %s !", yylval.var_name);
									yyerror("");
									exit(0);
								}
                strcpy(var_list[idx], yylval.var_name); idx++;
            }

VAR_LIST: VAR COMA VAR_LIST { strcpy(var_list[idx], $1); idx++; insert_to_table($1, current_data_type); }
				| VAR { strcpy(var_list[idx], $1); idx++; insert_to_table($1, current_data_type); }

DATA_TYPE: 		INT {
     						$$=$1;
     						current_data_type=$1;
     					}
     					| CHAR  {
     						$$=$1;
     						current_data_type=$1;
     					}
     					| FLOAT {
     						$$=$1;
     						current_data_type=$1;
     					}
     					| DOUBLE {
     						$$=$1;
     						current_data_type=$1;
     					}

A_EXPN: A_EXPN PLUS {printf("+");} A_EXPN
				| A_EXPN MINUS {printf("-");} A_EXPN
				| A_EXPN MUL {printf("*");} A_EXPN
				| A_EXPN DIV {printf("/");} A_EXPN
        | A_EXPN MOD {printf("%%");} A_EXPN
        | NOT {printf("!");} A_EXPN
				| A_EXPN LAND {printf("&&");} A_EXPN
        | A_EXPN LOR {printf("||");} A_EXPN
        | A_EXPN LEQ {printf("<=");} A_EXPN
        | A_EXPN GEQ {printf(">=");} A_EXPN
        | A_EXPN GT {printf(">");} A_EXPN
        | A_EXPN LT {printf("<");} A_EXPN
        | A_EXPN DEQ {printf("==");} A_EXPN
        | A_EXPN NEQ {printf("!=");} A_EXPN
        | TERMINAL

TERMINAL: VAR {
              if((temp=lookup_in_table(yylval.var_name))!=-1) {
                printf("%s", yylval.var_name);
                if(expn_type==-1){
                  expn_type=temp;
                }
                else if(expn_type!=temp){
                  printf("\ntype mismatch in the expression\n");
                  yyerror("");
                  exit(0);
                }
              }
              else{
                printf("\n variable \"%s\" undeclared\n", yylval.var_name);
                yyerror("");
                exit(0);
              }
          }
        | NUMBER { printf("%d", yylval.value); }

%%

int lookup_in_table(char var[30])
{
	for(int i=0; i<table_idx; i++)
	{
		if(strcmp(sym_table[i].var_name, var)==0)
			return sym_table[i].type;
	}
	return -1;
}

void insert_to_table(char var[30], int type)
{
	if(lookup_in_table(var)==-1)
	{
		strcpy(sym_table[table_idx].var_name,var);
		sym_table[table_idx].type = type;
		table_idx++;
	}
	else {
		printf("Multiple declaration of variable\n");
		yyerror("");
		exit(0);
	}
}

void indent() {
	for(int i = 0; i < tabs; i++){
		printf("\t");
	}
	return;
}

int main() {
	yyparse();
	return 0;
}

int yyerror(const char *msg) {
	extern int yylineno;
	printf("Parsing failed\nLine number: %d %s\n", yylineno, msg);
	success = 0;
	return 0;
}
