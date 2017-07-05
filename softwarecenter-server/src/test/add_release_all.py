#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import subprocess

file = open("log")
while 1:
    lines = file.readlines()
    if not lines:
        break

    for line in lines:
        line = line.strip('\n     ')
        (p1, p2, p3, p4, p5, p6, p7, p8) = (line.split('|'))
        subprocess.call(["./add_release.sh", p1, p7, p6, p1, p8])

