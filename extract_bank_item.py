#!/bin/python3

import sys
import os
from pypdf import PdfReader

def check_args_valid() -> None:
    if len(sys.argv) != 2:
        print('this script shall take exactly one argument of input path to source file!')
        exit(1)

def get_input_file_path() -> str:
    if not os.path.exists(sys.argv[1]):
        print('the input path to source file does not exist!')
        exit(1)
    return sys.argv[1]

def get_input_data(path: str) -> list[str]:
    #data = []
    rder = PdfReader(path)
    for pg in rder.pages:
        print (pg.extract_text())

def main() -> None:
    check_args_valid()
    in_path = get_input_file_path()
    get_input_data(in_path)

if __name__ == '__main__':
    main()

