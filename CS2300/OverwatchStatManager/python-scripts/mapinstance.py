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

db = create_connection("..\dbapp\owdb.db")
c = db.cursor()
mapurl = "https://api.overwatchleague.com/maps"
staturl = "https://api.overwatchleague.com/stats/matches/"
response = urllib.request.urlopen(mapurl)
mapdata = json.loads(response.read())
mapdict = {}
for i in mapdata:
    mapdict[i['guid']] = i['name']['en_US']
print(mapdict)

for i in range(10223,10634):
    for j in range(1,6):
        try:
            tmpurl2 = staturl + str(i) + "/maps/" + str(j)
            response2 = urllib.request.urlopen(tmpurl2)
            statdata = json.loads(response2.read())
            tmpurl = "https://api.overwatchleague.com/match/" + str(i)
            res = urllib.request.urlopen(tmpurl)
            mdata = json.loads(res.read())
            score = str(mdata['games'][j-1]['attributes']['mapScore']['team1']) + " - " + str(mdata['games'][j-1]['attributes']['mapScore']['team2'])
            tmpdata = [j, i, str(mapdict[statdata['map_id']]), statdata['stats'][0]['value'], score]
            print(tmpdata)
            c.execute("INSERT INTO MapInstance (Number, MatchID, Name, Time, Score) VALUES (?,?,?,?,?)", tmpdata)
        except:
            pass
db.commit()
db.close()
