const express = require('express');
const cors = require('cors');
const sqlite3 = require('sqlite3').verbose();
const app = express();
const path = require('path')
const allPlayers = 'SELECT * FROM Players';

let db = new sqlite3.Database('owdb.db', sqlite3.OPEN_READWRITE, (err) => {
  if (err) {
    console.error(err.message);
  }
  console.log('Connected to the database.');
});

app.use(cors());

app.get('/players', (req, res) => {
  db.all('SELECT * FROM Player', [], (err, rows) => {
    if (err) {
      console.error(err.message);
    }
    return res.json({
      data: rows
    });
  })
});
app.get('/players/player', (req, res) => {
  const {player} = req.query;
  db.all(`SELECT * FROM Player where PlayerID=${player}`, [], (err, rows) => {
    if (err) {
      console.error(err.message);
    }
    return res.json({
      data: rows
    });
  })
});

app.get('/teams', (req, res) => {
  db.all('SELECT * FROM Team', [], (err, rows) => {
    if (err) {
      console.error(err.message);
    }
    return res.json({
      data: rows
    });
  })
});

app.get('/teams/team', (req, res) => {
  const {TeamID} = req.query;
  db.all(`SELECT * FROM Team WHERE TeamID='${TeamID}'`, [], (err, rows) => {
    if (err) {
      console.error(err.message);
    }
    return res.json({
      data: rows
    });
  })
});

app.get('/matches', (req, res) => {
  db.all('SELECT * FROM Match', [], (err, rows) => {
    if (err) {
      console.error(err.message);
    }
    return res.json({
      data: rows
    });
  })
});

app.get('/matches/match', (req, res) => {
  const {match} = req.query
  db.all(`SELECT * FROM Match WHERE MatchID='${match}'`, [], (err, rows) => {
    if (err) {
      console.error(err.message);
    }
    return res.json({
      data: rows
    });
  })
});

app.get('/matches/match/1', (req, res) => {
  const {match} = req.query
  db.all(`SELECT * FROM Player, Match, PlayedOn, MapInstance, PlayersTeam WHERE Match.MatchID='${match}' and Match.MatchID=PlayedOn.Match and Match.MatchID=MapInstance.MatchID and MapInstance.Number = PlayedOn.MapNumber and Player.PlayerID = PlayedOn.Player and PlayedOn.MapNumber='1' and PlayersTeam.PlayerID=PlayedOn.Player and (Team1=TeamID or Team2=TeamID)`, [], (err, rows) => {
    if (err) {
      console.error(err.message);
    }
    return res.json({
      data: rows
    });
  })
});
app.get('/matches/match/2', (req, res) => {
  const {match} = req.query
  db.all(`SELECT * FROM Player, Match, PlayedOn, MapInstance, PlayersTeam WHERE Match.MatchID='${match}' and Match.MatchID=PlayedOn.Match and Match.MatchID=MapInstance.MatchID and MapInstance.Number = PlayedOn.MapNumber and Player.PlayerID = PlayedOn.Player and PlayedOn.MapNumber='2' and PlayersTeam.PlayerID=PlayedOn.Player and (Team1=TeamID or Team2=TeamID)`, [], (err, rows) => {
    if (err) {
      console.error(err.message);
    }
    return res.json({
      data: rows
    });
  })
});

app.get('/matches/match/3', (req, res) => {
  const {match} = req.query
  db.all(`SELECT * FROM Player, Match, PlayedOn, MapInstance, PlayersTeam WHERE Match.MatchID='${match}' and Match.MatchID=PlayedOn.Match and Match.MatchID=MapInstance.MatchID and MapInstance.Number = PlayedOn.MapNumber and Player.PlayerID = PlayedOn.Player and PlayedOn.MapNumber='3' and PlayersTeam.PlayerID=PlayedOn.Player and (Team1=TeamID or Team2=TeamID)`, [], (err, rows) => {
    if (err) {
      console.error(err.message);
    }
    return res.json({
      data: rows
    });
  })
});

app.get('/matches/match/4', (req, res) => {
  const {match} = req.query
  db.all(`SELECT * FROM Player, Match, PlayedOn, MapInstance, PlayersTeam WHERE Match.MatchID='${match}' and Match.MatchID=PlayedOn.Match and Match.MatchID=MapInstance.MatchID and MapInstance.Number = PlayedOn.MapNumber and Player.PlayerID = PlayedOn.Player and PlayedOn.MapNumber='4' and PlayersTeam.PlayerID=PlayedOn.Player and (Team1=TeamID or Team2=TeamID)`, [], (err, rows) => {
    if (err) {
      console.error(err.message);
    }
    return res.json({
      data: rows
    });
  })
});

