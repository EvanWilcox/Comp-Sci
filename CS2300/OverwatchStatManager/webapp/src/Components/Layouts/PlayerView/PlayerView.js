import React, { Fragment } from 'react'
import Grid from '@material-ui/core/Grid'
import Card from '../Card'
import TextField from '@material-ui/core/TextField'
import HeroStats from "./HeroStats"
import { Typography } from '@material-ui/core';
import { withStyles } from '@material-ui/core/styles';

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

class PlayerView extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            value: '',
            players: [],
            player: "Muma",
            hero: "Tracer",
            hs: [],
            stattable: React.createRef(),
        };

        this.handleChange = this.handleChange.bind(this);
      }



    componentDidMount() {
        this.getPlayers()
        this.state.playerss = this.state.players.map(player => ({
            label: player,
            value: player,
        }))

      }

    getPlayers = _ => {
        fetch(`http://localhost:${port}/players`)
        .then(response => response.json())
        .then(response => this.setState({ players: response.data}))
        .then(this.getHeroStats({value: "Muma", label: "Muma"}))
        .catch(err => console.error(err))
      }
      getHeroStats = (val) => {
        console.log(this.state.value.label)
        fetch(`http://localhost:${port}/herostats/player?player=${val.value}`)
        .then(response => response.json())
        .then(response => this.setState({hs: response.data}))
        .catch(err => console.error(err))
      }
      handleChange(val) {
        console.log(val)
        this.setState({value: val}, this.getHeroStats(val))
        ;
      }


    render() {

      return (
        <Fragment>
            <Grid container justify="center" alignItems="center" spacing={16}>
                <Grid item>
                    <AutoComplete
                        id="Player"
                        defaultValue={this.state.player}
                        value={this.state.value}
                        onChange={this.handleChange}
                        />
                        {this.state.players.map((item, index) => {
                        if(item.Name === this.state.value.value) {
                            return <Card key={1} player={item}>{JSON.stringify(item)}</Card>
                        }
                    })}
                </Grid>
                <Grid item justify="center">
                {console.log(this.state.hs)}
                    <HeroStats ref="stat" hs={this.state.hs} player={this.state} />
                </Grid>
         </Grid>
        </Fragment>
      )
    }
}

export default withStyles(styles)(PlayerView);
