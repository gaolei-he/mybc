mybc(1)                                                                                General Commands Manual                                                                                mybc(1)

NAME
        mybc  -  A limited precision calculator

SYNTAX
        mybc  [options]
DESCRIPTION
        mybc is a calculator that supports arbitrary precision integer with interactive execution of statements.  mybc processes data line by line.

    OPTIONS
        -v
            Print the version message

    NUMBERS
        The most basic element in bc is the number. Numbers are arbitrary precision integers.  All numbers are repesented internally in decimal and all computation is done in decimal.

    VARIABLES
        Numbers can be stored in variables.  Every variables is named. Names are consist of lowercase letters.  For example:  ac,  lld.
    
        There are two special variables, ibase, obase. ibase defines the conversion base for input numbers while obase defines for output.
        The legal value of ibase are 2 through 16 while obase are 2 through 999.
    
    EXPRESSIONS
        Experssions are consist of operators, variables and numbers and there are six operators: +, -, *, /, %, ^

        In the following description of legal expressions, "expr" refers to a complete epxression and "var" refers to an variables.
        
        - expr The result is the negation of the epxression.

        expr + expr
            The result of the experssion is the sum of the two expressions.

        expr - expr
            The result of the expression is the difference of the two expressions.
        
        expr * expr
            The result of the expression is the product of the two expressions.

        expr / expr
            The result of the expression is the quotient of the two expressions.  Attention, there are no fractional part for the result. For experssion: 7/3=2.
        
        expr % expr
            The result of the expression is the "remainder". It is the same as % in the C programming language.
        
        expr ^ expr
            The result of the expression is the value of the first raised to the second.
        
        var = expr
            The variable is assigned the value of the expression.

AUTOOR
    Gaolei He, Wenkai Li, Wenjie Zhang
    ahegaolei@163.com
    2022.07.17

ACKNOWLEDGEMENTS
    The authors would like to say that the program is just a poor imitation of Linux BC and it will never be used for other purpose.