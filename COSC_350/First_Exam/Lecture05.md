## CoSc 350 - Functions and Other Commands


## Main Points

    * Functions
      - Functions with local variable
      - Functions with return value
      - Bash Recursive Function

    * Other Commands
      - break command
      - continue command
      - eval
      - exit
      - export 
      - expr
      - printf
      - set
      - shift

## Functions

    * You can define functions in a shell script

    SYNTAX:

    function_name ()
    {
        statement
        statement
        ...
    }

    * Function prototypes cannot  placed for calling a function before function definition
    * A funtion must be defined before it can be used

    * When a function is called the positional parameter the script $* (stop itallics*) , $@, $#, $0, $1      , $2, .. and so on      are replaced by the parameters to the function.
    * When the function finnishes, the positional parameters are restored to their previous values

## Functoins With Local Variables

    * SYNTAX:

    #!/bin/sh
    # function.sh: na example for a function definition

    function_hello()
    {
        local yourname
        echo -n "What is your name?"
        read yourname
        echo " Hello $yourname "
        echo "Parameter variables for the function_hello are $@"
    }

    echo "Parameters variables for this shell script are $@"
    function_hello you your you yours
    function_hello I mine me mine
    echo "your name is $yourname"
    echo "Parameters variables for this shell script are $@"
    exit 0

    * We can declare local variables iwthin a function by using **local** keyword which is only in the
      function scope
    * If the local variable has the same nmae as a global varibale, it takes scope over that variable
      within the function
    
    * EXAMPLE:

    #!/bin/sh
    # local.sh for testing local variable
    # local variable is in the function scope
   
    yourlocation()

    {
    local mylocation
    echo -n "where are you now?"
    read mylocation
    echo "He is now in $mylocation "
    }

    mylocation = "Salisbury"
    yourlocation
    echo "I am still in $mylocation"
    exit 0

## Function with Return Value

    * In bash, we cna define a function wit ha return value
    * A function can **return 0 (true) or 1(false)** as a result.

## Recursive Function

    * Bash permits recursion
      - It's slow
      - Runninga script with recursion could lock up system

## Break Command

    * Exit from a for, while or until loop

        SYNTAX:
            break[n]
   
    * If n is supplied, the nth enclosing loop is exited
    * n must be n >= 1

    for myloop in 1 2 3 4 5 do
    echo "$myloop"
    if [ "$myloop" -eq 3 ]
then
    break
    fi
done

## Continue Command 

    * Resume the next iteration of an enclosing for, while, until, or select loop.

        SYNTAX:
            continue[n]

    * If n is supplied, the execution of the nth enclosing loop is resumed
    * n must be n >= 1

## Other Commands

# export

    * Set an environment variable
    * Mark each name to be passed to child processes in the environment

# expr

    * Evaluate expressions, evaluates an expression (arithmetic, logical) and writes the result on
      standard output

        SYNTAX
            `expr expression...`

# printf

    SYNTAX:
        printf"Format strings", parameter list

    * Format string : sequence of conversion specifier (%d, %c, %s)
    * Parameter list and conversion specifier must be matched.

    * Ex
      - printf "%d, %s, %c\\a" 2 "Hi" 'a'

    * Escape Sequence in printf
      - \b = backspace
      - \f = form feed
      - \n = newline
      - \r = carriage return
      - \t = tap
      - \v = vertical tap

# set

    * The set command sets the parameter variables for the shell script
    * Position parameter can change inside a script
    * We can use the result of a command as an input to other commands

# shift

    * The shift command shift all positional parameter variable down by one. $4 become $3, $3 become $2
    * The previous vlaue of $1 is deiscarded 
      - $0 (name of script) remains
