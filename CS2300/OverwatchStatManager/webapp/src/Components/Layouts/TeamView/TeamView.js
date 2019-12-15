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
            Teams: [],
            Team: "Houston Outlaws",
            ts: [],
            ms: [],
            bg: "#000"
        };

        this.handleChange = this.handleChange.bind(this);
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
        .catch(err => console.error(err))
      }

      getMatchStats = (val) => {
        fetch(`http://localhost:${port}/stats/match?team=${val}`)
        .then(response => response.json())
        .then(response => this.setState({ms: response.data}))
        .catch(err => console.error(err))
      }
      getTeamStats = (val) => {
        fetch(`http://localhost:${port}/stats/team?team=${val}`)
        .then(response => response.json())
        .then(response => this.setState({ts: response.data, bg:response.data[0].PrimaryColor}, this.getMatchStats(val)))
        .catch(err => console.error(err))
      }
      handleChange(val) {
        this.setState({value: val})
        this.getTeamStats(val.value);
      }


    render() {

      return (
        <Fragment>
        <div backgroundColor={this.state.bg}>
            <Grid container align="center" alignItems="center" justify="center" spacing={16}>
                <Grid item xs={12} sm>
                    <AutoComplete
                        id="Team"
                        defaultValue={this.state.Team}
                        value={this.state.value}
                        onChange={this.handleChange}
                        />
                        </Grid>
                        {this.state.Teams.map((item, index) => {
                          console.log(this.state.value.value)
                        if(item.Name === this.state.value.value) {
                            return <Grid item xs={3} sm={12}><TeamCard key={1} team={item}>{JSON.stringify(item)}</TeamCard></Grid>
                        }
                        })}
                        <Grid item xs={12} sm={12}>
                          <Paper><Typography variant="h4"> Roster </Typography></Paper>
                        </Grid>
                <Grid item>
                  <Grid container alignItems="center" justify="center" direction="row" spacing={16}>
                    {console.log(this.state.ts)}
                    {this.state.ts.map((item, index) => {
                      return <Grid item><Card player={item} key={index}>{JSON.stringify(item)}</Card></Grid>
                    })}
                  </Grid>
                </Grid>
                <Grid item xs={12} sm={12}>
                  <Paper><Typography variant="h4"> Matches </Typography></Paper>
                </Grid>
                <Grid item>
                  <TeamStats ms={this.state.ms} team={this.state.value.value}/>
                </Grid>
         </Grid>
         </div>
        </Fragment>
      )
    }
}

export default withStyles(styles)(TeamView);
