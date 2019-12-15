import React, { Fragment } from 'react';
import Deck from './Deck'
import { withStyles } from '@material-ui/core/styles';
import { DndProvider } from 'react-dnd'
import HTML5Backend from 'react-dnd-html5-backend'
const styles = {

};

class PlayArea extends React.Component {

  render() {
    return(
      <Fragment>
      <DndProvider backend={HTML5Backend}>
        <Deck/>
        </DndProvider>
      </Fragment>
    )
  }
}
export default withStyles(styles)(PlayArea);
