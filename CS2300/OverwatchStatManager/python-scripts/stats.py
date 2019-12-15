import json
import urllib.request
from datetime import datetime, timezone
import sqlite3

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

playerurl = "https://api.overwatchleague.com/players/"
playerend = "?locale=en-us&expand=article,vods,stats,stat.ranks,team,team.matches.recent,similarPlayers"
staturl = "https://api.overwatchleague.com/stats/matches/"

response = urllib.request.urlopen(url)
data = json.loads(response.read())
print(json.dumps(data['content'][0]['id'], sort_keys=True, indent=4))
ctr = 1
