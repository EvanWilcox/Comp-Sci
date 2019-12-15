import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from '@material-ui/core/styles';
import Table from '@material-ui/core/Table';
import TableBody from '@material-ui/core/TableBody';
import TableCell from '@material-ui/core/TableCell';
import TableHead from '@material-ui/core/TableHead';
import TableRow from '@material-ui/core/TableRow';
import Paper from '@material-ui/core/Paper';

const styles = theme => ({
  root: {
    width: '100%',
    height: 300,
    marginTop: theme.spacing.unit * 3,
    overflowY: 'auto',
  },
  table: {
    minWidth: 500,
    maxHeight: 300,
    overflow: 'auto',
    tableLayout: 'auto'
  },
  paper: {
    height: 300,
    width: '100%',
    marginTop: theme.spacing.unit * 3,
    overflow: 'auto',
  },
});

class MapStats extends React.Component {
  constructor(props) {
  super(props)
  }

  state = {
    hs: [],
    playerstats: [],

  };


  render() {
    return (
      <Paper className={this.props.root}>
        <Table className={this.props.table} style={{width: 10}}>
          <TableHead style={{width: 'auto !important'}}>
            <TableRow style={{width: 'auto !important'}}>
              <TableCell style={{width: 'auto !important'}}>Hero</TableCell>
              <TableCell style={{width: 'auto !important'}}>Elims</TableCell>
              <TableCell style={{width: 'auto !important'}}>Deaths</TableCell>
              <TableCell style={{width: 'auto !important'}}>Damage</TableCell>
              <TableCell style={{width: 'auto !important'}}>Healing</TableCell>
            </TableRow>
          </TableHead>
          <TableBody>
            {this.props.hs.map(row => {
              if ( !(row.Eliminations === 0 & row.Deaths === 0 & row.Damage === 0 & row.Healing === 0))
              return (
                <TableRow hover={true} key={row.id} style={{width: 'auto !important'}}>
                  <TableCell component="th" scope="row" style={{width: 10}}>
                    {row.Hero.charAt(0).toUpperCase() + row.Hero.substr(1)}
                  </TableCell>
                  <TableCell style={{ width: 'auto !important' }}>{row.Eliminations.toFixed(2)}</TableCell>
                  <TableCell style={{width: 'auto !important'}}>{row.Deaths.toFixed(2)}</TableCell>
                  <TableCell style={{width: 'auto !important'}}>{row.Damage.toFixed(2)}</TableCell>
                  <TableCell style={{width: 'auto !important'}}>{row.Healing.toFixed(2)}</TableCell>
                </TableRow>
              );
            })}
          </TableBody>
        </Table>
      </Paper>
    );
  }
}

MapStats.propTypes = {
    props: PropTypes.object.isRequired,
};

export default withStyles(styles)(MapStats);
