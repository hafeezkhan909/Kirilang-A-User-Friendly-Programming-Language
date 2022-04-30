%option yylineno

%{
	#include<stdio.h>
	#include<string.h>
	#include"y.tab.h"
	#include<math.h>
%}
%%

"func"                                          {return FUNC;}
"main"                                          {return MAIN;}
"Start"                                         {return START;}
":"                                             {return COLON;}
"End"                                           {return END;}
"print"                                         {return PRINT;}
"Read"                                          {return READ;}
"forloop"                                       {return FOR;}
"To"                                            {return TO;}
"Of"                                            {return OF;}
"Do"                                            {return DO;}
"EndFor"                                        {return ENDFOR;}
"Check"                                         {return IF;}
"Otherwise"                                     {return ELSEIF;}
"Else"                                          {return ELSE;}
"EndCheck"                                      {return ENDIF;}
"Rerun"                                         {return RERUN;}
"Until"                                         {return UNTIL;}
"While"                                         {return WHILE;}
"EndWhile"                                      {return ENDWHILE;}
"$"(.|\n)*"$"                                   {strcpy(yylval.var_name, yytext); return COMMENT;}
"decl"                                          {return VAR_DECL;}
"num"                                           {yylval.data_type=0; return INT;}
"alph"                                          {yylval.data_type=1; return CHAR;}
"dec"                                           {yylval.data_type=2; return FLOAT;}
"lrg"                                           {yylval.data_type=3; return DOUBLE;}
"+"                                             {return PLUS;}
"-"                                             {return MINUS;}
"*"                                             {return MUL;}
"/"                                             {return DIV;}
"%"                                             {return MOD;}
"<-"                                            {return ARROW;}
"("                                             {return LB;}
")"                                             {return RB;}
"|"                                             {return SC;}
","                                             {return COMA;}
"="                                             {return ASSIGNMENT;}
"and"                                           {return LAND;}
"or"                                            {return LOR;}
"not"                                           {return NOT;}
">="                                            {return GEQ;}
"<="                                            {return LEQ;}
">"                                             {return GT;}
"<"                                             {return LT;}
"!="                                            {return NEQ;}
"=="                                            {return DEQ;}
'[^'"]*'                                        {strcpy(yylval.text, yytext); return TEXT;}
[a-zA-Z]+                                       {strcpy(yylval.var_name, yytext); return VAR;}
[0-9]+                                          {yylval.value = atoi(yytext); return NUMBER;}
Array((\[[0-9]+\]){2})                          {return ARRAY;}
[\n\t ]+                                        {/* ignore whitespace, newline, tab */}
%%

int yywrap(void) {
	return 1;
}
