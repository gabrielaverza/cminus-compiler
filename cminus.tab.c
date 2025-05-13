/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 13 "cminus.y"

#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h" 

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void); /* add to ensure no conflict with lex */


#line 87 "cminus.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "cminus.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ELSE = 3,                       /* ELSE  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_PLUS = 9,                       /* PLUS  */
  YYSYMBOL_MINUS = 10,                     /* MINUS  */
  YYSYMBOL_TIMES = 11,                     /* TIMES  */
  YYSYMBOL_OVER = 12,                      /* OVER  */
  YYSYMBOL_LT = 13,                        /* LT  */
  YYSYMBOL_LTE = 14,                       /* LTE  */
  YYSYMBOL_GT = 15,                        /* GT  */
  YYSYMBOL_GTE = 16,                       /* GTE  */
  YYSYMBOL_EQ = 17,                        /* EQ  */
  YYSYMBOL_NEQ = 18,                       /* NEQ  */
  YYSYMBOL_ASSIGN = 19,                    /* ASSIGN  */
  YYSYMBOL_SEMI = 20,                      /* SEMI  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_LPAREN = 22,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 23,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 24,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 25,                  /* RBRACKET  */
  YYSYMBOL_LBRACES = 26,                   /* LBRACES  */
  YYSYMBOL_RBRACES = 27,                   /* RBRACES  */
  YYSYMBOL_ID = 28,                        /* ID  */
  YYSYMBOL_NUM = 29,                       /* NUM  */
  YYSYMBOL_ENDFILE = 30,                   /* ENDFILE  */
  YYSYMBOL_ERROR = 31,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_program = 33,                   /* program  */
  YYSYMBOL_declaration_list = 34,          /* declaration_list  */
  YYSYMBOL_declaration = 35,               /* declaration  */
  YYSYMBOL_variable_declaration = 36,      /* variable_declaration  */
  YYSYMBOL_specifier_type = 37,            /* specifier_type  */
  YYSYMBOL_function_declaration = 38,      /* function_declaration  */
  YYSYMBOL_parameters = 39,                /* parameters  */
  YYSYMBOL_parameter_list = 40,            /* parameter_list  */
  YYSYMBOL_parameter = 41,                 /* parameter  */
  YYSYMBOL_compound_declaration = 42,      /* compound_declaration  */
  YYSYMBOL_local_declarations = 43,        /* local_declarations  */
  YYSYMBOL_statement_list = 44,            /* statement_list  */
  YYSYMBOL_statement = 45,                 /* statement  */
  YYSYMBOL_expression_decl = 46,           /* expression_decl  */
  YYSYMBOL_if_decl = 47,                   /* if_decl  */
  YYSYMBOL_loop_decl = 48,                 /* loop_decl  */
  YYSYMBOL_return_decl = 49,               /* return_decl  */
  YYSYMBOL_expression = 50,                /* expression  */
  YYSYMBOL_var = 51,                       /* var  */
  YYSYMBOL_simple_expression = 52,         /* simple_expression  */
  YYSYMBOL_relational = 53,                /* relational  */
  YYSYMBOL_sum_expression = 54,            /* sum_expression  */
  YYSYMBOL_sum = 55,                       /* sum  */
  YYSYMBOL_term = 56,                      /* term  */
  YYSYMBOL_mult = 57,                      /* mult  */
  YYSYMBOL_factor = 58,                    /* factor  */
  YYSYMBOL_activation = 59,                /* activation  */
  YYSYMBOL_argument_list = 60,             /* argument_list  */
  YYSYMBOL_identifier = 61,                /* identifier  */
  YYSYMBOL_number = 62                     /* number  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   140

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  110

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    42,    42,    45,    57,    60,    62,    65,    73,    83,
      90,    97,   108,   112,   116,   129,   134,   143,   153,   166,
     170,   174,   178,   191,   196,   209,   214,   218,   222,   226,
     230,   235,   239,   243,   249,   258,   265,   269,   275,   281,
     286,   290,   297,   303,   308,   313,   318,   323,   328,   333,
     339,   345,   350,   355,   361,   367,   372,   377,   383,   387,
     391,   395,   400,   407,   414,   427,   432,   438
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ELSE", "IF", "INT",
  "RETURN", "VOID", "WHILE", "PLUS", "MINUS", "TIMES", "OVER", "LT", "LTE",
  "GT", "GTE", "EQ", "NEQ", "ASSIGN", "SEMI", "COMMA", "LPAREN", "RPAREN",
  "LBRACKET", "RBRACKET", "LBRACES", "RBRACES", "ID", "NUM", "ENDFILE",
  "ERROR", "$accept", "program", "declaration_list", "declaration",
  "variable_declaration", "specifier_type", "function_declaration",
  "parameters", "parameter_list", "parameter", "compound_declaration",
  "local_declarations", "statement_list", "statement", "expression_decl",
  "if_decl", "loop_decl", "return_decl", "expression", "var",
  "simple_expression", "relational", "sum_expression", "sum", "term",
  "mult", "factor", "activation", "argument_list", "identifier", "number", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-42)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       1,   -42,   -42,    47,     1,   -42,   -42,   -19,   -42,   -42,
     -42,   -42,     9,   -42,    23,    36,    50,   -19,    56,    60,
     -42,   -42,    13,    59,    61,     1,    65,    75,    15,   -42,
     -42,   -42,   -42,    69,   -15,    86,   -42,   -12,   -42,   -42,
     -19,   -42,    49,    66,   -42,   -42,   -42,   -42,   -42,    89,
      91,   -42,   114,    78,   -42,   -42,    39,   -42,   -12,   -42,
      92,   -12,    88,    38,   -42,   -42,    76,   -42,   -42,   -42,
     -12,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -12,
     -12,   -42,   -42,   -12,    17,   -12,    94,   -42,    95,   -42,
     -42,   -42,   -42,    97,    78,   -42,   -42,   -42,    43,   100,
      93,    93,   -12,   -42,   -42,   111,   -42,   -42,    93,   -42
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,    66,     0,     7,     0,     0,    10,     0,     0,    12,
      15,    67,     0,    16,     0,     0,     0,     0,     0,    11,
      14,     8,    17,     0,     0,     0,    32,     0,    21,    23,
       0,    27,     0,     0,    25,    26,    28,    29,    30,     0,
      59,    39,    43,    51,    55,    60,    40,    61,     0,    36,
       0,     0,     0,     0,    19,    22,     0,    20,    24,    31,
       0,    52,    53,    46,    47,    48,    49,    44,    45,     0,
       0,    56,    57,     0,     0,     0,     0,    37,     0,    58,
      18,    38,    59,    42,    50,    54,    63,    65,     0,     0,
       0,     0,     0,    62,    41,    33,    35,    64,     0,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -42,   -42,   -42,   112,   -16,   -10,   -42,   -42,   -42,   101,
      96,   -42,    98,   -41,   -42,   -42,   -42,   -42,   -34,   -31,
     -42,   -42,    54,   -42,    55,   -42,    51,   -42,   -42,    -6,
     121
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    18,    19,    20,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    79,    52,    80,    53,    83,    54,    55,    98,    56,
      57
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      60,    12,    68,    62,    17,    59,     1,    37,     2,    11,
      37,    23,    39,    11,    21,    17,    11,    21,    40,    33,
       1,    34,     2,    35,    86,    68,    65,    88,     1,    13,
      16,    14,    40,    15,    63,    36,    91,    37,    26,    37,
      96,    28,    38,    11,    21,    11,    21,     9,    92,    92,
      97,    99,    92,    33,     1,    34,     2,    35,    13,   105,
     106,    84,    15,    85,   102,    21,   103,   109,   107,    36,
      33,    37,    34,   -13,    35,    28,    64,    11,    21,    24,
      33,    25,    34,    27,    35,    31,    36,    28,    37,    81,
      82,    58,    28,    67,    11,    21,    36,    33,    37,    34,
      32,    35,    28,    90,    11,    21,    71,    72,    61,    69,
      70,    89,    87,    36,   108,    37,    10,   100,   101,    28,
      29,    11,    21,    71,    72,   104,    30,    73,    74,    75,
      76,    77,    78,    93,    95,    94,    22,     0,     0,     0,
      66
};

static const yytype_int8 yycheck[] =
{
      34,     7,    43,    37,    14,    20,     5,    22,     7,    28,
      22,    17,    28,    28,    29,    25,    28,    29,    28,     4,
       5,     6,     7,     8,    58,    66,    42,    61,     5,    20,
       7,    22,    42,    24,    40,    20,    70,    22,    25,    22,
      23,    26,    27,    28,    29,    28,    29,     0,    79,    80,
      84,    85,    83,     4,     5,     6,     7,     8,    20,   100,
     101,    22,    24,    24,    21,    29,    23,   108,   102,    20,
       4,    22,     6,    23,     8,    26,    27,    28,    29,    23,
       4,    21,     6,    24,     8,    20,    20,    26,    22,    11,
      12,    22,    26,    27,    28,    29,    20,     4,    22,     6,
      25,     8,    26,    27,    28,    29,     9,    10,    22,    20,
      19,    23,    20,    20,     3,    22,     4,    23,    23,    26,
      24,    28,    29,     9,    10,    25,    25,    13,    14,    15,
      16,    17,    18,    79,    83,    80,    15,    -1,    -1,    -1,
      42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,    33,    34,    35,    36,    37,    38,     0,
      35,    28,    61,    20,    22,    24,     7,    37,    39,    40,
      41,    29,    62,    61,    23,    21,    25,    24,    26,    42,
      41,    20,    25,     4,     6,     8,    20,    22,    27,    36,
      37,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    54,    56,    58,    59,    61,    62,    22,    20,
      50,    22,    50,    61,    27,    36,    44,    27,    45,    20,
      19,     9,    10,    13,    14,    15,    16,    17,    18,    53,
      55,    11,    12,    57,    22,    24,    50,    20,    50,    23,
      27,    50,    51,    54,    56,    58,    23,    50,    60,    50,
      23,    23,    21,    23,    25,    45,    45,    50,     3,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    36,    37,
      37,    38,    39,    39,    40,    40,    41,    41,    42,    42,
      42,    42,    43,    43,    44,    44,    45,    45,    45,    45,
      45,    46,    46,    47,    47,    48,    49,    49,    50,    50,
      51,    51,    52,    52,    53,    53,    53,    53,    53,    53,
      54,    54,    55,    55,    56,    56,    57,    57,    58,    58,
      58,    58,    59,    59,    60,    60,    61,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     4,     3,
       3,     2,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     5,     7,     5,     2,     3,     3,     1,
       1,     4,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     4,     3,     3,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declaration_list  */
