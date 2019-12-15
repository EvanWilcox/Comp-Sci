import sqlite3
import sys

'''
Run program with no arguments drops all tables.
Run program with 1 or more arguments drops tables with those names.
'''

conn = sqlite3.connect("../dbapp/owdb.db")
c = conn.cursor()

# Drops all tables.
if len(sys.argv) == 1:
    dropList = ["DROP TABLE IF EXISTS Player", 
                "DROP TABLE IF EXISTS PlayersTeam",
                "DROP TABLE IF EXISTS Team", 
                "DROP TABLE IF EXISTS Match", 
                "DROP TABLE IF EXISTS Map", 
                "DROP TABLE IF EXISTS MapInstance",
                "DROP TABLE IF EXISTS PlayedOn",
                "DROP TABLE IF EXISTS Coach",
                "DROP TABLE IF EXISTS Personnel",
                "DROP TABLE IF EXISTS Stats"]
    for i in dropList:
        c.execute(i)

#Drops tables specified by command line arguments.
else:
    for i in sys.argv[1:]:
        command = "DROP TABLE IF EXISTS " + i
        c.execute(command)

conn.commit()
conn.close()
