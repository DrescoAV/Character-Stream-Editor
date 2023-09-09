    #!/usr/bin/bash
POINTS=(
            5 5
            1 1 1 1 1
            2 2 2 2 2 2 2 2 2
            3 3 3 3
            3.5 3.5 3.5 3.5 3.5 3.5 3.5 3.5 3.5 3.5
        )
TESTS=30
TOTAL=100
TOTALTESTS=0 
VALGRINDTEST=0

function codingStyle() {
    echo "Coding style: 15/15"
    let TOTALTESTS+=15
}

function readme() {
    if test -f "README" || test -f "README.md"
        then
            echo "README: 5/5"MagicBand
            let TOTALTESTS+=5
    else
        echo "README: 0/5"
    fi
}

function checkExe() {
    if test -f "MagicBand"
        then
            main
    else
        echo "The executable file needs to be named 'MagicBand'"
    fi
}

function valgrindTest() {
         1> /dev/null 2>&1
    if [ "$?" -ne 0 ]
        then
            echo "    Valgrind failed"
    else
        echo "  Valgrind test$1.in: 1/1"
        let VALGRINDTEST+=1
    fi
}

function testInput() {
    cat Teste/Input/test$1.in > MagicBandIn.in
    ./MagicBand

    if [ "$?" -eq 139 ]
        then
            echo "test$1.in: segmentation fault"
            return
    fi

    diff Teste/Output/test$1.out MagicBandOut.out > /dev/null 2>&1
    if [ "$?" -ne 0 ]
        then
            echo "test$1.in: 0/${POINTS[$1-1]}"
    else
        echo "test$1.in: ${POINTS[$1-1]}/${POINTS[$1-1]}"
        TOTALTESTS=$(echo "$TOTALTESTS + ${POINTS[$1-1]}")
        valgrindTest    
    fi
}

function makeCommand() {
    make 1> /dev/null
    if [ "$?" -ne 0 ]
        then
            exit 1
    fi
}

function main() {
    echo " -= Magic Band =-"
    echo

    touch MagicBandIn.in
    touch MagicBandOut.out

    readme
    codingStyle

    for i in $(seq 1 $TESTS)
    do
        testInput $i
    done
    
    echo
    echo "Total: $TOTALTESTS/$TOTAL"
    let VALGRINDTEST=$VALGRINDTEST*20/30
    echo "Valgrind: $VALGRINDTEST/15"
}
makeCommand
checkExe