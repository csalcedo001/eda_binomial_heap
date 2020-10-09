#!/bin/bash

if [ ! -f docs/graph.in ]; then
	echo "Input file docs/graph.in not found"
else
	./bin/graph < docs/graph.in | dot -Tps -o docs/graph.ps
	ps2pdf docs/graph.ps
	mv graph.pdf docs/
	rm docs/graph.ps
fi
