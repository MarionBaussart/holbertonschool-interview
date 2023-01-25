#!/usr/bin/python3
""" script that reads stdin line by line and computes metrics
"""
import sys


nb_line_read = 0
total_size = 0
status_code_dict = {"200": 0, "301": 0, "400": 0, "401": 0,
                    "403": 0, "404": 0, "405": 0, "500": 0}

try:
    for line in sys.stdin:
        splited_line = line.split()
        if len(splited_line) != 9:
            pass

        # get sum of size
        size_line = int(splited_line[8])
        total_size += size_line

        # nb of line by status code
        status_code_line = splited_line[7]
        for status_code in status_code_dict:
            if status_code_line == status_code:
                status_code_dict[status_code_line] += 1

        nb_line_read += 1

        if nb_line_read % 10 == 0:
            print("File size: {}".format(total_size))
            for status_code in status_code_dict:
                if status_code_dict[status_code] != 0:
                    print("{}: {}".format(status_code,
                                          status_code_dict[status_code]))

except KeyboardInterrupt:
    raise

finally:
    print("File size: {}".format(total_size))
    for status_code in status_code_dict:
        if status_code_dict[status_code] != 0:
            print("{}: {}".format(status_code,
                                  status_code_dict[status_code]))
