import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from '@material-ui/core/styles';
import Table from '@material-ui/core/Table';
import TableBody from '@material-ui/core/TableBody';
import TableCell from '@material-ui/core/TableCell';
import TableHead from '@material-ui/core/TableHead';
import TableRow from '@material-ui/core/TableRow';
import Paper from '@material-ui/core/Paper';
import CardMedia from '@material-ui/core/CardMedia';

const styles = theme => ({
  root: {
    width: '100%',
    height: 300,
    marginTop: theme.spacing.unit * 3,
    overflowY: 'auto',
  },
  table: {
    minWidth: 700,
    maxHeight: 300,
    overflow: 'auto'
  },
  paper: {
    height: 300,
    width: '100%',
    marginTop: theme.spacing.unit * 3,
    overflow: 'auto',
  },
});

let id = 0;
function createData(hero, elims, deaths, damage, healing, time) {
  id += 1;
  return { id, hero, elims, deaths, damage, healing, time };
}

let rows = [
  createData('Winston', 356, 16.0, 49, 3.9, 345),
  createData('Reinhardt', 237, 9.0, 37, 4.3, 304),
  createData('Orisa', 305, 3.7, 67, 4.3, 205),
  createData('Roadhog', 262, 16.0, 24, 6.0, 30),
  createData('Wrecking Ball', 305, 3.7, 67, 4.3, 25),
  createData('Brigitte', 305, 3.7, 67, 4.3, 4),
];

class TeamTable extends React.Component {
  constructor(props) {
    super(props);
  }
  getColor(winner, team) {
    console.log("TEST")
    console.log(winner)
    console.log(team)
    if (winner===team)
    {
      return { background: "#69f0ae"}
    }
    return { background: "#ff5252"}
  }
  state = {
    hs: [],
    playerstats: [],

    };
  componentDidMount() {
    console.log("MOUNTED")
  }
  updateStats() {
    this.state.playerstats = this.state.hs.map(team => (createData(team.Hero, 1,2,3,4, 0)));
  }
  render() {
    return (
      <Paper className={this.props.root}>
        <Table className={this.props.table}>
          <TableHead>
            <TableRow>
              <TableCell></TableCell>
              <TableCell>Team 1</TableCell>
              <TableCell>Score</TableCell>
              <TableCell>Date</TableCell>
              <TableCell>Team 2</TableCell>
              <TableCell></TableCell>
            </TableRow>
          </TableHead>
          <TableBody>
            {this.props.ms.map(row => {
              console.log(row)
              console.log(row.Team1Name)
              console.log(this.props.team)
              return (
                <TableRow key={row.id} style={{...this.getColor(row.Winner, (row.Team1Name===this.props.team ? row.Team1ID : row.TeamID))}}>
                  <TableCell numeric><img height={60} width={60} src={row.Team1Logo}/></TableCell>
                  <TableCell>{row.Team1Name}</TableCell>
                  <TableCell>{row.Score}</TableCell>
                  <TableCell>{row.Time}</TableCell>
                  <TableCell>{row.Name}</TableCell>
                  <TableCell numeric><img height={60} width={60} src={row.Logo}/></TableCell>
                </TableRow>
              );
            })}
          </TableBody>
        </Table>
      </Paper>
    );
  }
}

TeamTable.propTypes = {
    props: PropTypes.object.isRequired,
};

export default withStyles(styles)(TeamTable);