#line 43 "cminus.y"
                                     { savedTree = yyvsp[0]; }
#line 1216 "cminus.tab.c"
    break;

  case 3: /* declaration_list: declaration_list declaration  */
#line 46 "cminus.y"
                            {
             	               YYSTYPE t = yyvsp[-1];
             	               if(t != NULL)
				     	{ 
                                   while(t->sibling != NULL)
             	                       t = t->sibling;
             	                   t->sibling = yyvsp[0];
             	                   yyval = yyvsp[-1];
                              }
             	               else yyval = yyvsp[0];
             	            }
#line 1232 "cminus.tab.c"
    break;

  case 4: /* declaration_list: declaration  */
#line 58 "cminus.y"
                                     { yyval = yyvsp[0]; }
#line 1238 "cminus.tab.c"
    break;

  case 5: /* declaration: variable_declaration  */
#line 61 "cminus.y"
                                    { yyval = yyvsp[0]; }
#line 1244 "cminus.tab.c"
    break;

  case 6: /* declaration: function_declaration  */
#line 63 "cminus.y"
                                    { yyval = yyvsp[0]; }
#line 1250 "cminus.tab.c"
    break;

  case 7: /* variable_declaration: specifier_type identifier SEMI  */
#line 66 "cminus.y"
                                      {
                              yyval = yyvsp[-2];
                              yyval->child[0] = yyvsp[-1];
                              yyvsp[-1]->nodekind = StmtK;
                              yyvsp[-1]->kind.stmt = VariableK;
                              yyvsp[-1]->specifier_type = yyvsp[-2]->specifier_type;
			              }
