import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from '@material-ui/core/styles';
import AppBar from '@material-ui/core/AppBar';
import Tabs from '@material-ui/core/Tabs';
import Tab from '@material-ui/core/Tab';
import Typography from '@material-ui/core/Typography';
import Grid from '@material-ui/core/Grid'
import MatchInfo from './MatchInfo'
import MiniCard from '../MiniCard'
import MapStats from './MapStats'

function TabContainer(props) {
  return (
    <Typography component="div" style={{ padding: 8 * 3 }}>
      {props.children}
    </Typography>
  );
}

TabContainer.propTypes = {
  children: PropTypes.node.isRequired,
};

function LinkTab(props) {
  return <Tab component="a" onClick={event => event.preventDefault()} {...props} />;
}

const styles = theme => ({
  root: {
    flexGrow: 1,
    width: 'auto',
    float: 'none',
    marginLeft: theme.spacing.unit*8,
    marginRight: theme.spacing.unit*8,
  },
  tabsRoot: {
    borderBottom: '1px solid #e8e8e8',
  },
  tabsIndicator: {
    backgroundColor: '#1890ff',
  },
  tabRoot: {
    textTransform: 'initial',
    minWidth: 72,
    fontWeight: theme.typography.fontWeightRegular,
    marginRight: theme.spacing.unit * 4,
    fontFamily: [
      '-apple-system',
      'BlinkMacSystemFont',
      '"Segoe UI"',
      'Roboto',
      '"Helvetica Neue"',
      'Arial',
      'sans-serif',
      '"Apple Color Emoji"',
      '"Segoe UI Emoji"',
      '"Segoe UI Symbol"',
    ].join(','),
    '&:hover': {
      color: '#40a9ff',
      opacity: 1,
    },
    '&$tabSelected': {
      color: '#1890ff',
      fontWeight: theme.typography.fontWeightMedium,
    },
    '&:focus': {
      color: '#40a9ff',
    },
  },
  tabSelected: {},
});

const port = process.env.PORT || process.env.OPENSHIFT_NODEJS_PORT || 8080

class NavTabs extends React.Component {
  constructor(props) {
      super(props)
      this.getMatchStats(this.props.match);
      this.state = {
          value: 0,
          match: "10233",
          map1: {},
          map2: {},
          map3: {},
          map4: {},
          map5: {},
          mapname1: "",
          mapname2: "",
          mapname3: "",
          mapname4: "",
          mapname5: "",
          team1: "",
      };

  }

  getMatchStats = (matchid) => {
    fetch(`http://localhost:${port}/matches/match?match=${matchid}`)
    .then(response => response.json())
    .then(response => this.setState({ ms: response.data[0]}, this.getTeams(response.data[0].Team1, response.data[0].Team2)))
    .catch(err => console.error(err))
    fetch(`http://localhost:${port}/matches/match/1?match=${matchid}`)
    .then(response => response.json())
    .then(response => this.setState({ map1: response.data}))
    .catch(err => console.error(err))
    fetch(`http://localhost:${port}/matches/match/2?match=${matchid}`)
    .then(response => response.json())
    .then(response => this.setState({ map2: response.data}))
    .catch(err => console.error(err))
    fetch(`http://localhost:${port}/matches/match/3?match=${matchid}`)
    .then(response => response.json())
    .then(response => this.setState({ map3: response.data}))
    .catch(err => console.error(err))
    fetch(`http://localhost:${port}/matches/match/4?match=${matchid}`)
    .then(response => response.json())
    .then(response => this.setState({ map4: response.data}))
    .catch(err => console.error(err))
    fetch(`http://localhost:${port}/matches/match/5?match=${matchid}`)
    .then(response => response.json())
    .then(response => this.setState({ map5: response.data}))
    .catch(err => console.error(err))
  }

