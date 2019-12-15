import json
import sqlite3
import urllib.request

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
url = "https://api.overwatchleague.com/players"
response = urllib.request.urlopen(url)
data = json.loads(response.read())

db = create_connection("../dbapp/owdb.db")
c = db.cursor()
#c.execute("CREATE TABLE IF NOT EXISTS Player (PlayerID int PRIMARY KEY, Handle char(30), Name char(30), Location char(30), PlayerNumber int, Role char(10), Picture char(100))")
#c.execute("CREATE TABLE IF NOT EXISTS PlayersTeam (PlayerID int REFERENCES Player(PlayerID), TeamID int REFERENCES Team(TeamID), UNIQUE(PlayerID, TeamID))")
ctr = 0

#Insert Player Data
for i in data['content']:
    try:
        print (ctr)
        ctr += 1
        tmpdata = [i['id'], i['handle'], i['name'], i['homeLocation'], i['attributes']['player_number'], i['attributes']['role'], i['headshot']]
        c.execute('insert into Player (PlayerID, Handle, Name, Location, PlayerNumber, Role, Picture) values (?,?,?,?,?,?,?)', tmpdata)
    except:
        pass

#Insert Team Data
for i in data['content']:
    try:
        print (ctr)
        ctr += 1
        for j in i['teams']:
            tmdata = [j['team']['id'], j['team']['name'], j['team']['logo']]
            c.execute('insert into Team (TeamID, Name, Logo) values (?,?,?)', tmdata)

    except:
        pass

#Insert Teams Players have played on.
for i in data['content']:
    try:
        print (ctr)
        ctr += 1
        for j in i['teams']:
            tdata =  [i['id'], j['team']['id']]
            c.execute('insert into PlayersTeam (PlayerID, TeamID) VALUES (?,?)', tdata)
    except:
        pass
db.commit()
db.close()
