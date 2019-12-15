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
  LightenDarkenColor(col, amt) {

    var usePound = false;

    if (col[0] == "#") {
        col = col.slice(1);
        usePound = true;
    }

    var num = parseInt(col,16);

    var r = (num >> 16) + amt;

    if (r > 255) r = 255;
    else if  (r < 0) r = 0;

    var b = ((num >> 8) & 0x00FF) + amt;

    if (b > 255) b = 255;
    else if  (b < 0) b = 0;

    var g = (num & 0x0000FF) + amt;

    if (g > 255) g = 255;
    else if (g < 0) g = 0;

    return (usePound?"#":"") + (g | (b << 8) | (r << 16)).toString(16);

}
  getColor(winner, team) {

    this.state.col1 = this.LightenDarkenColor('#' + this.props.bg1, 40)
    this.state.col2 = this.LightenDarkenColor('#' + this.props.bg2, 40)
    console.log(this.state.col1)
    console.log(this.state.col2)
    if (winner===team)
    {
      return { background: this.state.col1}
    }
    return { background: this.state.col2}
  }
  state = {
    hs: [],
    playerstats: [],
    col1: "#000",
    col2: "#000",
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
              return (
                <TableRow onClick={() => {this.props.topChange(null,4, row.MatchID)}} key={row.id} style={{...this.getColor(row.Winner, (row.Team1Name===this.props.team ? row.Team1ID : row.TeamID))}}>
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
