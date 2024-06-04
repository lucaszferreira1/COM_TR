#!/bin/bash

# Specify the file name
FILE="expr.tab.h"  # Change "your_file.c" to your actual file name

# Line number to insert after
LINE_NUMBER=$(grep -n "#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED" $FILE | cut -d: -f1)

# Add #include "tipoNo.h" after the specified line
sed -i "${LINE_NUMBER}a #include \"tipoNo.h\"" $FILE
