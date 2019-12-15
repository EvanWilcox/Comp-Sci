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
playerend = "?locale=en-us&expand=article,vods,stats"
url = "https://api.overwatchleague.com/match/"
staturl = "https://api.overwatchleague.com/stats/matches/"
response = urllib.request.urlopen(url)
data = json.loads(response.read())
print(json.dumps(data['content'][0]['id'], sort_keys=True, indent=4))
ctr = 1
for i in range(10223,10634):
    try:
        tmpurl = url + str(i)
        response = urllib.request.urlopen(tmpurl)
        data = json.loads(response.read())
        if (data['bracket']['stage']['tournament']['attributes']['program']['type'] == "owl"):
            print(ctr, ":", data['id'], data['competitors'][0]['name'], "vs", data['competitors'][1]['name'], data['scores'][0]['value'], "-", data['scores'][1]['value'], data['startDate'], data['winner']['name'])
            matchdata = [data['id'], data['competitors'][0]['id'], data['competitors'][1]['id'], str(data['scores'][0]['value']) + '-' + str(data['scores'][1]['value']), data['winner']['id']]
            try:
                c.execute('insert into Match (MatchID, Team1, Team2, Score, Winner) VALUES (?,?,?,?,?)', matchdata)
            except:
                print("error")
            for j in data['games']:
                for k in j["players"]:
                    t=k['team']
                    k=k['player']
                    tmpdata = [k['id'], k['handle'], k['name'],k['homeLocation'],k['attributes']['player_number'], k['attributes']['role'], k['headshot']]
                    print("Here")
                    try:
                        c.execute("INSERT INTO Player (PlayerID, Handle, Name, Location, PlayerNumber, Role, Picture) values (?,?,?,?,?,?,?)", tmpdata)
                        purl = playerurl+str(k['id'])+playerend
                        print(purl)
                        pres = urllib.request.urlopen(purl)
                        pdat = json.loads(pres.read())
                        print("WHAT")
                        for m in pdat['data']['stats']['heroes']:
                            try:
                                ptmpdata = [pdat['data']['player']['id'], m['name'], m['stats']['hero_damage_avg_per_10m'], m['stats']['deaths_avg_per_10m'], m['stats']['eliminations_avg_per_10m'], m['stats']['healing_avg_per_10m'], m['stats']['final_blows_avg_per_10m'], m['stats']['ultimates_earned_avg_per_10m'], m['stats']['time_played_total']]
                                print(ptmpdata)
                                c.execute("INSERT INTO STATS (Player, Hero, Damage, Deaths, Eliminations, Healing, FinalBlows, Ultimates, Time) values (?,?,?,?,?,?,?,?,?)", ptmpdata)
                            except:
                                print("SOMETHING WEIRD HAPPENED")
                    except Exception as e:
                        print(e)
                    try:
                        print(k['id'], t['id'])
                        c.execute('INSERT INTO PlayersTeam (PlayerID, TeamID) VALUES (?,?)', [k['id'], t['id']])
                    except Exception as e:
                        print(e)
                        pass


            for j in range(1,5):
                tmpurl2 = staturl + str(i) + "/maps/" + str(j)
                response2 = urllib.request.urlopen(tmpurl2)
                statdata = json.loads(response2.read())
                print("\t", statdata['game_number'], end=" ")

                for k in statdata['teams']:
                    for l in k["players"]:
                        for m in l["heroes"]:
                            print("\t",l['esports_player_id'])
                            try:
                                damage = 0
                                deaths = 0
                                elims = 0
                                healing = 0
                                for n in m['stats']:
                                    if (n['name'] == "damage"):
                                        damage = n['value']
                                    if (n['name'] == "deaths"):
                                        deaths = n['value']
                                    if (n['name'] == "eliminations"):
                                        elims = n['value']
                                    if (n['name'] == "healing"):
                                        healing = n['value']

                                insertdata = [statdata['esports_match_id'], j, m['name'], l['esports_player_id'], damage, deaths, elims, healing]
                                c.execute('insert into PlayedOn (Match, MapNumber, Hero, Player, Damage, Deaths, Eliminations, Healing) values (?,?,?,?,?,?,?,?)', insertdata)
                            except:
                                print("UHOH")
                                try:
                                    insertdata = [statdata['esports_match_id'], j, m['name'], l['esports_player_id'], m['stats'][0]['value'], m['stats'][1]['value'], m['stats'][2]['value']]
                                    c.execute('insert into PlayedOn (Match, MapNumber, Hero, Player, Damage, Deaths, Eliminations) values (?,?,?,?,?,?,?)', insertdata)
                                except:
                                    pass
                    print("| ", end="")
                print()
            ctr += 1
    except KeyboardInterrupt:
        break
    except:
        pass
db.commit()
db.close()
#10223 - 10632 are stages 1 - 4
#13121 to 13134 are finals