  handleChange = (event, value, match=10233) => {
    this.setState({ value, match });
  };
  mapupdate = _ => {
    if (this.state.map1[0] != undefined) {
      this.state.mapname1 = this.state.map1[0].Name
    }
    if (this.state.map2[0] != undefined) {
      this.state.mapname2 = this.state.map2[0].Name
    }
    if (this.state.map3[0] != undefined) {
      this.state.mapname3 = this.state.map3[0].Name
    }
    if (this.state.map4[0] != undefined) {
      this.state.mapname4 = this.state.map4[0].Name
    }
    if (this.state.map5[0] != undefined) {
      this.state.mapname5 = this.state.map5[0].Name
    }
  }
  map1 = _ => {
    if (this.state.map1[0] != undefined) {
      this.state.mapname1 = this.state.map1[0].Name
      var team = {}
      this.state.team1 = this.state.map1[0].Team1
      for (var index in this.state.map1) {
        team[this.state.map1[index].Player] = []
      }
      for (var index in this.state.map1) {
        var isIn = false
        for (var stuff in team[this.state.map1[index].Player]){
          console.log(team[this.state.map1[index].Player][stuff])
          if (team[this.state.map1[index].Player][stuff].Hero === this.state.map1[index].Hero) {
            isIn = true
          }
        }
        if (!isIn) {
          team[this.state.map1[index].Player].push(this.state.map1[index]);
        }
      }


    return <Grid container justify="center" alignItems="top" spacing={16} direction="row"><Grid item xs={6}>{Object.keys(team).map(item => {
      if (team[item][0]['TeamID'] === this.state.team1){
          return <Grid item>
                    <Grid container justify="left" alignItems="center" spacing={16} direction="row">
                        <Grid item>
                          <MiniCard player={team[item][0]} />
                        </Grid>
                        <Grid item>
                          <MapStats hs={team[item]}/>
                        </Grid>
                    </Grid>
                  </Grid>}
      })}</Grid><Grid item xs={6}>{Object.keys(team).map(item => {
        console.log(team[item])
        if (team[item][0]['TeamID'] != this.state.team1){
            return <Grid item>
                      <Grid container justify="left" alignItems="center" spacing={16} direction="row">
                          <Grid item>
                            <MiniCard player={team[item][0]} />
                          </Grid>
                          <Grid item>
                            <MapStats hs={team[item]}/>
                          </Grid>
                      </Grid>
                    </Grid>}

        })}</Grid></Grid>
    }
  }
  map2 = _ => {
    if (this.state.map2[0] != undefined) {
      this.state.mapname2 = this.state.map2[0].Name
      var team = {}
      this.state.team1 = this.state.map2[0].Team1
      for (var index in this.state.map2) {
        team[this.state.map2[index].Player] = []
      }
      for (var index in this.state.map2) {
        var isIn = false
        for (var stuff in team[this.state.map2[index].Player]){
          console.log(team[this.state.map2[index].Player][stuff])
          if (team[this.state.map2[index].Player][stuff].Hero === this.state.map2[index].Hero) {
            isIn = true
          }
        }
        if (!isIn) {
          team[this.state.map2[index].Player].push(this.state.map2[index]);
        }
      }


    return <Grid container justify="center" alignItems="top" spacing={16} direction="row"><Grid item xs={6}>{Object.keys(team).map(item => {
      if (team[item][0]['TeamID'] === this.state.team1){
          return <Grid item>
                    <Grid container justify="left" alignItems="center" spacing={16} direction="row">
                        <Grid item>
                          <MiniCard player={team[item][0]} />
                        </Grid>
                        <Grid item>
                          <MapStats hs={team[item]}/>
                        </Grid>
                    </Grid>
                  </Grid>}
      })}</Grid><Grid item xs={6}>{Object.keys(team).map(item => {
        console.log(team[item])
        if (team[item][0]['TeamID'] != this.state.team1){
            return <Grid item>
                      <Grid container justify="left" alignItems="center" spacing={16} direction="row">
                          <Grid item>
                            <MiniCard player={team[item][0]} />
                          </Grid>
                          <Grid item>
                            <MapStats hs={team[item]}/>
                          </Grid>
                      </Grid>
                    </Grid>}

        })}</Grid></Grid>
    }
  }
  map3 = _ => {
    if (this.state.map3[0] != undefined) {
      this.state.mapname3 = this.state.map3[0].Name
      var team = {}
      this.state.team1 = this.state.map3[0].Team1
      for (var index in this.state.map3) {
        team[this.state.map3[index].Player] = []
      }
      for (var index in this.state.map3) {
        var isIn = false
        for (var stuff in team[this.state.map3[index].Player]){
          console.log(team[this.state.map3[index].Player][stuff])
          if (team[this.state.map3[index].Player][stuff].Hero === this.state.map3[index].Hero) {
            isIn = true
          }
        }
        if (!isIn) {
          team[this.state.map3[index].Player].push(this.state.map3[index]);
        }
      }


    return <Grid container justify="center" alignItems="top" spacing={16} direction="row"><Grid item xs={6}>{Object.keys(team).map(item => {
      if (team[item][0]['TeamID'] === this.state.team1){
          return <Grid item>
                    <Grid container justify="left" alignItems="center" spacing={16} direction="row">
                        <Grid item>
                          <MiniCard player={team[item][0]} />
                        </Grid>
                        <Grid item>
                          <MapStats hs={team[item]}/>
                        </Grid>
                    </Grid>
                  </Grid>}
      })}</Grid><Grid item xs={6}>{Object.keys(team).map(item => {
        console.log(team[item])
        if (team[item][0]['TeamID'] != this.state.team1){
            return <Grid item>
                      <Grid container justify="left" alignItems="center" spacing={16} direction="row">
                          <Grid item>
                            <MiniCard player={team[item][0]} />
                          </Grid>
                          <Grid item>
                            <MapStats hs={team[item]}/>
                          </Grid>
                      </Grid>
                    </Grid>}

        })}</Grid></Grid>
    }
  }
  map4 = _ => {
    if (this.state.map4[0] != undefined) {
      this.state.mapname4 = this.state.map4[0].Name
      var team = {}
      this.state.team1 = this.state.map4[0].Team1
      for (var index in this.state.map4) {
        team[this.state.map4[index].Player] = []
      }
      for (var index in this.state.map4) {
        var isIn = false
        for (var stuff in team[this.state.map4[index].Player]){
          console.log(team[this.state.map4[index].Player][stuff])
          if (team[this.state.map4[index].Player][stuff].Hero === this.state.map4[index].Hero) {
            isIn = true
          }
        }
        if (!isIn) {
          team[this.state.map4[index].Player].push(this.state.map4[index]);
        }
      }


    return <Grid container justify="center" alignItems="top" spacing={16} direction="row"><Grid item xs={6}>{Object.keys(team).map(item => {
      if (team[item][0]['TeamID'] === this.state.team1){
          return <Grid item>
                    <Grid container justify="left" alignItems="center" spacing={16} direction="row">
                        <Grid item>
                          <MiniCard player={team[item][0]} />
                        </Grid>
                        <Grid item>
                          <MapStats hs={team[item]}/>
                        </Grid>
                    </Grid>
                  </Grid>}
      })}</Grid><Grid item xs={6}>{Object.keys(team).map(item => {
        console.log(team[item])
        if (team[item][0]['TeamID'] != this.state.team1){
            return <Grid item>
                      <Grid container justify="left" alignItems="center" spacing={16} direction="row">
                          <Grid item>
                            <MiniCard player={team[item][0]} />
                          </Grid>
                          <Grid item>
                            <MapStats hs={team[item]}/>
                          </Grid>
                      </Grid>
                    </Grid>}

        })}</Grid></Grid>
    }
  }
  map5 = _ => {
    if (this.state.map5[0] != undefined) {
      this.state.mapname5 = this.state.map5[0].Name
      var team = {}
      this.state.team1 = this.state.map5[0].Team1
      for (var index in this.state.map5) {
        team[this.state.map1[index].Player] = []
      }
      for (var index in this.state.map5) {
        var isIn = false
        for (var stuff in team[this.state.map5[index].Player]){
          console.log(team[this.state.map5[index].Player][stuff])
          if (team[this.state.map5[index].Player][stuff].Hero === this.state.map5[index].Hero) {
            isIn = true
          }
        }
        if (!isIn) {
          team[this.state.map5[index].Player].push(this.state.map5[index]);
        }
      }


    return <Grid container justify="center" alignItems="top" spacing={16} direction="row"><Grid item xs={6}>{Object.keys(team).map(item => {
      if (team[item][0]['TeamID'] === this.state.team1){
          return <Grid item>
                    <Grid container justify="left" alignItems="center" spacing={16} direction="row">
                        <Grid item>
                          <MiniCard player={team[item][0]} />
                        </Grid>
                        <Grid item>
                          <MapStats hs={team[item]}/>
                        </Grid>
                    </Grid>
                  </Grid>}
      })}</Grid><Grid item xs={6}>{Object.keys(team).map(item => {
        console.log(team[item])
        if (team[item][0]['TeamID'] != this.state.team1){
            return <Grid item>
                      <Grid container justify="left" alignItems="center" spacing={16} direction="row">
                          <Grid item>
                            <MiniCard player={team[item][0]} />
                          </Grid>
                          <Grid item>
                            <MapStats hs={team[item]}/>
                          </Grid>
                      </Grid>
                    </Grid>}

        })}</Grid></Grid>
    }
  }
  map5nav = _ => {
      if (this.state.map5[0] != undefined) {
        return <LinkTab label={this.state.mapname5} href="page6" />
      }
      return
  }

