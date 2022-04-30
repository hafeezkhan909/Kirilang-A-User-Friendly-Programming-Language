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
extern YYSTYPE yylval;
