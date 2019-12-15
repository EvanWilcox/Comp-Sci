import sqlite3
from sqlite3 import OperationalError
import os

def create_connection(db_file):
    """ create a database connection to the SQLite database
        specified by db_file
    :param db_file: database file
    :return: Connection object or None
    """
    try:
        conn = sqlite3.connect(db_file)
        return conn
    except Error as e:
        print(e)

    return None

db = create_connection("../dbapp/owdb.db")
c = db.cursor()

# Read commands from sql file
f = open('owdb.sql', 'r')
sqlFile = f.read()
f.close()

sqlCommands = sqlFile.split(';')

# Execute every command from the input file
for command in sqlCommands:
    # This will skip and report errors
    # For example, if the tables do not yet exist, this will skip over
    # the DROP TABLE commands
    try:
        c.execute(command)
    except OperationalError as msg:
        print ("Command skipped:", msg)

db.commit()
db.close()
