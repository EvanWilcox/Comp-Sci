import React, { Fragment } from 'react';
import List from '@material-ui/core/List'
import ListItem from '@material-ui/core/ListItem'
import { withStyles } from '@material-ui/core/styles';

const styles = theme => ({

})
class PlayerList extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
      players: ["Andrew", "Blake", "James", "Evan", "Tyler", "Matt"]
    };

  }
  render() {
    return (
      <Fragment>
        <List component="nav">
          {this.state.players.map(player => <ListItem button>{player}</ListItem>)}
        </List>
      </Fragment>
    )
  }
}
export default withStyles(styles)(PlayerList);
