CREATE TABLE Player (
    PlayerID int PRIMARY KEY,
    Handle char(30),
    Name char(30),
    Location char(30),
    PlayerNumber int,
    Role char(10),
    Picture varchar
);

CREATE TABLE PlayersTeam (
    PlayerID int REFERENCES Player(PlayerID),
    TeamID int REFERENCES Team(TeamID),
    PRIMARY KEY(PlayerID, TeamID)
);

CREATE TABLE Team (
    TeamID int PRIMARY KEY,
    Name char(30),
    Division char(30),
    Logo varchar,
    PrimaryColor char(10),
    SecondaryColor char(10),
    Location varchar
);

CREATE TABLE Match (
    MatchID int PRIMARY KEY,
    Team1 int REFERENCES Team(TeamID),
    Team2 int REFERENCES Team(TeamID),
    Time int,
    Score char(10),
    Winner int REFERENCES Team(TeamID)
);

CREATE TABLE Map (
    Name varchar PRIMARY KEY,
    Type varchar,
    Picture varchar
);

CREATE TABLE MapInstance (
    Number int,
    MatchID int REFERENCES Match (MatchID),
    Name varchar REFERENCES Map,
    Time int,
    Score char(10),
    PRIMARY KEY(Number, MatchID)
);

CREATE TABLE PlayedOn(
    Match int,
    MapNumber int,
    Hero varchar,
    Player int REFERENCES Player(PlayerID),
    Damage float,
    Deaths int,
    Eliminations int,
    Healing float,
    FOREIGN KEY(Match, MapNumber) REFERENCES MapInstance,
    PRIMARY KEY(Match, MapNumber, Hero, Player)
);

CREATE TABLE Coach (
    CoachID int PRIMARY KEY,
    Handle char(30),
    Name char(30),
    Team int REFERENCES Team(TeamID)
);

CREATE TABLE Personnel (
    StageName char(30) PRIMARY KEY,
    Name varchar,
    Type varchar,
    Picture varchar
);

CREATE TABLE Stats (
    Player int REFERENCES Player(PlayerID),
    Hero varchar,
    Damage float,
    Deaths float,
    Eliminations float,
    Healing float,
    FinalBlows float,
    Ultimates float,
    Time float,
    PRIMARY KEY(Player, Hero)
);
