#!/bin/bash

dot -Tps graph1.gv -o graph1.ps
ps2pdf graph1.ps