#line 1262 "cminus.tab.c"
    break;

  case 8: /* variable_declaration: specifier_type identifier LBRACKET number RBRACKET SEMI  */
#line 74 "cminus.y"
                                      {
                              yyval = yyvsp[-5];
                              yyval->child[0] = yyvsp[-4];
                              yyvsp[-4]->nodekind = StmtK;
                              yyvsp[-4]->kind.stmt = VectorK;
                              yyvsp[-4]->attr.len = yyvsp[-2]->attr.val;
                              yyvsp[-4]->specifier_type = yyvsp[-5]->specifier_type;
                             }
#line 1275 "cminus.tab.c"
    break;

  case 9: /* specifier_type: INT  */
#line 84 "cminus.y"
                                  {
                            yyval = newExpNode(TypeK);
                            yyval->specifier_type = IntK;
                            yyval->attr.name = "Inteiro";
                         }
#line 1285 "cminus.tab.c"
    break;

  case 10: /* specifier_type: VOID  */
#line 91 "cminus.y"
                             {
                              yyval = newExpNode(TypeK);
                              yyval->specifier_type = VoidK;
                              yyval->attr.name = "Void";
                            }
#line 1295 "cminus.tab.c"
    break;

  case 11: /* function_declaration: specifier_type identifier LPAREN parameters RPAREN compound_declaration  */
