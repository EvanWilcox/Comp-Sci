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
    width: 150,
    maxHeight: 150,
  },
  media: {
    height: 150,
    width: 150,
  },
};
const port = process.env.PORT || process.env.OPENSHIFT_NODEJS_PORT || 8080

class MediaCard extends React.Component {
  constructor(props) {
      super(props);
      this.state = {
          value: {value:"Houston Outlaws", label:"Houston Outlaws"},
          Teams: [],
          Team: "Houston Outlaws",
          ts: [],
          ms: [],
          bg: "#000",
          player: [],
      };
      console.log(this.props.player.PlayerID)
      this.getPlayer(this.props.player.PlayerID)
    }
  getPlayer = (player) => {
      fetch(`http://localhost:${port}/players/player?player=${player}`)
      .then(response => response.json())
      .then(response => this.setState({ player: response.data, playerName: response.data[0].Name}, () => {console.log(this.state.player)}))
      .catch(err => console.error(err))
    }

  render() {
      console.log(this.state.player)
  return (
    <Card className={this.props.card} root={styles.card}>
      <CardActionArea>
        <CardMedia
          className={this.props.media}
          image={this.props.player.Picture}
          title={this.props.player.Name}
          style={styles.media}
        />
        <CardContent style={styles.card}>
          <Grid>
          <Typography gutterBottom variant="subheading" component="h2">
            {this.state.playerName}
          </Typography>
            <Typography gutterBottom variant="subheading" component="h2">
              {this.props.player.Role.charAt(0).toUpperCase() + this.props.player.Role.substr(1)}
            </Typography>
          </Grid>

          <Typography component="p">
            {this.props.player.Team}
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
}


export default withStyles(styles)(MediaCard);
