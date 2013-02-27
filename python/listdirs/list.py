import os

dirList = os.listdir("/var") # current directory
for dir in dirList:
  if os.path.isdir("/var/" + dir) == True:
    print dir
    add_notify("/var/" + dir)
  else:
    print "not a directory"