#line 98 "cminus.y"
                        {
                            yyval = yyvsp[-5];
                            yyval->child[0] = yyvsp[-4];
                            yyvsp[-4]->child[0] = yyvsp[-2];
                            yyvsp[-4]->child[1] = yyvsp[0];
                            yyvsp[-4]->nodekind = StmtK;
                            yyvsp[-4]->kind.stmt = FunctionK;
                            yyvsp[-4]->specifier_type = yyvsp[-5]->specifier_type;
                        }
#line 1309 "cminus.tab.c"
    break;

  case 12: /* parameters: parameter_list  */
#line 109 "cminus.y"
                       {
                           yyval = yyvsp[0];
                       }
#line 1317 "cminus.tab.c"
    break;

  case 13: /* parameters: VOID  */
#line 113 "cminus.y"
                       {
                       }
#line 1324 "cminus.tab.c"
    break;

  case 14: /* parameter_list: parameter_list COMMA parameter  */
#line 117 "cminus.y"
                           {
                            YYSTYPE t = yyvsp[-2];
                            if(t != NULL)
                           {
				          while(t->sibling != NULL)
                                  t = t->sibling;
				          t->sibling = yyvsp[0];
				          yyval = yyvsp[-2];
                           }
                            else
                              yyval = yyvsp[-2];
                         }
#line 1341 "cminus.tab.c"
    break;

  case 15: /* parameter_list: parameter  */
#line 130 "cminus.y"
                       {
                            yyval = yyvsp[0];
                       }
#line 1349 "cminus.tab.c"
    break;

  case 16: /* parameter: specifier_type identifier  */
#line 135 "cminus.y"
                       {
                           yyval = yyvsp[-1];
                           yyval->child[0] = yyvsp[0];
                           yyvsp[0]->nodekind = StmtK;
                           yyvsp[0]->kind.stmt = ParameterK;
                           yyvsp[0]->specifier_type = yyvsp[-1]->specifier_type;

                       }
#line 1362 "cminus.tab.c"
    break;

  case 17: /* parameter: specifier_type identifier LBRACKET RBRACKET  */
#line 144 "cminus.y"
                                {
                            yyval = yyvsp[-3];
                            yyval->child[0] = yyvsp[-2];
                            yyvsp[-2]->nodekind = StmtK;
                            yyvsp[-2]->kind.exp = VectK;
                            yyvsp[-2]->kind.stmt = ParameterK;
                            yyvsp[-2]->specifier_type = yyvsp[-3]->specifier_type;
                       }
#line 1375 "cminus.tab.c"
    break;

  case 18: /* compound_declaration: LBRACES local_declarations statement_list RBRACES  */
#line 154 "cminus.y"
                             {
                              YYSTYPE t = yyvsp[-2];
                              if(t != NULL)
                                {
                                 while(t->sibling != NULL)
                                    t = t->sibling;
                                  t->sibling = yyvsp[-1];
                                  yyval = yyvsp[-2];
                                }
                                 else
                                 yyval = yyvsp[-1];
                              }
