import React, { Fragment } from 'react';
import PropTypes from 'prop-types';
import { withStyles } from '@material-ui/core/styles';
import Table from '@material-ui/core/Table';
import TableBody from '@material-ui/core/TableBody';
import TableCell from '@material-ui/core/TableCell';
import TableHead from '@material-ui/core/TableHead';
import TableRow from '@material-ui/core/TableRow';
import Paper from '@material-ui/core/Paper';
import Typography from '@material-ui/core/Typography';

const styles = theme => ({
  root: {
    width: '100%',
    marginTop: theme.spacing.unit * 3,
    overflowX: 'auto',
    backgroundColor: theme.palette.common.black,
    head: {
      backgroundColor: theme.palette.common.black,
    },
  },
  table: {
    minWidth: 200,
  },
  row: {
      backgroundColor: '#000',
  },
});

let id = 0;
function createData(stats, player1Stats, player2Stats) {
  id += 1;
  return { id, stats, player1Stats, player2Stats };
}

const rows = [
  createData('Elims', 159, 6.0),
  createData('Deaths', 237, 9.0),
  createData('Damage', 262, 16.0),
  createData('Healing', 305, 3.7),
];

const port = process.env.PORT || process.env.OPENSHIFT_NODEJS_PORT || 8080

class PlayerStats extends React.Component {
  componentDidMount() {
    this.getPlayers()
  }

getPlayers = _ => {
    fetch(`http://localhost:${port}/stats/cmpplayers?player1=${this.props.player1}&player2=${this.props.player2}`)
    .then(response => response.json())
    .then(response => this.setState({ players: response.data}))
    .catch(err => console.error(err))
  }
  render() {
  return (
    <Fragment>
    <Paper className={this.props.root}>
      <Table className={this.props.table}>
        <TableHead>
          <TableRow>
            <TableCell>Hero</TableCell>
            <TableCell>Player</TableCell>
            <TableCell>Damage</TableCell>
            <TableCell>Deaths</TableCell>
            <TableCell>Elims</TableCell>
            <TableCell>Healing</TableCell>
            <TableCell>Ultimates</TableCell>
            <TableCell>FinalBlows</TableCell>
            <TableCell>Time</TableCell>
          </TableRow>
        </TableHead>
        <TableBody>
          {this.props.hs.map(row => {
            return (
              <Fragment>
              <TableRow key={row.id}>
                <TableCell component="th" scope="row">{row.Hero.charAt(0).toUpperCase() + row.Hero.substr(1)}</TableCell>
                <TableCell component="th" scope="row">{this.props.player1}</TableCell>
                <TableCell numeric>{row.P1Damage.toFixed(2)}</TableCell>
                <TableCell numeric>{row.P1Deaths.toFixed(2)}</TableCell>
                <TableCell numeric>{row.P1Elims.toFixed(2)}</TableCell>
                <TableCell numeric>{row.P1Healing.toFixed(2)}</TableCell>
                <TableCell numeric>{row.P1Ultimates.toFixed(2)}</TableCell>
                <TableCell numeric>{row.P1FinalBlows.toFixed(2)}</TableCell>
                <TableCell numeric>{row.P1Time.toFixed(2)}</TableCell>
              </TableRow>
              <TableRow key={row.id}>
                              <TableCell component="th" scope="row"></TableCell>
                <TableCell component="th" scope="row">{this.props.player2}</TableCell>

                <TableCell numeric>{row.P2Damage.toFixed(2)}</TableCell>
                <TableCell numeric>{row.P2Deaths.toFixed(2)}</TableCell>
                <TableCell numeric>{row.P2Elims.toFixed(2)}</TableCell>
                <TableCell numeric>{row.P2Healing.toFixed(2)}</TableCell>
                <TableCell numeric>{row.P2Ultimates.toFixed(2)}</TableCell>
                <TableCell numeric>{row.P2FinalBlows.toFixed(2)}</TableCell>
                <TableCell numeric>{row.P2Time.toFixed(2)}</TableCell>
              </TableRow>
              </Fragment>
            );
          })}
        </TableBody>
      </Table>
    </Paper>
    </Fragment>
  );
 }
}

PlayerStats.propTypes = {
    props: PropTypes.object.isRequired,
};

export default withStyles(styles)(PlayerStats);
