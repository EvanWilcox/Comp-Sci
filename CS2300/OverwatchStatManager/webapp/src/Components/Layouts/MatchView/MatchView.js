import React, { Fragment } from 'react'
import Grid from '@material-ui/core/Grid'
import Card from '../MiniCard'
import TextField from '@material-ui/core/TextField'
import { Typography } from '@material-ui/core';
import { withStyles } from '@material-ui/core/styles';
import Paper from '@material-ui/core/Paper';
import TeamCard from '../TeamCard'
import NavTabs from './NavTabs'

const styles = theme => ({
    root: {
      flexGrow: 1,
      ...theme.mixins.gutters(),
      paddingTop: theme.spacing.unit * 2,
      paddingBottom: theme.spacing.unit * 2,
    },
    paper: {
      height: 140,
      width: 100,
    },
    control: {
      padding: theme.spacing.unit * 2,
    },
  });

const port = process.env.PORT || process.env.OPENSHIFT_NODEJS_PORT || 8080

class MatchView extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            value: '',
            players: [],
            player: "Muma",
            hero: "Tracer",
            ms: {},
            team1: {},
            team2: {},

        };

        this.handleChange = this.handleChange.bind(this);
      }



    componentDidMount() {
        this.getMatchStats(this.props.match)
      }
      team1 = _ => {
        if (this.state.team1.Division != undefined) {
            return <TeamCard key={1} team={this.state.team1}/>
        }
        return

      }
      team2 = _ => {
        if (this.state.team2.Division != undefined) {
            return <TeamCard key={2} team={this.state.team2}/>
        }
        return

      }
      map1 = _ => {
        if (this.state.map1[0] != undefined) {
          return <Typography variant="h4">{this.state.map1[0].Name}</Typography>
        }
        return
      }
      map2 = _ => {
        if (this.state.map2[0] != undefined) {
          return <Typography variant="h4">{this.state.map2[0].Name}</Typography>
        }
        return
      }
      map3 = _ => {
        if (this.state.map3[0] != undefined) {
          return <Typography variant="h4">{this.state.map3[0].Name}</Typography>
        }
        return
      }
      map4 = _ => {
        if (this.state.map4[0] != undefined) {
          return <Typography variant="h4">{this.state.map4[0].Name}</Typography>
        }
        return
      }
      map5 = _ => {
        if (this.state.map5[0] != undefined) {
          return <Typography variant="h4">{this.state.map5[0].Name}</Typography>
        }
        return
      }
      getPlayerStats = _ => {
        fetch(`http://localhost:${port}/players`)
        .then(response => response.json())
        .then(response => this.setState({ players: response.data}))
        .then(this.getHeroStats())
        .catch(err => console.error(err))
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
      getTeams = (team1, team2) => {
        fetch(`http://localhost:${port}/teams/team?TeamID=${team1}`)
        .then(response => response.json())
        .then(response => this.setState({ team1: response.data[0]}))
        .catch(err => console.error(err))
        fetch(`http://localhost:${port}/teams/team?TeamID=${team2}`)
        .then(response => response.json())
        .then(response => this.setState({ team2: response.data[0]}))
        .catch(err => console.error(err))
      }
      handleChange(val) {
        this.setState({value: val})
        this.getHeroStats(val);
      }


    render() {
      console.log(this.state.team1)
      var team1nn = false;
      var team2nn = false;

      if (this.state.team2 != undefined) {
        team2nn = true;
      }
      console.log(team1nn)
      return (
        <Fragment>

            <Grid container justify="center" alignItems="center" spacing={16}>
                <Grid container justify="center" alignItems="center" spacing={16}>
                  <Grid item>{this.team1()}</Grid>
                  <Grid item>{this.team2()}</Grid>
                </Grid>
                <Grid item><NavTabs t1={this.state.team1} t2={this.state.team2} match={this.props.match} /></Grid>
            </Grid>
        </Fragment>
      )
    }
}

export default withStyles(styles)(MatchView);
