#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import subprocess

file = open("categories")
while 1:
    lines = file.readlines()
    if not lines:
        break

    cs={}

    for line in lines:
        line = line.strip('\n     ')
        (v, k) = line.split(' ')
        cs[k] = v
        

file = open("log")
while 1:
    lines = file.readlines()
    if not lines:
        break

    for line in lines:
        line = line.strip('\n     ')
        (p1, p2, p3, p4, p5, p6, p7, p8) = (line.split('|'))
        if p3 == '':
            p3 = 'Other'
        subprocess.call(["./add_product.sh", p1, p2, cs[p3], p4, p5])

