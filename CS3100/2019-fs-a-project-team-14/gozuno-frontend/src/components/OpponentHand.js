import React, { Fragment } from 'react';
import { withStyles } from '@material-ui/core/styles';
import Card from '@material-ui/core/Card';
import CardActionArea from '@material-ui/core/CardActionArea';
import CardMedia from '@material-ui/core/CardMedia';
import onered from './onered.png';
import Grid from '@material-ui/core/Grid';

const styles = {
  card: {
    height: 195,
    width: 18,
  },
  media: {
    width: 20,
    height: 20,
  },
};

class OpponentHand extends React.Component {

  render() {
    return(
      <Fragment>
      <Grid container direction="row" spacing={1}>
        <Grid item xs={2}>
        <Card className={styles.card}>
          <CardActionArea>
            <CardMedia
              className={styles.media}
              component="img"
              image={onered}
              title="Name"
              height="100"
              width="10"
            />
          </CardActionArea>
        </Card>
        </Grid>
        <Grid item xs={2}>
        <Card className={styles.card}>
          <CardActionArea>
            <CardMedia
              className={styles.media}
              component="img"
              image={onered}
              title="Name"
              height="100"
              width="10"
            />
          </CardActionArea>
        </Card>
        </Grid>
        <Grid item xs={2}>
        <Card className={styles.card}>
          <CardActionArea>
            <CardMedia
              className={styles.media}
              component="img"
              image={onered}
              title="Name"
              height="100"
              width="10"
            />
          </CardActionArea>
        </Card>
        </Grid>
        <Grid item xs={2}>
        <Card className={styles.card}>
          <CardActionArea>
            <CardMedia
              className={styles.media}
              component="img"
              image={onered}
              title="Name"
              height="100"
              width="10"
            />
          </CardActionArea>
        </Card>
        </Grid>
        <Grid item xs={2}>
        <Card className={styles.card}>
          <CardActionArea>
            <CardMedia
              className={styles.media}
              component="img"
              image={onered}
              title="Name"
              height="100"
              width="10"
            />
          </CardActionArea>
        </Card>
        </Grid>
      </Grid>
      </Fragment>
    )
  }
}
export default withStyles(styles)(OpponentHand);
