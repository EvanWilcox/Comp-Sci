import React, { Fragment, Component } from 'react'
import { withStyles } from '@material-ui/core/styles';
import Grid from '@material-ui/core/Grid'
import Card from '../Card'
import PlayerStats from "./PlayerStats"
import TextField from '@material-ui/core/TextField'
import AutoComplete from './AutoComplete';


const styles = {
    card: {
      padding: 20,
    }
  };

const port = process.env.PORT || process.env.OPENSHIFT_NODEJS_PORT || 8080

class ComparePlayers extends Component {
    constructor(props) {
        super(props);
        this.state = {
            value: '{label:Muma, value:Muma}',
            value2: '{label:sinatraa, value:sinatraa}',
            players: [],
            player1: "Muma",
            player2: "sinatraa",
            hero: "Tracer",
            hs: [],
        };

        this.handleChange1 = this.handleChange1.bind(this);
        this.handleChange2 = this.handleChange2.bind(this);
      }


    componentDidMount() {
        this.getPlayers()
      }

    getPlayers = _ => {
        fetch(`http://localhost:${port}/players`)
        .then(response => response.json())
        .then(response => this.setState({ players: response.data}))
        .catch(err => console.error(err))
      }

      handleChange1(val) {
        this.setState({value: val}, this.getPlayerStats(val.value, this.state.value2.label));
      }

      handleChange2(val) {
        this.setState({value2: val}, this.getPlayerStats(this.state.value.label, val.value));
      }
      getPlayerStats = (val1, val2) => {
        console.log(val1)
        console.log(val2)
        fetch(`http://localhost:${port}/cmpplayer?player1=${val1}&player2=${val2}`)
        .then(response => response.json())
        .then(response => this.setState({hs: response.data}))
        .catch(err => console.error(err))
      }
    render() {
        return (
            <Fragment>
                <Grid container justify="center" alignItems="top" spacing={16}>
                    <Grid item>
                    <AutoComplete
                        id="Player"
                        defaultValue={this.state.player1}
                        value={this.state.value}
                        onChange={this.handleChange1}
                        />
                    {this.state.players.map((item, index) => {
                        if(item.Name === this.state.value.value) {
                            return <Card key={1} player={item}>{JSON.stringify(item)}</Card>
                        }
                    })}
                    </Grid>
                    <Grid item>
                    <AutoComplete
                        id="Player2"
                        defaultValue={this.state.player2}
                        value={this.state.value2}
                        onChange={this.handleChange2}
                        />
                    {this.state.players.map((item, index) => {
                        if(item.Name === this.state.value2.value) {
                            return <Card key={1} player={item}>{JSON.stringify(item)}</Card>
                        }
                    })}
                    </Grid>
                    <Grid item justify="center">

                    <PlayerStats hs={this.state.hs} player1={this.state.value.value} player2={this.state.value2.value}/>
                    </Grid>


                </Grid>
            </Fragment>
        );
    }
}

export default withStyles(styles)(ComparePlayers);
