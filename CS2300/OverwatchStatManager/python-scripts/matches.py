import json
import urllib.request
from datetime import datetime, timezone

url = "https://api.overwatchleague.com/match/"

response = urllib.request.urlopen(url)
data = json.loads(response.read())
print(json.dumps(data['content'][0]['id'], sort_keys=True, indent=4))
ctr = 1
for i in range(10223,16600):
    try:
        tmpurl = url + str(i)
        response = urllib.request.urlopen(tmpurl)
        data = json.loads(response.read())
        if (data['bracket']['stage']['tournament']['attributes']['program']['type'] == "owl"):
            print(ctr, ":", data['id'], data['competitors'][0]['name'], "vs", data['competitors'][1]['name'], data['scores'][0]['value'], "-", data['scores'][1]['value'], data['startDate'], data['winner']['name'])
            ctr += 1
    except KeyboardInterrupt:
        break
    except:
        pass
#10223 - 10632 are stages 1 - 4
#13121 to 13134 are finals

#print(data['content'])
