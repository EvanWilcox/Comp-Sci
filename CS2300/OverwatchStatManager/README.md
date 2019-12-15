# Amp! it up Stats.

Amp! it up Stats is a statistics viewer for Blizzard's Overwatch League. 
You can use this program to see stats on individual players, teams, and matches. 
As well as compare players and teams.
This project was made for our Databases Final Project.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

You must install the following things 

```
Node.js 8.12
```

### Installing

In a terminal, clone the repository and move in to the new directory

```
git clone https://github.com/dsaf123/OverwatchStatManager.git
cd OverwatchStatManager
```

Setup and start the database server

```
cd dbapp
npm install
node index.js
```

Open a new terminal and navigate back to the repository.
Setup and start the web server

```
cd webapp
npm install
npm start
```

Navigate in your browser to:

```
localhost:3000
```

### Getting the Data

All data is already stored in `dbapp\owdb.db`. If you would like to regenerate the data just run the following files located in `python-scripts`.

```
player.py
teams.py
maps.py
mapinstance.py
```

### Manually Editing the Data

You can use `console.py` located in `python-scripts` to manually insert, delete or modify the data in the database.

## Built With

* [Node.js](https://nodejs.org/en/) - Javascript runtime environment.
* [React](https://reactjs.org/) - User Interface.

## Authors

* **Andrew Henningsen** - [dsaf123](https://github.com/dsaf123)
* **Evan Wilcox** - [EvanWilcox](https://github.com/EvanWilcox)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
