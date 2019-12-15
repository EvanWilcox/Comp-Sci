import sqlite3

db = sqlite3.connect("../dbapp/owdb.db")
c = db.cursor()

choice = 1
while choice:
    print ("\n\n\nSelect an operation: ")
    print ("0. Exit")
    print ("1. Insert")
    print ("2. Update")
    print ("3. Delete")

    choice = int(input("Choice: "))

    #Insert
    if choice == 1:
        print("\n\n\nSelect a table:")
        print("0. Back to Menu")
        print("1. Player")
        print("2. PlayersTeam")
        print("3. Team")
        print("4. Match")
        print("5. Map")
        print("6. MapInstance")
        print("7. PlayedOn")
        print("8. Coach")
        print("9. Personnel")
        print("10. Stats")
        
        table = int(input("Table: "))

        if table == 1:
            print ("\n\n\nTable: Player")
            PlayerID = input("PlayerID(PRIMARY KEY): ")
            Handle = input("Handle: ")
            Name = input("Name: ")
            Location = input("Location: ")
            PlayerNumber = input("PlayerNumber: ")
            Role = input("Role: ")
            Picture = input("Picture: ")
            c.execute("INSERT INTO Player VALUES(?,?,?,?,?,?,?)", (PlayerID,Handle,Name,Location,PlayerNumber,Role,Picture))

        if table == 2:
            print ("\n\n\nTable: PlayersTeam")
            PlayerID = input("PlayerID(PRIMARY KEY): ")
            TeamID = input("TeamID(PRIMARY KEY): ")
            c.execute("INSERT INTO PlayersTeam VALUES(?,?)", (PlayerID,TeamID))

        if table == 3:
            print ("\n\n\nTable: Team")
            TeamID = input("TeamID(PRIMARY KEY): ")
            Name = input("Name: ")
            Division = input("Division: ")
            Logo = input("Logo: ")
            PrimaryColor = input("PrimaryColor: ")
            SecondaryColor = input("SecondaryColor: ")
            Location = input("Location: ")
            c.execute("INSERT INTO Team VALUES(?,?,?,?,?,?,?)", (TeamID,Name,Division,Logo,PrimaryColor,SecondaryColor,Location))

            
        if table == 4:
            print ("\n\n\nTable: Match")
            MatchID = input("MatchID(PRIMARY KEY): ")
            Team1 = input("Team1: ")
            Team2 = input("Team2: ")
            Time = input("Time: ")
            Score = input("Score: ")
            Winner = input("Winner: ")
            c.execute("INSERT INTO Match VALUES(?,?,?,?,?,?)", (MatchID,Team1,Team2,Time,Score,Winner))


        if table == 5:
            print ("\n\n\nTable: Map")
            Name = input("Name(PRIMARY KEY): ")
            Type = input("Type: ")
            Picture = input("Picture: ")
            c.execute("INSERT INTO Map VALUES(?,?,?)", (Name,Type,Picture))

        if table == 6:
            print ("\n\n\nTable: MapInstance")
            Number = input("Number(PRIMARY KEY): ")
            MatchID = input("MatchID(PRIMARY KEY): ")
            Name = input("Name: ")
            Time = input("Time: ")
            Score = input("Score: ")
            c.execute("INSERT INTO MapInstance VALUES(?,?,?,?,?)", (Number,MatchID,Name,Time,Score))

        if table == 7:
            print ("\n\n\nTable: PlayedOn")
            Match = input("Match(PRIMARY KEY): ")
            MapNumber = input("MapNumber(PRIMARY KEY): ")
            Hero = input("Hero(PRIMARY KEY): ")
            Player = input("Player(PRIMARY KEY): ")
            Damage = input("Damage: ")
            Deaths = input("Deaths: ")
            Eliminations = input("Eliminations: ")
            Healing = input("Healing: ")
            c.execute("INSERT INTO PlayedOn VALUES(?,?,?,?,?,?,?,?)", (Match,MapNumber,Hero,Player,Damage,Deaths,Eliminations,Healing))


        if table == 8:
            print ("\n\n\nTable: Coach")
            CoachID = input("CoachID(PRIMARY KEY): ")
            Handle = input("Handle: ")
            Name = input("Name: ")
            Team = input("Team: ")
            c.execute("INSERT INTO Coach VALUES(?,?,?,?)", (CoachID,Handle,Name,Team))

        if table == 9:
            print ("\n\n\nTable: Personnel")
            StageName = input("StageName(PRIMARY KEY): ")
            Name = input("Name: ")
            Type = input("Type: ")
            Picture = input("Picture: ")
            c.execute("INSERT INTO Personnel VALUES(?,?,?,?)", (StageName,Name,Type,Picture))

        if table == 10:
            print ("\n\n\nTable: Stats")
            Player = input("Player(PRIMARY KEY): ")
            Hero = input("Hero(PRIMARY KEY): ")
            Damage = input("Damage: ")
            Deaths = input("Deaths: ")
            Eliminations = input("Eliminations: ")
            Healing = input("Healing: ")
            FinalBlows = input("FinalBlows: ")
            Ultimates = input("Ultimates: ")
            Time = input("Time: ")
            c.execute("INSERT INTO Stats VALUES(?,?,?,?,?,?,?,?,?)", (Player,Hero,Damage,Deaths,Eliminations,Healing,FinalBlows,Ultimates,Time))

    #Update
    elif choice == 2:
        print("\n\n\nSelect a table:")
        print("0. Back to Menu")
        print("1. Player")
        print("2. PlayersTeam")
        print("3. Team")
        print("4. Match")
        print("5. Map")
        print("6. MapInstance")
        print("7. PlayedOn")
        print("8. Coach")
        print("9. Personnel")
        print("10. Stats")
        
        table = int(input("Table: "))

        if table == 1:
            print ("\n\n\nTable: Player")
            PlayerID = input("PlayerID(PRIMARY KEY): ")
            Handle = input("Handle: ")
            Name = input("Name: ")
            Location = input("Location: ")
            PlayerNumber = input("PlayerNumber: ")
            Role = input("Role: ")
            Picture = input("Picture: ")
            c.execute("UPDATE Player SET Handle=?, Name=?, Location=?, PlayerNumber=?, Role=?, Picture=? WHERE PlayerID=?", (Handle,Name,Location,PlayerNumber,Role,Picture,PlayerID))

        if table == 2:
            print ("\n\n\nTable: PlayersTeam")
            PlayerID = input("PlayerID(PRIMARY KEY): ")
            TeamID = input("TeamID(PRIMARY KEY): ")
            #c.execute("UPDATE PlayersTeam SET PlayerID=?, TeamID=? WHERE PlayerID=?, TeamID=?", (Handle,Name,Location,PlayerNumber,Role,Picture,PlayerID))


        if table == 3:
            print ("\n\n\nTable: Team")
            TeamID = input("TeamID(PRIMARY KEY): ")
            Name = input("Name: ")
            Division = input("Division: ")
            Logo = input("Logo: ")
            PrimaryColor = input("PrimaryColor: ")
            SecondaryColor = input("SecondaryColor: ")
            Location = input("Location: ")
            c.execute("UPDATE Player SET Name=?, Division=?, Logo=?, PrimaryColor=?, SecondaryColor=?, Location=? WHERE TeamID=?", (Name,Division,Logo,PrimaryColor,SecondaryColor,Location,TeamID))


            
        if table == 4:
            print ("\n\n\nTable: Match")
            MatchID = input("MatchID(PRIMARY KEY): ")
            Team1 = input("Team1: ")
            Team2 = input("Team2: ")
            Time = input("Time: ")
            Score = input("Score: ")
            Winner = input("Winner: ")
            c.execute("UPDATE Match SET Team1=?, Team2=?, Time=?, Score=?, Winner=? WHERE MatchID=?", (Team1,Team2,Time,Score,Winner,MatchID))



        if table == 5:
            print ("\n\n\nTable: Map")
            Name = input("Name(PRIMARY KEY): ")
            Type = input("Type: ")
            Picture = input("Picture: ")
            c.execute("UPDATE Map SET Type=?, Picture=? WHERE Name=?", (Name,Type,Picture))

        if table == 6:
            print ("\n\n\nTable: MapInstance")
            Number = input("Number(PRIMARY KEY): ")
            MatchID = input("MatchID(PRIMARY KEY): ")
            Name = input("Name: ")
            Time = input("Time: ")
            Score = input("Score: ")
            c.execute("UPDATE MapInstance SET Name=?, Time=?, Score=? WHERE Number=? and MatchID=?", (Name,Time,Score,Number,MatchID))

        if table == 7:
            print ("\n\n\nTable: PlayedOn")
            Match = input("Match(PRIMARY KEY): ")
            MapNumber = input("MapNumber(PRIMARY KEY): ")
            Hero = input("Hero(PRIMARY KEY): ")
            Player = input("Player(PRIMARY KEY): ")
            Damage = input("Damage: ")
            Deaths = input("Deaths: ")
            Eliminations = input("Eliminations: ")
            Healing = input("Healing: ")
            c.execute("UPDATE PlayedOn SET Damage=?, Deaths=?, Eliminations=?, Healing=? WHERE Match=? and MapNumber=? and Hero=? and Player=?", (Damage,Deaths,Eliminations,Healing,Match,MapNumber,Hero,Player))


        if table == 8:
            print ("\n\n\nTable: Coach")
            CoachID = input("CoachID(PRIMARY KEY): ")
            Handle = input("Handle: ")
            Name = input("Name: ")
            Team = input("Team: ")
            c.execute("UPDATE Coach SET Handle=?, Name=?, Team=? WHERE CoachID=?", (Handle,Name,Team,CoachID))

        if table == 9:
            print ("\n\n\nTable: Personnel")
            StageName = input("StageName(PRIMARY KEY): ")
            Name = input("Name: ")
            Type = input("Type: ")
            Picture = input("Picture: ")
            c.execute("UPDATE Personnel SET Name=?, Type=?, Picture=?", (Name,Type,Picture,StageName))

        if table == 10:
            print ("\n\n\nTable: Stats")
            Player = input("Player(PRIMARY KEY): ")
            Hero = input("Hero(PRIMARY KEY): ")
            Damage = input("Damage: ")
            Deaths = input("Deaths: ")
            Eliminations = input("Eliminations: ")
            Healing = input("Healing: ")
            FinalBlows = input("FinalBlows: ")
            Ultimates = input("Ultimates: ")
            Time = input("Time: ")
            c.execute("UPDATE Stats SET Damage=?, Deaths=?, Eliminations=?, Healing=?, FinalBlows=?, Ultimates=?, Time=? WHERE Player=? and Hero=?", (Damage,Deaths,Eliminations,Healing,FinalBlows,Ultimates,Time,Player,Hero))


    #Delete
    if choice == 3:
        print("\n\n\nSelect a table:")
        print("0. Back to Menu")
        print("1. Player")
        print("2. PlayersTeam")
        print("3. Team")
        print("4. Match")
        print("5. Map")
        print("6. MapInstance")
        print("7. PlayedOn")
        print("8. Coach")
        print("9. Personnel")
        print("10. Stats")

        table = int(input("Choice: "))
        
        if table == 1:
            key = input("PlayerID: ")
            c.execute("DELETE FROM Player WHERE PlayerID = ?", (key,))
            c.execute("DELETE FROM PlayersTeam WHERE PlayerID = ?", (key,))
            c.execute("DELETE FROM Stats WHERE Player = ?", (key,))
            c.execute("DELETE FROM PlayedOn WHERE Player = ?", (key,))

        if table == 2:
            Player = input("PlayerID: ")
            Team = input("TeamID: ")
            c.execute("DELETE FROM PlayersTeam WHERE PlayerID = ? and TeamID = ?", (Player, Team,))

        if table == 3:
            key = input("TeamID: ")
            c.execute("DELETE FROM Team WHERE TeamID = ?", (key,))
            c.execute("DELETE FROM PlayersTeam WHERE TeamID = ?", (key,))
            
        if table == 4:
            key = input("MatchID: ")
            c.execute("DELETE FROM Match WHERE MatchID = ?", (key,))
            c.execute("DELETE FROM MapInstance WHERE MatchID = ?", (key,))

        if table == 5:
            key = input("Map Name: ")
            c.execute("DELETE FROM Map WHERE Name = ?", (key,))

        if table == 6:
            Match = input("MatchID: ")
            Map = input("MapID: ")
            c.execute("DELETE FROM MapInstance WHERE Number = ? and MatchID = ?", (Map, Match,))

        if table == 7:
            Match = input("MatchID: ")
            Map = input("MapNumber: ")
            Hero = input("Hero: ")
            Player = input("PlayerID: ")
            c.execute("DELETE FROM PlayedOn WHERE MatchID = ? and MapNumber = ? and Hero = ? and Player = ?", (Match, Map, Hero, Player))

        if table == 8:
            key = input("CoachID: ")
            c.execute("DELETE FROM Coach WHERE CoachID = ?", (key,))

        if table == 9:
            key = input("StageName: ")
            c.execute("DELETE FROM Personnel WHERE StageName = ?", (key,))

        if table == 10:
            Player = input("PlayerID: ")
            Hero = input("Hero: ")
            c.execute("DELETE FROM Stats WHERE Player = ? and Hero = ?", (Player, Hero,))

    db.commit()

db.close()