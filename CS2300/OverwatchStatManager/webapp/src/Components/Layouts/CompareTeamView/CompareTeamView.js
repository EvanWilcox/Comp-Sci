import React, { Fragment } from 'react'
import Grid from '@material-ui/core/Grid'
import TeamCard from '../TeamCard'
import TextField from '@material-ui/core/TextField'
import TeamStats from "./TeamStats"
import { Typography } from '@material-ui/core';
import { withStyles } from '@material-ui/core/styles';
import Card from '../Card'
import Paper from '@material-ui/core/Paper';
import AutoComplete from './AutoComplete';


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

class TeamView extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            value: {value:"Houston Outlaws", label:"Houston Outlaws"},
            value2: {value:"Philadelphia Fusion", label:"Philadelphia Fusion"},
            Teams: [],
            Team: "Houston Outlaws",
            Team2: "Philadelphia Fusion",
            t2s: [],
            ts: [],
            ms: [],
            bg1: "#000",
            bg2: "#000"
        };

        this.handleChange1 = this.handleChange1.bind(this);
        this.handleChange2 = this.handleChange2.bind(this);
      }



    componentDidMount() {
        this.getTeams()
        this.state.Teams = this.state.Teams.map(team => ({
            label: team,
            value: team,
        }))

      }

    getTeams = _ => {
        fetch(`http://localhost:${port}/teams`)
        .then(response => response.json())
        .then(response => this.setState({ Teams: response.data}, this.getTeamStats("Houston Outlaws")))
        .then(this.getTeamStats(this.state.Team))
        .then(this.getTeam2Stats(this.state.Team2))
        .catch(err => console.error(err))
      }

      getMatchStats = (val, val2) => {
        fetch(`http://localhost:${port}/stats/cmpmatch?team=${val}&team2=${val2}`)
        .then(response => response.json())
        .then(response => this.setState({ms: response.data}))
        .catch(err => console.error(err))
      }
      getTeamStats = (val) => {
        fetch(`http://localhost:${port}/stats/team?team=${val}`)
        .then(response => response.json())
        .then(response => this.setState({ts: response.data, bg1:response.data[0].PrimaryColor}, this.getMatchStats(val, this.state.value2.value)))
        .catch(err => console.error(err))
      }
      getTeam2Stats = (val) => {
        fetch(`http://localhost:${port}/stats/team?team=${val}`)
        .then(response => response.json())
        .then(response => this.setState({t2s: response.data, bg2:response.data[0].PrimaryColor}, this.getMatchStats(this.state.value.value, val)))
        .catch(err => console.error(err))
      }
      handleChange1(val) {
        this.setState({value: val})
        this.getTeamStats(val.value);
      }
      handleChange2(val) {
        this.setState({value2: val})
        this.getTeam2Stats(val.value);
      }


    render() {

      return (
        <Fragment>
        <div backgroundColor={this.state.bg}>
            <Grid container align="center" alignItems="center" justify="center" spacing={16}>
                <Grid item xs={6} sm>
                    <AutoComplete
                        id="Team"
                        defaultValue={this.state.Team}
                        value={this.state.value}
                        onChange={this.handleChange1}
                        />
                        </Grid>
                  <Grid item xs={6} sm>
                  <AutoComplete
                      id="Team"
                      defaultValue={this.state.Team2}
                      value={this.state.value2}
                      onChange={this.handleChange2}
                      />
                  </Grid>
                    <Grid container align="center" alignItems="center" justify="center" spacing={16}>
                        {this.state.Teams.map((item, index) => {
                          console.log(this.state.value.value)
                        if(item.Name === this.state.value.value) {
                            return <Grid item xs={3} sm={6}><TeamCard key={1} team={item}>{JSON.stringify(item)}</TeamCard></Grid>
                        }
                        })}
                        {this.state.Teams.map((item, index) => {
                          console.log(this.state.value2.value)
                        if(item.Name === this.state.value2.value) {
                            return <Grid item xs={3} sm={6}><TeamCard key={1} team={item}>{JSON.stringify(item)}</TeamCard></Grid>
                        }
                        })}
                      </Grid>
                        <Grid item xs={12} sm={12}>
                          <Paper><Typography variant="h4"> Roster </Typography></Paper>
                        </Grid>
                <Grid container alignItems="top" justify="center" direction="row" spacing={16}>
                <Grid item xs={6}>
                  <Grid container alignItems="center" justify="center" direction="row" spacing={16}>
                    {console.log(this.state.ts)}
                    {this.state.ts.map((item, index) => {
                      return <Grid item><Card player={item} key={index}>{JSON.stringify(item)}</Card></Grid>
                    })}
                  </Grid>
                </Grid>
                <Grid item xs={6}>
                  <Grid container alignItems="center" justify="center" direction="row" spacing={16}>
                    {console.log(this.state.ts)}
                    {this.state.t2s.map((item, index) => {
                      return <Grid item><Card player={item} key={index}>{JSON.stringify(item)}</Card></Grid>
                    })}
                  </Grid>

                </Grid>
                </Grid>
                <Grid item xs={12} sm={12}>
                  <Paper><Typography variant="h4">Matches</Typography></Paper>
                </Grid>
                <Grid item>
                  <TeamStats topChange={this.props.topChange} ms={this.state.ms} team={this.state.value.value} bg1={this.state.bg1} bg2={this.state.bg2}/>
                </Grid>
         </Grid>
         </div>
        </Fragment>
      )
    }
}

export default withStyles(styles)(TeamView);
