import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from '@material-ui/core/styles';
import Table from '@material-ui/core/Table';
import TableBody from '@material-ui/core/TableBody';
import TableCell from '@material-ui/core/TableCell';
import TableHead from '@material-ui/core/TableHead';
import TableRow from '@material-ui/core/TableRow';
import Paper from '@material-ui/core/Paper';
import { Typography } from '@material-ui/core';

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

class MatchInfo extends React.Component {
  constructor(props) {
    super(props);
  }
  state = {
    hs: [],
    playerstats: [],

  };

  map1row = _ => {
    console.log("HEERE")
    console.log(this.props.map1)
    if (this.props.map1[0] != undefined) {

        return (<TableRow hover={true}>
                    <TableCell numeric><img height={60} width={60} src={this.props.team1['Logo']}></img></TableCell>
                    <TableCell numeric><Typography variant="h5">{this.props.team1['Name']}</Typography></TableCell>
                    <TableCell numeric><Typography variant="h4">{this.props.map1[0].Score.charAt(0)}</Typography></TableCell>
                    <TableCell><Typography variant="h5">{this.props.map1[0].Name}</Typography></TableCell>
                    <TableCell numeric><Typography variant="h4">{this.props.map1[0].Score.charAt(4)}</Typography></TableCell>
                    <TableCell numeric><Typography variant="h5">{this.props.team2['Name']}</Typography></TableCell>
                    <TableCell numeric><img height={60} width={60} src={this.props.team2['Logo']}></img></TableCell>
                </TableRow>
              )
    }

  }

  map2row = _ => {
    console.log("HEERE")
    console.log(this.props.map2)
    if (this.props.map2[0] != undefined) {

        return (<TableRow hover={true}>
                    <TableCell numeric><img height={60} width={60} src={this.props.team1['Logo']}></img></TableCell>
                    <TableCell numeric><Typography variant="h5">{this.props.team1['Name']}</Typography></TableCell>
                    <TableCell numeric><Typography variant="h4">{this.props.map2[0].Score.charAt(0)}</Typography></TableCell>
                    <TableCell><Typography variant="h5">{this.props.map2[0].Name}</Typography></TableCell>
                    <TableCell numeric><Typography variant="h4">{this.props.map2[0].Score.charAt(4)}</Typography></TableCell>
                    <TableCell numeric><Typography variant="h5">{this.props.team2['Name']}</Typography></TableCell>
                    <TableCell numeric><img height={60} width={60} src={this.props.team2['Logo']}></img></TableCell>
                </TableRow>
              )
    }

  }

  map3row = _ => {
    console.log("HEERE")
    console.log(this.props.map3)
    if (this.props.map3[0] != undefined) {

        return (<TableRow hover={true}>
                    <TableCell numeric><img height={60} width={60} src={this.props.team1['Logo']}></img></TableCell>
                    <TableCell numeric><Typography variant="h5">{this.props.team1['Name']}</Typography></TableCell>
                    <TableCell numeric><Typography variant="h4">{this.props.map3[0].Score.charAt(0)}</Typography></TableCell>
                    <TableCell><Typography variant="h5">{this.props.map3[0].Name}</Typography></TableCell>
                    <TableCell numeric><Typography variant="h4">{this.props.map3[0].Score.charAt(4)}</Typography></TableCell>
                    <TableCell numeric><Typography variant="h5">{this.props.team2['Name']}</Typography></TableCell>
                    <TableCell numeric><img height={60} width={60} src={this.props.team2['Logo']}></img></TableCell>
                </TableRow>
              )
    }

  }

  map4row = _ => {
    console.log("HEERE")
    console.log(this.props.map4)
    if (this.props.map4[0] != undefined) {

        return (<TableRow hover={true}>
                    <TableCell numeric><img height={60} width={60} src={this.props.team1['Logo']}></img></TableCell>
                    <TableCell numeric><Typography variant="h5">{this.props.team1['Name']}</Typography></TableCell>
                    <TableCell numeric><Typography variant="h4">{this.props.map4[0].Score.charAt(0)}</Typography></TableCell>
                    <TableCell><Typography variant="h5">{this.props.map4[0].Name}</Typography></TableCell>
                    <TableCell numeric><Typography variant="h4">{this.props.map4[0].Score.charAt(4)}</Typography></TableCell>
                    <TableCell numeric><Typography variant="h5">{this.props.team2['Name']}</Typography></TableCell>
                    <TableCell numeric><img height={60} width={60} src={this.props.team2['Logo']}></img></TableCell>
                </TableRow>
              )
    }

  }
  map5row = _ => {
    console.log("HEERE")
    console.log(this.props.map5)
    if (this.props.map5[0] != undefined) {

        return (<TableRow hover={true}>
                    <TableCell numeric><img height={60} width={60} src={this.props.team1['Logo']}></img></TableCell>
                    <TableCell numeric><Typography variant="h5">{this.props.team1['Name']}</Typography></TableCell>
                    <TableCell numeric><Typography variant="h4">{this.props.map5[0].Score.charAt(0)}</Typography></TableCell>
                    <TableCell><Typography variant="h5">{this.props.map5[0].Name}</Typography></TableCell>
                    <TableCell numeric><Typography variant="h4">{this.props.map5[0].Score.charAt(4)}</Typography></TableCell>
                    <TableCell numeric><Typography variant="h5">{this.props.team2['Name']}</Typography></TableCell>
                    <TableCell numeric><img height={60} width={60} src={this.props.team2['Logo']}></img></TableCell>
                </TableRow>
              )
    }

  }

  render() {
    return (
      <Paper className={this.props.root}>
        <Table className={this.props.table}>
          <TableBody>
            {this.map1row()}
            {this.map2row()}
            {this.map3row()}
            {this.map4row()}
            {this.map5row()}
          </TableBody>
        </Table>
      </Paper>
    );
  }
}

MatchInfo.propTypes = {
    props: PropTypes.object.isRequired,
};

export default withStyles(styles)(MatchInfo);
