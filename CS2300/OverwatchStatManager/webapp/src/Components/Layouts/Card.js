import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from '@material-ui/core/styles';
import Card from '@material-ui/core/Card';
import CardActionArea from '@material-ui/core/CardActionArea';
import CardActions from '@material-ui/core/CardActions';
import CardContent from '@material-ui/core/CardContent';
import CardMedia from '@material-ui/core/CardMedia';
import Button from '@material-ui/core/Button';
import Typography from '@material-ui/core/Typography';
import Grid from '@material-ui/core/Grid'

const styles = {
  card: {
    width: 200,
    maxHeight: 150,
  },
  media: {
    height: 300
  },
};

function MediaCard(props) {
  return (
    <Card className={props.card} root={styles.card}>
      <CardActionArea>
        <CardMedia
          className={props.media}
          image={props.player.Picture}
          title={props.player.Name}
          style={styles.media}
        />
        <CardContent style={styles.card}>
          <Grid>
            <Typography gutterBottom variant="h5" component="h2">
              {props.player.Name}
            </Typography>
            <Typography gutterBottom variant="subheading" component="h2">
              {props.player.Role.charAt(0).toUpperCase() + props.player.Role.substr(1)}
            </Typography>
          </Grid>

          <Typography component="p">
            {props.player.Team}
          </Typography>
        </CardContent>
      </CardActionArea>
      {/*<CardActions>
        <Button size="small" color="primary">
          Share
        </Button>
        <Button size="small" color="primary">
          Learn More
        </Button>
      </CardActions>*/}
    </Card>
  );
}

MediaCard.propTypes = {
  props: PropTypes.object.isRequired,
};

export default withStyles(styles)(MediaCard);