  render() {
    const { classes } = this.props;
    const { value } = this.state;
    console.log(this.state.match)
    return (
      <div className={classes.root}>
          <Tabs classes={{ root: classes.tabsRoot, indicator: classes.tabsIndicator }} borderBottom='1px solid #e8e8e8' fullWidth value={value} onChange={this.handleChange}>
            <LinkTab label="Overview" href="page1" />
            <LinkTab label={this.state.mapname1} href="page2" />
            <LinkTab label={this.state.mapname2} href="page3" />
            <LinkTab label={this.state.mapname3} href="page4" />
            <LinkTab label={this.state.mapname4} href="page5" />
            {this.map5nav()}

          </Tabs>
        {value === 0 &&
        <TabContainer>
          {this.mapupdate()}
          <MatchInfo team1={this.props.t1} team2={this.props.t2} map1={this.state.map1} map2={this.state.map2} map3={this.state.map3} map4={this.state.map4} map5={this.state.map5}/>
        </TabContainer>}
        {value === 1 &&
        <TabContainer>
          {this.map1()}
        </TabContainer>}
        {value === 2 &&
        <TabContainer>
          {this.map2()}
        </TabContainer>}
        {value === 3 &&
        <TabContainer>
          {this.map3()}
        </TabContainer>}
        {value === 4 &&
        <TabContainer>
          {this.map4()}
        </TabContainer>}
        {value === 5 &&
        <TabContainer>
          {this.map5()}
        </TabContainer>}
      </div>
    );
  }
}

NavTabs.propTypes = {
    props: PropTypes.object.isRequired,
};

export default withStyles(styles)(NavTabs);