#line 1392 "cminus.tab.c"
    break;

  case 19: /* compound_declaration: LBRACES local_declarations RBRACES  */
#line 167 "cminus.y"
                       {
                            yyval = yyvsp[-1];
                       }
#line 1400 "cminus.tab.c"
    break;

  case 20: /* compound_declaration: LBRACES statement_list RBRACES  */
#line 171 "cminus.y"
                       {
                            yyval = yyvsp[-1];
                       }
#line 1408 "cminus.tab.c"
    break;

  case 21: /* compound_declaration: LBRACES RBRACES  */
#line 175 "cminus.y"
                       {
                       }
#line 1415 "cminus.tab.c"
    break;

  case 22: /* local_declarations: local_declarations variable_declaration  */
#line 179 "cminus.y"
                       {
                            YYSTYPE t = yyvsp[-1];
                            if(t != NULL)
                            {
                              while(t->sibling != NULL)
                                   t = t->sibling;
                              t->sibling = yyvsp[0];
                              yyval = yyvsp[-1];
                            }
                            else
                               yyval = yyvsp[0];
                       }
#line 1432 "cminus.tab.c"
    break;

  case 23: /* local_declarations: variable_declaration  */
#line 192 "cminus.y"
                       {
                            yyval = yyvsp[0];
                       }
#line 1440 "cminus.tab.c"
    break;

  case 24: /* statement_list: statement_list statement  */
#line 197 "cminus.y"
                       {
                           YYSTYPE t = yyvsp[-1];
                           if(t != NULL)
                           {
                              while(t->sibling != NULL)
                                   t = t->sibling;
                              t->sibling = yyvsp[0];
                              yyval = yyvsp[-1];
                           }
                           else
                             yyval = yyvsp[0];
			}
#line 1457 "cminus.tab.c"
    break;

  case 25: /* statement_list: statement  */
#line 210 "cminus.y"
                       {
                           yyval = yyvsp[0];
                       }
#line 1465 "cminus.tab.c"
    break;

  case 26: /* statement: expression_decl  */
#line 215 "cminus.y"
                       {
                           yyval = yyvsp[0];
                       }
#line 1473 "cminus.tab.c"
    break;

  case 27: /* statement: compound_declaration  */
#line 219 "cminus.y"
                       {
                           yyval = yyvsp[0];
                       }
#line 1481 "cminus.tab.c"
    break;

  case 28: /* statement: if_decl  */
#line 223 "cminus.y"
                       {
                           yyval = yyvsp[0];
                       }
#line 1489 "cminus.tab.c"
    break;

  case 29: /* statement: loop_decl  */
#line 227 "cminus.y"
                       {
                           yyval = yyvsp[0];
                       }
#line 1497 "cminus.tab.c"
    break;

  case 30: /* statement: return_decl  */
#line 231 "cminus.y"
                       {
                           yyval = yyvsp[0];
                       }
#line 1505 "cminus.tab.c"
    break;

  case 31: /* expression_decl: expression SEMI  */
#line 236 "cminus.y"
                       {
                           yyval = yyvsp[-1];
                       }
#line 1513 "cminus.tab.c"
    break;

  case 32: /* expression_decl: SEMI  */
#line 240 "cminus.y"
                       {
                       }
#line 1520 "cminus.tab.c"
    break;

  case 33: /* if_decl: IF LPAREN expression RPAREN statement  */
#line 244 "cminus.y"
                       {
                             yyval = newStmtNode(IfK);
                             yyval->child[0] = yyvsp[-2];
                             yyval->child[1] = yyvsp[0];
                       }
#line 1530 "cminus.tab.c"
    break;

  case 34: /* if_decl: IF LPAREN expression RPAREN statement ELSE statement  */
#line 250 "cminus.y"
                       {
               
                             yyval = newStmtNode(IfK);
                             yyval->child[0] = yyvsp[-4];
                             yyval->child[1] = yyvsp[-2];
                             yyval->child[2] = yyvsp[0];
                       }
#line 1542 "cminus.tab.c"
    break;

  case 35: /* loop_decl: WHILE LPAREN expression RPAREN statement  */
