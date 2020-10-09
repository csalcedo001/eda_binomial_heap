#!/bin/bash

echo "$1" | ./bin/graph | dot -Tps -o docs/result.ps
ps2pdf docs/result.ps
