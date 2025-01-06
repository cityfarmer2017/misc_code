#!/bin/python3

import sys
import os
import re

pattern_str = r'^(7A|10)[\s\dA-Z]{26}.*$'

match_2_dst_files = {
    "7AQT": "4002.txt",
    "10QT": "4026.txt",
    "100576": "3589.txt",
    "100580": "3589.txt",
    "10": "297.txt",
    "7A": "3563.txt",
}

dst_files = ["4002.txt", "4026.txt", "3589.txt", "297.txt", "3563.txt"]

def check_parameters_valid() -> None:
    if len(sys.argv) != 3:
        print("this script shall take exactly 2 arguments of source path to input file and destination directory!")
        exit(1)

def get_src_file_path() -> str:
    if not os.path.exists(sys.argv[1]):
        print("the source path to input file does not exist!")
        exit(1)
    return sys.argv[1]

def get_dst_path() -> str:
    dir = sys.argv[2]
    if not os.path.exists(dir):
        try:
            os.makedirs(dir)
        except PermissionError:
            print(f"Permission denied: Unable to create '{dir}'.")
            exit(1)
        except Exception as e:
            print(f"An error occured: {e}")
            exit(1)
    else:
        try:
            files = os.listdir(dir)
            for file in files:
                if file in dst_files:
                    file_path = os.path.join(dir, file)
                    if os.path.isfile(file_path):
                        os.remove(file_path)
        except OSError as e:
            print(f"An error occured: {e}")
    return dir

def match_src_lines_to_dest_files(src_path: str, dst_path: str) -> None:
    # data = {}
    with open(src_path, 'r') as file:
        lines = file.readlines()
        for line in lines:
            matches = re.search(pattern_str, line.strip())
            if matches is None:
                print("no matching!")
                continue
            match_str = matches.group(1)
            if line[8:10] == "QT":
                match_str += line[8:10]
            else:
                if line[23:27] == "0576" or line[23:27] == "0580":
                    match_str += line[23:27]
            # print(match_str)
            dst_file_path = os.path.join(dst_path, match_2_dst_files[match_str])
            dst_file = open(dst_file_path, 'a')
            dst_file.write(line.strip() + '\n')

def main() -> None:
    check_parameters_valid()
    src_path = get_src_file_path()
    dst_path = get_dst_path()
    match_src_lines_to_dest_files(src_path, dst_path)

if __name__ == '__main__':
    main()