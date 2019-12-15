import React, { Fragment } from 'react';
import { withStyles } from '@material-ui/core/styles';
import Card from '@material-ui/core/Card';
import CardActionArea from '@material-ui/core/CardActionArea';
import CardMedia from '@material-ui/core/CardMedia';
import onered from './onered.png';
import Grid from '@material-ui/core/Grid';
import UnoCard from './Card';
import { DndProvider } from 'react-dnd'
import HTML5Backend from 'react-dnd-html5-backend'

const styles = {
  card: {
    height: 295,
    width: 198,
  },
  media: {
    width: 200,
    height: 200,
  },
};



class PlayerHand extends React.Component {

  render() {
    return(
      <Fragment>
      <DndProvider backend={HTML5Backend}><UnoCard/></DndProvider>

      <Grid container spacing={1}>
        <Grid item>
        <Card className={styles.card}>
          <CardActionArea>
            <CardMedia
              className={styles.media}
              component="img"
              image={onered}
              title="Name"
              height="390"
              width="198"
            />
          </CardActionArea>
        </Card>
        </Grid>
        <Grid item >
        <Card className={styles.card}>
          <CardActionArea>
            <CardMedia
              className={styles.media}
              component="img"
              image={onered}
              title="Name"
              height="390"
              width="198"
            />
          </CardActionArea>
        </Card>
        </Grid>
      </Grid>
      </Fragment>
    )
  }
}
export default withStyles(styles)(PlayerHand);
