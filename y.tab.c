#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "yacc_file.y"

	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include<ctype.h>
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
#line 26 "yacc_file.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
int data_type;
char var_name[30];
int value;
char text[30];
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 57 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define COMMENT 257
#define FUNC 258
#define MAIN 259
#define START 260
#define COLON 261
#define HIPHEN 262
#define END 263
#define VAR_DECL 264
#define INT 265
#define CHAR 266
#define FLOAT 267
#define DOUBLE 268
#define PRINT 269
#define READ 270
#define FOR 271
#define TO 272
#define OF 273
#define DO 274
#define ENDFOR 275
#define IF 276
#define ELSEIF 277
#define ELSE 278
#define ENDIF 279
#define RERUN 280
#define UNTIL 281
#define WHILE 282
#define ENDWHILE 283
#define ARROW 284
#define LB 285
#define RB 286
#define SC 287
#define COMA 288
#define ASSIGNMENT 289
#define LAND 290
#define LOR 291
#define GEQ 292
#define LEQ 293
#define GT 294
#define LT 295
#define NEQ 296
#define DEQ 297
#define PLUS 298
#define MINUS 299
#define MUL 300
#define DIV 301
#define MOD 302
#define NOT 303
#define TEXT 304
#define VAR 305
#define NUMBER 306
#define ARRAY 307
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    3,    0,    2,    2,    4,    6,    8,    4,    4,   11,
   12,    4,   13,    4,    4,    4,    4,   17,   18,    4,
   19,   20,    4,   21,   22,   24,   25,   26,   27,   28,
    4,    4,    4,   29,   30,   14,   15,   15,   32,   33,
   31,   34,   16,   35,    9,    9,   36,   10,   37,   10,
   10,   10,    5,    5,    1,    1,    1,    1,   38,    7,
   39,    7,   40,    7,   41,    7,   42,    7,   43,    7,
   44,    7,   45,    7,   46,    7,   47,    7,   48,    7,
   49,    7,   50,    7,   51,    7,    7,   23,   23,   23,
};
static const short yylen[] = {                            2,
    0,   10,    2,    0,    4,    0,    0,    6,    5,    0,
    0,    7,    0,    8,    2,    3,    4,    0,    0,    9,
    0,    0,    8,    0,    0,    0,    0,    0,    0,    0,
   18,    2,    1,    0,    0,    7,    2,    0,    0,    0,
    7,    0,    3,    0,    4,    1,    0,    4,    0,    3,
    1,    1,    3,    1,    1,    1,    1,    1,    0,    4,
    0,    4,    0,    4,    0,    4,    0,    4,    0,    3,
    0,    4,    0,    4,    0,    4,    0,    4,    0,    4,
    0,    4,    0,    4,    0,    4,    1,    1,    1,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    1,    4,    0,   33,
    0,    0,    0,    0,    0,    0,   21,    0,    0,    3,
    0,    2,   55,   56,   57,   58,    0,    0,    0,   10,
    0,   24,   34,    4,   18,   32,    0,   15,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    7,
    0,   42,   16,    0,   37,   53,    5,   13,    0,    0,
   11,    0,    0,   25,   69,   90,   88,   89,    0,   87,
    0,    0,    0,   39,    4,   17,    0,    0,    0,    0,
    0,    9,    0,    0,   35,   71,   73,   77,   75,   79,
   81,   85,   83,   59,   61,   63,   65,   67,   22,   19,
    0,    0,    0,    0,    0,   50,    0,   45,   26,   70,
    4,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    8,    0,    0,   48,
   12,    0,    0,   72,   74,   78,   76,   80,   82,   86,
   84,   60,   62,   64,   66,   68,    0,    4,   40,   14,
   27,   23,    0,    0,    0,   20,   41,   28,    0,    0,
    0,    0,   30,    4,    0,   31,
};
static const short yydgoto[] = {                          2,
   28,    9,    8,   20,   29,   37,   69,   73,   45,   61,
   43,   80,   77,   21,   39,   54,   49,  126,   34,  125,
   46,   83,   70,  132,  155,  159,  161,  164,   47,  111,
   55,  102,  154,   75,   62,   78,   79,  120,  121,  122,
  123,  124,   84,  112,  113,  115,  114,  116,  117,  119,
  118,
};
static const short yysindex[] = {                      -229,
 -237,    0, -226, -222, -192, -191,    0,    0, -256,    0,
 -188, -262, -211, -210, -187, -186,    0, -183, -158,    0,
 -175,    0,    0,    0,    0,    0, -180, -196, -150,    0,
 -190,    0,    0,    0,    0,    0, -176,    0, -260, -196,
 -167, -182, -294,    0, -165, -178, -272, -234, -272,    0,
 -154,    0,    0, -145,    0,    0,    0,    0,    0,    0,
    0, -156, -151,    0,    0,    0,    0,    0, -148,    0,
 -146, -131, -272,    0,    0,    0, -136, -132, -294, -129,
 -190,    0, -144, -272,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -81, -272, -204, -171, -294,    0, -113,    0,    0,    0,
    0, -272, -272, -272, -272, -272, -272, -272, -272, -272,
 -272, -272, -272, -272, -272, -101,    0, -114, -112,    0,
    0, -250, -204,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -97,    0,    0,    0,
    0,    0, -164, -204,  -82,    0,    0,    0, -272,  -68,
  -95,  -66,    0,    0, -147,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -54,    0,
 -233,    0,    0,    0,    0,    0, -259,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -261,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -236, -247,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -87,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -216,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -79,
    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  132,  -34,    0,   83,  -19,    0,  -33,    0,  157,  -67,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  107,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
#define YYTABLESIZE 239
static const short yytable[] = {                         48,
   10,   54,   23,   24,   25,   26,   11,   12,   41,   59,
   60,  106,   13,   14,   15,   72,   51,   52,   53,   16,
   56,    3,   10,   17,   46,   18,   44,   54,    1,   12,
   65,   66,   67,   68,   13,   14,   15,  130,   52,  101,
  103,   16,   27,   38,   38,   17,   71,   18,   19,   51,
  110,   47,   10,   66,   67,   68,   49,   49,    4,   12,
   36,   36,   36,    5,   13,   14,   15,    6,  128,    7,
   19,   16,   22,   30,   31,   17,  133,   18,  134,  135,
  136,  137,  138,  139,  140,  141,  142,  143,  144,  145,
  146,  147,   10,   23,   24,   25,   26,   32,   33,   12,
   19,   35,   36,   38,   13,   14,   15,   40,   27,   10,
   42,   16,   50,  153,   44,   17,   12,   18,  156,   57,
   63,   13,   14,   15,   58,  160,   64,  166,   16,  165,
   74,   81,   17,   76,   18,   82,  104,   85,   99,  109,
   19,   86,   87,   88,   89,   90,   91,   92,   93,   94,
   95,   96,   97,   98,  100,  105,  107,   19,   86,   87,
   88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
   98,  149,  148,  131,  150,   86,   87,   88,   89,   90,
   91,   92,   93,   94,   95,   96,   97,   98,  152,  158,
  162,   43,   86,   87,   88,   89,   90,   91,   92,   93,
   94,   95,   96,   97,   98,  127,   29,  163,   86,   87,
   88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
   98,   86,   87,   88,   89,   90,   91,   92,   93,   94,
   95,   96,   97,   98,    6,  129,  157,  108,  151,
};
static const short yycheck[] = {                         34,
  257,  261,  265,  266,  267,  268,  263,  264,   28,  304,
  305,   79,  269,  270,  271,   49,  277,  278,  279,  276,
   40,  259,  257,  280,  286,  282,  288,  287,  258,  264,
  303,  304,  305,  306,  269,  270,  271,  105,  286,   73,
   75,  276,  305,  277,  278,  280,  281,  282,  305,  286,
   84,  288,  257,  304,  305,  306,  304,  305,  285,  264,
  277,  278,  279,  286,  269,  270,  271,  260,  102,  261,
  305,  276,  261,  285,  285,  280,  111,  282,  112,  113,
  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,
  124,  125,  257,  265,  266,  267,  268,  285,  285,  264,
  305,  285,  261,  279,  269,  270,  271,  288,  305,  257,
  261,  276,  289,  148,  305,  280,  264,  282,  283,  287,
  286,  269,  270,  271,  307,  159,  305,  275,  276,  164,
  285,  288,  280,  279,  282,  287,  273,  286,  285,  284,
  305,  290,  291,  292,  293,  294,  295,  296,  297,  298,
  299,  300,  301,  302,  286,  288,  286,  305,  290,  291,
  292,  293,  294,  295,  296,  297,  298,  299,  300,  301,
  302,  286,  274,  287,  287,  290,  291,  292,  293,  294,
  295,  296,  297,  298,  299,  300,  301,  302,  286,  272,
  286,  279,  290,  291,  292,  293,  294,  295,  296,  297,
  298,  299,  300,  301,  302,  287,  286,  274,  290,  291,
  292,  293,  294,  295,  296,  297,  298,  299,  300,  301,
  302,  290,  291,  292,  293,  294,  295,  296,  297,  298,
  299,  300,  301,  302,  289,  104,  154,   81,  132,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 307
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"COMMENT","FUNC","MAIN","START",
"COLON","HIPHEN","END","VAR_DECL","INT","CHAR","FLOAT","DOUBLE","PRINT","READ",
"FOR","TO","OF","DO","ENDFOR","IF","ELSEIF","ELSE","ENDIF","RERUN","UNTIL",
"WHILE","ENDWHILE","ARROW","LB","RB","SC","COMA","ASSIGNMENT","LAND","LOR",
"GEQ","LEQ","GT","LT","NEQ","DEQ","PLUS","MINUS","MUL","DIV","MOD","NOT","TEXT",
"VAR","NUMBER","ARRAY",
};
static const char *yyrule[] = {
"$accept : program",
"$$1 :",
"program : FUNC MAIN LB RB START COLON $$1 PROGRAM_STATEMENTS END COLON",
"PROGRAM_STATEMENTS : PROGRAM_STATEMENTS PROGRAM_STATEMENT",
"PROGRAM_STATEMENTS :",
"PROGRAM_STATEMENT : VAR_DECL DATA_TYPE VAR_LIST SC",
"$$2 :",
"$$3 :",
"PROGRAM_STATEMENT : VAR $$2 ASSIGNMENT $$3 A_EXPN SC",
"PROGRAM_STATEMENT : READ LB TO_READ RB SC",
"$$4 :",
"$$5 :",
"PROGRAM_STATEMENT : PRINT LB $$4 TO_WRITE $$5 RB SC",
"$$6 :",
"PROGRAM_STATEMENT : VAR_DECL VAR_LIST COLON ARRAY $$6 OF DATA_TYPE SC",
"PROGRAM_STATEMENT : IF_BLOCK ENDIF",
"PROGRAM_STATEMENT : IF_BLOCK ELSEIF_BLOCKS ENDIF",
"PROGRAM_STATEMENT : IF_BLOCK ELSEIF_BLOCKS ELSE_BLOCK ENDIF",
"$$7 :",
"$$8 :",
"PROGRAM_STATEMENT : WHILE LB $$7 A_EXPN RB $$8 DO PROGRAM_STATEMENTS ENDWHILE",
"$$9 :",
"$$10 :",
"PROGRAM_STATEMENT : RERUN $$9 PROGRAM_STATEMENTS UNTIL LB $$10 A_EXPN RB",
"$$11 :",
"$$12 :",
"$$13 :",
"$$14 :",
"$$15 :",
"$$16 :",
"$$17 :",
"PROGRAM_STATEMENT : FOR LB $$11 VAR $$12 ARROW $$13 TERMINAL $$14 TO $$15 A_EXPN $$16 RB DO $$17 PROGRAM_STATEMENTS ENDFOR",
"PROGRAM_STATEMENT : VAR COLON",
"PROGRAM_STATEMENT : COMMENT",
"$$18 :",
"$$19 :",
"IF_BLOCK : IF LB $$18 A_EXPN RB $$19 PROGRAM_STATEMENTS",
"ELSEIF_BLOCKS : ELSEIF_BLOCKS ELSEIF_BLOCK",
"ELSEIF_BLOCKS :",
"$$20 :",
"$$21 :",
"ELSEIF_BLOCK : ELSEIF LB $$20 A_EXPN RB $$21 PROGRAM_STATEMENT",
"$$22 :",
"ELSE_BLOCK : ELSE $$22 PROGRAM_STATEMENTS",
"$$23 :",
"TO_READ : VAR $$23 COMA TO_READ",
"TO_READ : VAR",
"$$24 :",
"TO_WRITE : TEXT $$24 COMA TO_WRITE",
"$$25 :",
"TO_WRITE : VAR $$25 TO_WRITE",
"TO_WRITE : TEXT",
"TO_WRITE : VAR",
"VAR_LIST : VAR COMA VAR_LIST",
"VAR_LIST : VAR",
"DATA_TYPE : INT",
"DATA_TYPE : CHAR",
"DATA_TYPE : FLOAT",
"DATA_TYPE : DOUBLE",
"$$26 :",
"A_EXPN : A_EXPN PLUS $$26 A_EXPN",
"$$27 :",
"A_EXPN : A_EXPN MINUS $$27 A_EXPN",
"$$28 :",
"A_EXPN : A_EXPN MUL $$28 A_EXPN",
"$$29 :",
"A_EXPN : A_EXPN DIV $$29 A_EXPN",
"$$30 :",
"A_EXPN : A_EXPN MOD $$30 A_EXPN",
"$$31 :",
"A_EXPN : NOT $$31 A_EXPN",
"$$32 :",
"A_EXPN : A_EXPN LAND $$32 A_EXPN",
"$$33 :",
"A_EXPN : A_EXPN LOR $$33 A_EXPN",
"$$34 :",
"A_EXPN : A_EXPN LEQ $$34 A_EXPN",
"$$35 :",
"A_EXPN : A_EXPN GEQ $$35 A_EXPN",
"$$36 :",
"A_EXPN : A_EXPN GT $$36 A_EXPN",
"$$37 :",
"A_EXPN : A_EXPN LT $$37 A_EXPN",
"$$38 :",
"A_EXPN : A_EXPN DEQ $$38 A_EXPN",
"$$39 :",
"A_EXPN : A_EXPN NEQ $$39 A_EXPN",
"A_EXPN : TERMINAL",
"TERMINAL : VAR",
"TERMINAL : NUMBER",
"TERMINAL : TEXT",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 285 "yacc_file.y"


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
#line 486 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 50 "yacc_file.y"
	{ printf("#include<stdio.h>\nint main()\n{\n");  }
break;
case 2:
#line 51 "yacc_file.y"
	{ printf("\n}"); }
break;
case 5:
#line 55 "yacc_file.y"
	{
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
break;
case 6:
#line 68 "yacc_file.y"
	{
                    printf("%s", yystack.l_mark[0].var_name);
                    if((temp=lookup_in_table(yystack.l_mark[0].var_name))!=-1)
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
              						printf("\n variable \"%s\" undeclared\n",yystack.l_mark[0].var_name);
              						yyerror("");
              						exit(0);
              					}
              					expn_type=-1;

                    }
break;
case 7:
#line 92 "yacc_file.y"
	{ printf("="); }
break;
case 8:
#line 92 "yacc_file.y"
	{ printf(";\n"); }
break;
case 9:
#line 94 "yacc_file.y"
	{
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
                idx=0; /*done checking and printing, reuse var_list.*/
              }
break;
case 10:
#line 121 "yacc_file.y"
	{ printf("printf("); }
break;
case 11:
#line 121 "yacc_file.y"
	{printf("\b");}
break;
case 12:
#line 121 "yacc_file.y"
	{
                printf("\"");
                for(int i=0; i<idx; i++)
                {
                  printf(",%s", var_list[i]);
                }
                printf(");\n");
                idx = 0;
              }
break;
case 13:
#line 131 "yacc_file.y"
	{
							 		int j = 0;
									for(int i=0; i<strlen(yylval.var_name); i++)
									{
										if(isdigit(yylval.var_name[i]))
											{
										array_dims[j] = atoi	(&yylval.var_name[i]);									j++;
											}
										}
									}
break;
case 14:
#line 142 "yacc_file.y"
	{
                if(current_data_type == 0) { printf("int "); }
                else if(current_data_type == 1) { printf("char "); }
                else if(current_data_type == 2) { printf("float "); }
                else if(current_data_type == 3) { printf("double "); }
								else { printf("Invalid data type"); }

								printf(var_list[idx - 1]);
								idx = 0;

								for(int i=0; i<2; i++)
								
								{ if(array_dims[i]!=0)
								
								{printf("[%d]", array_dims[i]);}
								array_dims[i]=0;
								}
								printf(";\n");
								
							}
break;
case 18:
#line 166 "yacc_file.y"
	{ printf("while("); }
break;
case 19:
#line 166 "yacc_file.y"
	{ printf("){\n"); }
break;
case 20:
#line 166 "yacc_file.y"
	{ printf("}\n"); }
break;
case 21:
#line 167 "yacc_file.y"
	{ printf("do{\n");  }
break;
case 22:
#line 167 "yacc_file.y"
	{ printf("} while("); }
break;
case 23:
#line 167 "yacc_file.y"
	{ printf(");\n"); }
break;
case 24:
#line 168 "yacc_file.y"
	{ printf("for("); }
break;
case 25:
#line 168 "yacc_file.y"
	{ strcpy(loop_var, yylval.var_name); printf(loop_var); }
break;
case 26:
#line 169 "yacc_file.y"
	{ printf("="); }
break;
case 27:
#line 170 "yacc_file.y"
	{ printf("; %s", loop_var); }
break;
case 28:
#line 170 "yacc_file.y"
	{ printf("<="); }
break;
case 29:
#line 171 "yacc_file.y"
	{ printf("; %s++", loop_var); }
break;
case 30:
#line 172 "yacc_file.y"
	{ printf("){\n");   }
break;
case 31:
#line 173 "yacc_file.y"
	{  printf("}\n");}
break;
case 32:
#line 174 "yacc_file.y"
	{ printf("%s:\n", yylval.var_name); }
break;
case 33:
#line 175 "yacc_file.y"
	{ char subtext[200];
	       		strncpy(subtext,&yylval.var_name[1],strlen(yylval.var_name)-2);
			printf("/*%s*/\n",subtext);}
break;
case 34:
#line 179 "yacc_file.y"
	{   printf("if("); }
break;
case 35:
#line 179 "yacc_file.y"
	{ printf("){\n");   }
break;
case 36:
#line 179 "yacc_file.y"
	{   printf("}\n"); }
break;
case 39:
#line 182 "yacc_file.y"
	{ printf("else if("); }
break;
case 40:
#line 182 "yacc_file.y"
	{ printf("){\n"); }
break;
case 41:
#line 182 "yacc_file.y"
	{ printf("\n}\n"); }
break;
case 42:
#line 184 "yacc_file.y"
	{ printf("else{\n"); }
break;
case 43:
#line 184 "yacc_file.y"
	{ printf("\n}\n"); }
break;
case 44:
#line 186 "yacc_file.y"
	{ strcpy(var_list[idx], yylval.var_name); idx++; }
break;
case 46:
#line 187 "yacc_file.y"
	{ strcpy(var_list[idx], yylval.var_name); idx++; }
break;
case 47:
#line 189 "yacc_file.y"
	{ printf("%s", yylval.text); }
break;
case 49:
#line 190 "yacc_file.y"
	{
                if((temp=lookup_in_table(yystack.l_mark[0].var_name)) != -1)
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
                strcpy(var_list[idx], yylval.var_name); idx++; }
break;
case 51:
#line 209 "yacc_file.y"
	{ printf("%s", yylval.text); }
break;
case 52:
#line 210 "yacc_file.y"
	{ if((temp=lookup_in_table(yystack.l_mark[0].var_name)) != -1) {
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
break;
case 53:
#line 229 "yacc_file.y"
	{ strcpy(var_list[idx], yystack.l_mark[-2].var_name); idx++; insert_to_table(yystack.l_mark[-2].var_name, current_data_type); }
break;
case 54:
#line 230 "yacc_file.y"
	{ strcpy(var_list[idx], yystack.l_mark[0].var_name); idx++; insert_to_table(yystack.l_mark[0].var_name, current_data_type); }
break;
case 55:
#line 232 "yacc_file.y"
	{
     						yyval.data_type=yystack.l_mark[0].data_type;
     						current_data_type=yystack.l_mark[0].data_type;
     					}
break;
case 56:
#line 236 "yacc_file.y"
	{
     						yyval.data_type=yystack.l_mark[0].data_type;
     						current_data_type=yystack.l_mark[0].data_type;
     					}
break;
case 57:
#line 240 "yacc_file.y"
	{
     						yyval.data_type=yystack.l_mark[0].data_type;
     						current_data_type=yystack.l_mark[0].data_type;
     					}
break;
case 58:
#line 244 "yacc_file.y"
	{
     						yyval.data_type=yystack.l_mark[0].data_type;
     						current_data_type=yystack.l_mark[0].data_type;
     					}
break;
case 59:
#line 249 "yacc_file.y"
	{printf("+");}
break;
case 61:
#line 250 "yacc_file.y"
	{printf("-");}
break;
case 63:
#line 251 "yacc_file.y"
	{printf("*");}
break;
case 65:
#line 252 "yacc_file.y"
	{printf("/");}
break;
case 67:
#line 253 "yacc_file.y"
	{printf("%%");}
break;
case 69:
#line 254 "yacc_file.y"
	{printf("!");}
break;
case 71:
#line 255 "yacc_file.y"
	{printf("&&");}
break;
case 73:
#line 256 "yacc_file.y"
	{printf("||");}
break;
case 75:
#line 257 "yacc_file.y"
	{printf("<=");}
break;
case 77:
#line 258 "yacc_file.y"
	{printf(">=");}
break;
case 79:
#line 259 "yacc_file.y"
	{printf(">");}
break;
case 81:
#line 260 "yacc_file.y"
	{printf("<");}
break;
case 83:
#line 261 "yacc_file.y"
	{printf("==");}
break;
case 85:
#line 262 "yacc_file.y"
	{printf("!=");}
break;
case 88:
#line 265 "yacc_file.y"
	{
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
break;
case 89:
#line 283 "yacc_file.y"
	{ printf("%d", yylval.value); }
break;
case 90:
#line 283 "yacc_file.y"
	{printf("%s",yylval.text);}
break;
#line 1114 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
