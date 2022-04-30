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
#line 25 "yacc_file.y"
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
#line 56 "y.tab.c"

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
    4,   12,    4,    4,    4,   16,   17,    4,   18,   19,
    4,   20,   21,   23,   24,   25,   26,   27,    4,    4,
    4,   28,   29,   13,   14,   14,   31,   32,   30,   33,
   15,   34,    9,    9,   35,   10,   36,   10,   10,   10,
    5,    5,    1,    1,    1,    1,   37,    7,   38,    7,
   39,    7,   40,    7,   41,    7,   42,    7,   43,    7,
   44,    7,   45,    7,   46,    7,   47,    7,   48,    7,
   49,    7,   50,    7,    7,   22,   22,
};
static const short yylen[] = {                            2,
    0,   10,    2,    0,    4,    0,    0,    6,    5,    0,
    6,    0,    8,    2,    4,    0,    0,    9,    0,    0,
    8,    0,    0,    0,    0,    0,    0,    0,   18,    2,
    1,    0,    0,    7,    2,    0,    0,    0,    6,    0,
    3,    0,    4,    1,    0,    4,    0,    3,    1,    1,
    3,    1,    1,    1,    1,    1,    0,    4,    0,    4,
    0,    4,    0,    4,    0,    4,    0,    3,    0,    4,
    0,    4,    0,    4,    0,    4,    0,    4,    0,    4,
    0,    4,    0,    4,    1,    1,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    1,    4,    0,   31,
    0,    0,    0,    0,    0,    0,   19,    0,    0,    3,
    0,    2,   53,   54,   55,   56,    0,    0,    0,   10,
    0,   22,   32,    4,   16,   30,    0,   14,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    7,
   37,   40,    0,   35,   51,    5,   12,    0,    0,    0,
    0,    0,   23,   67,   86,   87,    0,   85,    0,    0,
    0,    0,    4,   15,    0,    0,    0,    0,    0,    9,
    0,    0,   33,   69,   71,   75,   73,   77,   79,   83,
   81,   57,   59,   61,   63,   65,   20,   17,    0,    0,
    0,    0,    0,   48,   11,   43,   24,   68,    4,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    8,   38,    0,   46,    0,    0,
   70,   72,   76,   74,   78,   80,   84,   82,   58,   60,
   62,   64,   66,    0,    4,    0,   13,   25,   21,    0,
   39,    0,   18,   26,    0,    0,    0,    0,   28,    4,
    0,   29,
};
static const short yydgoto[] = {                          2,
   28,    9,    8,   20,   29,   37,   67,   71,   45,   60,
   43,   75,   21,   39,   53,   49,  124,   34,  123,   46,
   81,   68,  129,  152,  155,  157,  160,   47,  109,   54,
   72,  146,   73,   61,   76,   77,  118,  119,  120,  121,
  122,   82,  110,  111,  113,  112,  114,  115,  117,  116,
};
static const short yysindex[] = {                      -252,
 -240,    0, -250, -218, -222, -191,    0,    0, -256,    0,
 -183, -263, -192, -189, -188, -187,    0, -186, -161,    0,
 -178,    0,    0,    0,    0,    0, -185, -200, -157,    0,
 -199,    0,    0,    0,    0,    0, -179,    0, -234, -200,
 -175, -190, -238,    0, -170, -184, -258, -248, -258,    0,
    0,    0, -160,    0,    0,    0,    0,    0,    0, -163,
 -158, -156,    0,    0,    0,    0, -145,    0, -153, -126,
 -258, -258,    0,    0, -148, -155, -238, -152, -199,    0,
 -147, -258,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -76, -109,
 -142, -204, -238,    0,    0,    0,    0,    0,    0, -258,
 -258, -258, -258, -258, -258, -258, -258, -258, -258, -258,
 -258, -258, -258, -138,    0,    0, -143,    0, -232, -142,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -92,    0, -142,    0,    0,    0, -211,
    0, -133,    0,    0, -258,  -63, -144, -116,    0,    0,
 -162,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -130,    0,
 -201,    0,    0,    0,    0,    0, -251,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -261,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -236, -274,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -118,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -223,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -124,    0,    0,    0,    0,
    0,    0,
};
static const short yygindex[] = {                         0,
   76,  -34,    0,   33,  -11,    0,  -31,    0,  101,  -66,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   66,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 239
static const short yytable[] = {                         48,
   10,   23,   24,   25,   26,    1,   11,   12,   10,   52,
  104,   50,   13,   14,   15,   12,   41,   70,    3,   16,
   13,   14,   15,   17,   44,   18,   42,   16,   55,   47,
   47,   17,   69,   18,    4,   52,  128,    6,  101,   99,
  100,   27,   51,   52,   64,   10,   65,   66,   19,   49,
  108,   45,   12,   34,   34,   34,   19,   13,   14,   15,
   23,   24,   25,   26,   16,   58,   59,    5,   17,    7,
   18,  153,   65,   66,  130,   36,   36,   22,  131,  132,
  133,  134,  135,  136,  137,  138,  139,  140,  141,  142,
  143,  144,   30,   19,   10,   31,   32,   33,   35,   36,
   38,   12,   40,   42,   27,   44,   13,   14,   15,   50,
  150,   56,  162,   16,   10,   62,   57,   17,   74,   18,
   63,   12,   78,  156,  102,  161,   13,   14,   15,   79,
   80,   97,  103,   16,  105,  145,  107,   17,  154,   18,
   83,  158,   19,  147,   84,   85,   86,   87,   88,   89,
   90,   91,   92,   93,   94,   95,   96,  159,    6,   98,
   41,   27,   19,   84,   85,   86,   87,   88,   89,   90,
   91,   92,   93,   94,   95,   96,  126,  127,  151,  106,
   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,
   94,   95,   96,  149,  148,    0,    0,   84,   85,   86,
   87,   88,   89,   90,   91,   92,   93,   94,   95,   96,
  125,    0,    0,   84,   85,   86,   87,   88,   89,   90,
   91,   92,   93,   94,   95,   96,   84,   85,   86,   87,
   88,   89,   90,   91,   92,   93,   94,   95,   96,
};
static const short yycheck[] = {                         34,
  257,  265,  266,  267,  268,  258,  263,  264,  257,  261,
   77,  286,  269,  270,  271,  264,   28,   49,  259,  276,
  269,  270,  271,  280,  286,  282,  288,  276,   40,  304,
  305,  280,  281,  282,  285,  287,  103,  260,   73,   71,
   72,  305,  277,  278,  303,  257,  305,  306,  305,  286,
   82,  288,  264,  277,  278,  279,  305,  269,  270,  271,
  265,  266,  267,  268,  276,  304,  305,  286,  280,  261,
  282,  283,  305,  306,  109,  277,  278,  261,  110,  111,
  112,  113,  114,  115,  116,  117,  118,  119,  120,  121,
  122,  123,  285,  305,  257,  285,  285,  285,  285,  261,
  279,  264,  288,  261,  305,  305,  269,  270,  271,  289,
  145,  287,  275,  276,  257,  286,  307,  280,  279,  282,
  305,  264,  286,  155,  273,  160,  269,  270,  271,  288,
  287,  285,  288,  276,  287,  274,  284,  280,  272,  282,
  286,  286,  305,  287,  290,  291,  292,  293,  294,  295,
  296,  297,  298,  299,  300,  301,  302,  274,  289,  286,
  279,  286,  305,  290,  291,  292,  293,  294,  295,  296,
  297,  298,  299,  300,  301,  302,  286,  102,  146,   79,
  290,  291,  292,  293,  294,  295,  296,  297,  298,  299,
  300,  301,  302,  286,  129,   -1,   -1,  290,  291,  292,
  293,  294,  295,  296,  297,  298,  299,  300,  301,  302,
  287,   -1,   -1,  290,  291,  292,  293,  294,  295,  296,
  297,  298,  299,  300,  301,  302,  290,  291,  292,  293,
  294,  295,  296,  297,  298,  299,  300,  301,  302,
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
"PROGRAM_STATEMENT : PRINT LB $$4 TO_WRITE RB SC",
"$$5 :",
"PROGRAM_STATEMENT : VAR_DECL VAR_LIST COLON ARRAY $$5 OF DATA_TYPE SC",
"PROGRAM_STATEMENT : IF_BLOCK ENDIF",
"PROGRAM_STATEMENT : IF_BLOCK ELSEIF_BLOCKS ELSE_BLOCK ENDIF",
"$$6 :",
"$$7 :",
"PROGRAM_STATEMENT : WHILE LB $$6 A_EXPN RB $$7 DO PROGRAM_STATEMENTS ENDWHILE",
"$$8 :",
"$$9 :",
"PROGRAM_STATEMENT : RERUN $$8 PROGRAM_STATEMENTS UNTIL LB $$9 A_EXPN RB",
"$$10 :",
"$$11 :",
"$$12 :",
"$$13 :",
"$$14 :",
"$$15 :",
"$$16 :",
"PROGRAM_STATEMENT : FOR LB $$10 VAR $$11 ARROW $$12 TERMINAL $$13 TO $$14 A_EXPN $$15 RB DO $$16 PROGRAM_STATEMENTS ENDFOR",
"PROGRAM_STATEMENT : VAR COLON",
"PROGRAM_STATEMENT : COMMENT",
"$$17 :",
"$$18 :",
"IF_BLOCK : IF LB $$17 A_EXPN RB $$18 PROGRAM_STATEMENTS",
"ELSEIF_BLOCKS : ELSEIF_BLOCKS ELSEIF_BLOCK",
"ELSEIF_BLOCKS :",
"$$19 :",
"$$20 :",
"ELSEIF_BLOCK : ELSEIF $$19 A_EXPN RB $$20 PROGRAM_STATEMENT",
"$$21 :",
"ELSE_BLOCK : ELSE $$21 PROGRAM_STATEMENTS",
"$$22 :",
"TO_READ : VAR $$22 COMA TO_READ",
"TO_READ : VAR",
"$$23 :",
"TO_WRITE : TEXT $$23 COMA TO_WRITE",
"$$24 :",
"TO_WRITE : VAR $$24 TO_WRITE",
"TO_WRITE : TEXT",
"TO_WRITE : VAR",
"VAR_LIST : VAR COMA VAR_LIST",
"VAR_LIST : VAR",
"DATA_TYPE : INT",
"DATA_TYPE : CHAR",
"DATA_TYPE : FLOAT",
"DATA_TYPE : DOUBLE",
"$$25 :",
"A_EXPN : A_EXPN PLUS $$25 A_EXPN",
"$$26 :",
"A_EXPN : A_EXPN MINUS $$26 A_EXPN",
"$$27 :",
"A_EXPN : A_EXPN MUL $$27 A_EXPN",
"$$28 :",
"A_EXPN : A_EXPN DIV $$28 A_EXPN",
"$$29 :",
"A_EXPN : A_EXPN MOD $$29 A_EXPN",
"$$30 :",
"A_EXPN : NOT $$30 A_EXPN",
"$$31 :",
"A_EXPN : A_EXPN LAND $$31 A_EXPN",
"$$32 :",
"A_EXPN : A_EXPN LOR $$32 A_EXPN",
"$$33 :",
"A_EXPN : A_EXPN LEQ $$33 A_EXPN",
"$$34 :",
"A_EXPN : A_EXPN GEQ $$34 A_EXPN",
"$$35 :",
"A_EXPN : A_EXPN GT $$35 A_EXPN",
"$$36 :",
"A_EXPN : A_EXPN LT $$36 A_EXPN",
"$$37 :",
"A_EXPN : A_EXPN DEQ $$37 A_EXPN",
"$$38 :",
"A_EXPN : A_EXPN NEQ $$38 A_EXPN",
"A_EXPN : TERMINAL",
"TERMINAL : VAR",
"TERMINAL : NUMBER",

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
#line 276 "yacc_file.y"


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
#line 480 "y.tab.c"

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
#line 49 "yacc_file.y"
	{ printf("#include<stdio.h>\nint main()\n{\n");  }
break;
case 2:
#line 50 "yacc_file.y"
	{ printf("\n}"); }
break;
case 5:
#line 54 "yacc_file.y"
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
#line 67 "yacc_file.y"
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
#line 91 "yacc_file.y"
	{ printf("="); }
break;
case 8:
#line 91 "yacc_file.y"
	{ printf(";\n"); }
break;
case 9:
#line 93 "yacc_file.y"
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
#line 120 "yacc_file.y"
	{ printf("printf(\""); }
break;
case 11:
#line 120 "yacc_file.y"
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
case 12:
#line 130 "yacc_file.y"
	{
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
break;
case 13:
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
								{ printf("[%d]", array_dims[i]); }
								printf(";\n");
							}
break;
case 16:
#line 159 "yacc_file.y"
	{ printf("while("); }
break;
case 17:
#line 159 "yacc_file.y"
	{ printf("){\n"); }
break;
case 18:
#line 159 "yacc_file.y"
	{ printf("}\n"); }
break;
case 19:
#line 160 "yacc_file.y"
	{ printf("do{\n");  }
break;
case 20:
#line 160 "yacc_file.y"
	{ printf("} while("); }
break;
case 21:
#line 160 "yacc_file.y"
	{ printf(");\n"); }
break;
case 22:
#line 161 "yacc_file.y"
	{ printf("for("); }
break;
case 23:
#line 161 "yacc_file.y"
	{ strcpy(loop_var, yylval.var_name); printf(loop_var); }
break;
case 24:
#line 162 "yacc_file.y"
	{ printf("="); }
break;
case 25:
#line 163 "yacc_file.y"
	{ printf("; %s", loop_var); }
break;
case 26:
#line 163 "yacc_file.y"
	{ printf("<="); }
break;
case 27:
#line 164 "yacc_file.y"
	{ printf("; %s++", loop_var); }
break;
case 28:
#line 165 "yacc_file.y"
	{ printf("){\n");   }
break;
case 29:
#line 166 "yacc_file.y"
	{  printf("}\n");}
break;
case 30:
#line 167 "yacc_file.y"
	{ printf("%s:\n", yylval.var_name); }
break;
case 31:
#line 168 "yacc_file.y"
	{ printf("/%s/\n", yylval.var_name); }
break;
case 32:
#line 170 "yacc_file.y"
	{   printf("if("); }
break;
case 33:
#line 170 "yacc_file.y"
	{ printf("){\n");   }
break;
case 34:
#line 170 "yacc_file.y"
	{   printf("}\n"); }
break;
case 37:
#line 173 "yacc_file.y"
	{ printf("else if("); }
break;
case 38:
#line 173 "yacc_file.y"
	{ printf("){\n"); }
break;
case 39:
#line 173 "yacc_file.y"
	{ printf("\n}\n"); }
break;
case 40:
#line 175 "yacc_file.y"
	{ printf("else{\n"); }
break;
case 41:
#line 175 "yacc_file.y"
	{ printf("\n}\n"); }
break;
case 42:
#line 177 "yacc_file.y"
	{ strcpy(var_list[idx], yylval.var_name); idx++; }
break;
case 44:
#line 178 "yacc_file.y"
	{ strcpy(var_list[idx], yylval.var_name); idx++; }
break;
case 45:
#line 180 "yacc_file.y"
	{ printf("%s", yylval.text); }
break;
case 47:
#line 181 "yacc_file.y"
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
case 49:
#line 200 "yacc_file.y"
	{ printf("%s", yylval.text); }
break;
case 50:
#line 201 "yacc_file.y"
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
case 51:
#line 220 "yacc_file.y"
	{ strcpy(var_list[idx], yystack.l_mark[-2].var_name); idx++; insert_to_table(yystack.l_mark[-2].var_name, current_data_type); }
break;
case 52:
#line 221 "yacc_file.y"
	{ strcpy(var_list[idx], yystack.l_mark[0].var_name); idx++; insert_to_table(yystack.l_mark[0].var_name, current_data_type); }
break;
case 53:
#line 223 "yacc_file.y"
	{
     						yyval.data_type=yystack.l_mark[0].data_type;
     						current_data_type=yystack.l_mark[0].data_type;
     					}
break;
case 54:
#line 227 "yacc_file.y"
	{
     						yyval.data_type=yystack.l_mark[0].data_type;
     						current_data_type=yystack.l_mark[0].data_type;
     					}
break;
case 55:
#line 231 "yacc_file.y"
	{
     						yyval.data_type=yystack.l_mark[0].data_type;
     						current_data_type=yystack.l_mark[0].data_type;
     					}
break;
case 56:
#line 235 "yacc_file.y"
	{
     						yyval.data_type=yystack.l_mark[0].data_type;
     						current_data_type=yystack.l_mark[0].data_type;
     					}
break;
case 57:
#line 240 "yacc_file.y"
	{printf("+");}
break;
case 59:
#line 241 "yacc_file.y"
	{printf("-");}
break;
case 61:
#line 242 "yacc_file.y"
	{printf("*");}
break;
case 63:
#line 243 "yacc_file.y"
	{printf("/");}
break;
case 65:
#line 244 "yacc_file.y"
	{printf("%%");}
break;
case 67:
#line 245 "yacc_file.y"
	{printf("!");}
break;
case 69:
#line 246 "yacc_file.y"
	{printf("&&");}
break;
case 71:
#line 247 "yacc_file.y"
	{printf("||");}
break;
case 73:
#line 248 "yacc_file.y"
	{printf("<=");}
break;
case 75:
#line 249 "yacc_file.y"
	{printf(">=");}
break;
case 77:
#line 250 "yacc_file.y"
	{printf(">");}
break;
case 79:
#line 251 "yacc_file.y"
	{printf("<");}
break;
case 81:
#line 252 "yacc_file.y"
	{printf("==");}
break;
case 83:
#line 253 "yacc_file.y"
	{printf("!=");}
break;
case 86:
#line 256 "yacc_file.y"
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
case 87:
#line 274 "yacc_file.y"
	{ printf("%d", yylval.value); }
break;
#line 1093 "y.tab.c"
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