#line 259 "cminus.y"
                       {
                             yyval = newStmtNode(WhileK);
                             yyval->child[0] = yyvsp[-2];
                             yyval->child[1] = yyvsp[0];
                       }
#line 1552 "cminus.tab.c"
    break;

  case 36: /* return_decl: RETURN SEMI  */
#line 266 "cminus.y"
                       {
                            yyval = newStmtNode(ReturnK);
                       }
#line 1560 "cminus.tab.c"
    break;

  case 37: /* return_decl: RETURN expression SEMI  */
#line 270 "cminus.y"
                       {
                            yyval = newStmtNode(ReturnK);
                            yyval->child[0] = yyvsp[-1];
                       }
#line 1569 "cminus.tab.c"
    break;

  case 38: /* expression: var ASSIGN expression  */
#line 276 "cminus.y"
                       {
                            yyval = newStmtNode(AssignK);
                            yyval->child[0] = yyvsp[-2];
                            yyval->child[1] = yyvsp[0];
                       }
#line 1579 "cminus.tab.c"
    break;

  case 39: /* expression: simple_expression  */
#line 282 "cminus.y"
                       {
                            yyval = yyvsp[0];
                       }
#line 1587 "cminus.tab.c"
    break;

  case 40: /* var: identifier  */
#line 287 "cminus.y"
                       {
                            yyval = yyvsp[0];
                       }
#line 1595 "cminus.tab.c"
    break;

  case 41: /* var: identifier LBRACKET expression RBRACKET  */
#line 291 "cminus.y"
                       {
                            yyval = yyvsp[-3];
                            yyval->child[0] = yyvsp[-1];
                            yyval->kind.exp = VectK;
                       }
#line 1605 "cminus.tab.c"
    break;

  case 42: /* simple_expression: sum_expression relational sum_expression  */
#line 298 "cminus.y"
                       {
                            yyval = yyvsp[-1];
                            yyval->child[0] = yyvsp[-2];
                            yyval->child[1] = yyvsp[0];
                       }
#line 1615 "cminus.tab.c"
    break;

  case 43: /* simple_expression: sum_expression  */
#line 304 "cminus.y"
                       {
                            yyval = yyvsp[0];
                       }
#line 1623 "cminus.tab.c"
    break;

  case 44: /* relational: EQ  */
#line 309 "cminus.y"
                       {
                            yyval = newExpNode(OpK);
                            yyval->attr.op = EQ;                            
                       }
#line 1632 "cminus.tab.c"
    break;

  case 45: /* relational: NEQ  */
#line 314 "cminus.y"
                       {
                            yyval = newExpNode(OpK);
                            yyval->attr.op = NEQ;                            
                       }
#line 1641 "cminus.tab.c"
    break;

  case 46: /* relational: LT  */
#line 319 "cminus.y"
                       {
                            yyval = newExpNode(OpK);
                            yyval->attr.op = LT;                            
                       }
#line 1650 "cminus.tab.c"
    break;

  case 47: /* relational: LTE  */
#line 324 "cminus.y"
                       {
                            yyval = newExpNode(OpK);
                            yyval->attr.op = LTE;                            
                       }
#line 1659 "cminus.tab.c"
    break;

  case 48: /* relational: GT  */
#line 329 "cminus.y"
                       {
                            yyval = newExpNode(OpK);
                            yyval->attr.op = GT;                            
                       }
#line 1668 "cminus.tab.c"
    break;

  case 49: /* relational: GTE  */
#line 334 "cminus.y"
                       {
                            yyval = newExpNode(OpK);
                            yyval->attr.op = GTE;                            
                       }
#line 1677 "cminus.tab.c"
    break;

  case 50: /* sum_expression: sum_expression sum term  */
#line 340 "cminus.y"
                       {
                            yyval = yyvsp[-1];
                            yyval->child[0] = yyvsp[-2];
                            yyval->child[1] = yyvsp[0];
                       }
#line 1687 "cminus.tab.c"
    break;

  case 51: /* sum_expression: term  */
#line 346 "cminus.y"
                       {
                            yyval = yyvsp[0];
                       }
#line 1695 "cminus.tab.c"
    break;

  case 52: /* sum: PLUS  */
#line 351 "cminus.y"
                        {
                            yyval = newExpNode(OpK);
                            yyval->attr.op = PLUS;                            
			}
