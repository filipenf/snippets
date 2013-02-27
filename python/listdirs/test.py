#!/bin/python
# recursivelly list all .html files in /tmp

import os
import sys

path = sys.argv[1]
for root, dirs, files in os.walk(path):
    for name in files:
        if name.endswith((".html", ".htm")):
            print name