app.get('/matches/match/5', (req, res) => {
  const {match} = req.query
  db.all(`SELECT * FROM Player, Match, PlayedOn, MapInstance, PlayersTeam WHERE Match.MatchID='${match}' and Match.MatchID=PlayedOn.Match and Match.MatchID=MapInstance.MatchID and MapInstance.Number = PlayedOn.MapNumber and Player.PlayerID = PlayedOn.Player and PlayedOn.MapNumber='5' and PlayersTeam.PlayerID=PlayedOn.Player and (Team1=TeamID or Team2=TeamID)`, [], (err, rows) => {
    if (err) {
      console.error(err.message);
    }
    return res.json({
      data: rows
    });
  })
});

app.get('/player', (req, res) => {
  const {player} = req.query;
  db.all(`SELECT * FROM Player WHERE Name='${player}'`, [], (err, rows) => {
    if (err) {
      console.error(err.message);
    }
    return res.json({
      data: rows
    });
  })
});



app.get('/stats/player', (req, res) => {
  const {player} = req.query;
  db.all(`SELECT * FROM PlayedOn JOIN (SELECT PlayerId FROM Player WHERE Name='${player}') where PlayedOn.Player=PlayerId`, [], (err, rows) => {
    if (err) {
      console.error(err.message);
    }
    return res.json({
      data: rows
    });
  })
});

app.get('/stats/team', (req, res) => {
  const {team} = req.query;
  db.all(`SELECT * FROM Team, PlayersTeam, Player WHERE Team.Name='${team}' and PlayersTeam.TeamID = Team.TeamID and PlayersTeam.PlayerID = Player.PlayerId`, [], (err, rows) => {
    if (err) {
      console.error(err.message);
    }
    return res.json({
      data: rows
    });
  })
});

app.get('/stats/match', (req, res) => {
  const {team} = req.query;
  db.all(`SELECT * FROM (SELECT MatchID, Team1, Team2, Winner, Time, Score, TeamID as Team1ID, Name as Team1Name, Logo as Team1Logo FROM Match, Team as T1 WHERE Team1ID=Team1), Team WHERE Team2=TeamID AND (Name='${team}' or Team1Name='${team}') ORDER BY MatchID DESC`, [], (err, rows) => {
    if (err) {
      console.error(err.message);
    }
    return res.json({
      data: rows
    });
  })
});

app.get('/stats/cmpmatch', (req, res) => {
  const {team, team2} = req.query;
  db.all(`SELECT * FROM (SELECT MatchID, Team1, Team2, Winner, Time, Score, TeamID as Team1ID, Name as Team1Name, Logo as Team1Logo FROM Match, Team as T1 WHERE Team1ID=Team1), Team WHERE Team2=TeamID AND ((Name='${team}' and Team1Name='${team2}') or (Name='${team2}' and Team1Name='${team}')) ORDER BY MatchID DESC`, [], (err, rows) => {
    if (err) {
      console.error(err.message);
    }
    return res.json({
      data: rows
    });
  })
});

app.get('/herostats/player', (req, res) => {
  const {player} = req.query;
  db.all(`SELECT * FROM Stats JOIN (SELECT PlayerId FROM Player WHERE Name='${player}') where Stats.Player=PlayerId`, [], (err, rows) => {
    if (err) {
      console.error(err.message);
    }
    return res.json({
      data: rows
    });
  })
});

app.get('/cmpplayer', (req, res) => {
  const {player1, player2} = req.query;
  db.all(`SELECT * FROM
          (SELECT Hero, Damage as P1Damage, Healing AS P1Healing, Eliminations as P1Elims, Deaths as P1Deaths, Ultimates as P1Ultimates, FinalBlows as P1FinalBlows, Time as P1Time
            FROM Stats JOIN
              (SELECT PlayerId FROM Player WHERE Name='${player1}') as p1id
                WHERE Stats.Player=p1id.PlayerId) AS P1
          JOIN
          (SELECT Hero, Damage as P2Damage, Healing AS P2Healing, Eliminations as P2Elims, Deaths as P2Deaths, Ultimates as P2Ultimates, FinalBlows as P2FinalBlows, Time as P2Time
            FROM Stats as S2 JOIN
              (SELECT PlayerId FROM Player WHERE Name='${player2}') as p2id
                WHERE S2.Player=p2id.PlayerId) AS P2
          WHERE P1.Hero = P2.Hero
          `, [], (err, rows) => {
    if (err) {
      console.error(err.message);
    }
    return res.json({
      data: rows
    });
  })
});


// Serve static files from the React frontend app
app.use(express.static(path.join(__dirname, '../webapp/build')))
// Anything that doesn't match the above, send back index.html
app.get('*', (req, res) => {
  console.log(path.join(__dirname + '../../webapp/build/index.html'))
  res.sendFile(path.join(__dirname + '../../webapp/build/index.html'))
})

var port = process.env.OPENSHIFT_NODEJS_PORT || 8080
app.listen(port, "0.0.0.0", () => {
  console.log("Server listening on " + port);
});
