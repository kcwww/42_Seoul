#!/bin/bash

arg=$(seq 1 100 | sort -R  | tr '\n' ' '); ./push_swap $(echo $arg) |  ./checker $(echo $arg)
./push_swap $(echo $arg) | ./checker_Mac $(echo $arg)