#line 1704 "cminus.tab.c"
    break;

  case 53: /* sum: MINUS  */
#line 356 "cminus.y"
                        {
                            yyval = newExpNode(OpK);
                            yyval->attr.op = MINUS;                            
			}
#line 1713 "cminus.tab.c"
    break;

  case 54: /* term: term mult factor  */
#line 362 "cminus.y"
                       {
                            yyval = yyvsp[-1];
                            yyval->child[0] = yyvsp[-2];
                            yyval->child[1] = yyvsp[0];
                       }
#line 1723 "cminus.tab.c"
    break;

  case 55: /* term: factor  */
#line 368 "cminus.y"
                       {
                            yyval = yyvsp[0];
                       }
#line 1731 "cminus.tab.c"
    break;

  case 56: /* mult: TIMES  */
#line 373 "cminus.y"
                       {
                            yyval = newExpNode(OpK);
                            yyval->attr.op = TIMES;                            
                       }
#line 1740 "cminus.tab.c"
    break;

  case 57: /* mult: OVER  */
#line 378 "cminus.y"
                       {
                            yyval = newExpNode(OpK);
                            yyval->attr.op = OVER;                            
                       }
#line 1749 "cminus.tab.c"
    break;

  case 58: /* factor: LPAREN expression RPAREN  */
#line 384 "cminus.y"
                       {
                            yyval = yyvsp[-1];
                       }
#line 1757 "cminus.tab.c"
    break;

  case 59: /* factor: var  */
#line 388 "cminus.y"
                       {
                            yyval = yyvsp[0];
                       }
#line 1765 "cminus.tab.c"
    break;

  case 60: /* factor: activation  */
#line 392 "cminus.y"
                       {
                            yyval = yyvsp[0];
                       }
#line 1773 "cminus.tab.c"
    break;

  case 61: /* factor: number  */
#line 396 "cminus.y"
                       {
                            yyval = yyvsp[0];
                       }
#line 1781 "cminus.tab.c"
    break;

  case 62: /* activation: identifier LPAREN argument_list RPAREN  */
#line 401 "cminus.y"
                       {
                            yyval = yyvsp[-3];
                            yyval->child[0] = yyvsp[-1];
                            yyval->nodekind = StmtK;
                            yyval->kind.stmt = CallK;
                       }
#line 1792 "cminus.tab.c"
    break;

  case 63: /* activation: identifier LPAREN RPAREN  */
#line 408 "cminus.y"
                        {
                            yyval = yyvsp[-2];
                            yyval->nodekind = StmtK;
                            yyval->kind.stmt = CallK;
                       }
#line 1802 "cminus.tab.c"
    break;

  case 64: /* argument_list: argument_list COMMA expression  */
#line 415 "cminus.y"
                       {
                            YYSTYPE t = yyvsp[-2];
                             if(t != NULL)
                             {
                                while(t->sibling != NULL)
                                   t = t->sibling;
                                 t->sibling = yyvsp[0];
                                 yyval = yyvsp[-2];
                             }
                             else
                                 yyval = yyvsp[0];
                       }
#line 1819 "cminus.tab.c"
    break;

  case 65: /* argument_list: expression  */
#line 428 "cminus.y"
                       {
                             yyval = yyvsp[0];
                       }
#line 1827 "cminus.tab.c"
    break;

  case 66: /* identifier: ID  */
#line 433 "cminus.y"
                       {
                             yyval = newExpNode(IdK);
                             yyval->attr.name = copyString(tokenString);
                       }
#line 1836 "cminus.tab.c"
    break;

  case 67: /* number: NUM  */
#line 439 "cminus.y"
                       {
                             yyval = newExpNode(ConstK);
                             yyval->attr.val = atoi(tokenString);
                       }
#line 1845 "cminus.tab.c"
    break;


#line 1849 "cminus.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 445 "cminus.y"


int yyerror(char* message){
     if(yychar != ENDFILE && !Error){
          fprintf(listing,"\nSINTATICAL ERROR: ");
          printToken(yychar,tokenString);
          fprintf(listing, "LINE: %d\n",lineno);
          Error = TRUE;
     }
     return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}
