import React from 'react';
import { makeStyles } from '@material-ui/core/styles';
import Card from '@material-ui/core/Card';
import CardActionArea from '@material-ui/core/CardActionArea';
import CardMedia from '@material-ui/core/CardMedia';
import onered from './onered.png'
import { useDrop } from 'react-dnd'
import { DragTypes } from './Card'
import { DndProvider } from 'react-dnd'
import HTML5Backend from 'react-dnd-html5-backend'

const useStyles = makeStyles({
  card: {
    height: 295,
    width: 198,
  },
  media: {
    width: 200,
  },
});


export default function Deck() {
  const classes = useStyles();
  const [{ isOver }, drop] = useDrop({
		accept: DragTypes.CARD,
    drop: () => console.log("THIS"),
		collect: monitor => ({
			isOver: !!monitor.isOver(),
		}),
  })


  return (
    <div>
    <Card className={classes.card}>
      <CardActionArea>
        <CardMedia
          className={classes.media}
          component="img"
          image={onered}
          title="Name"
        />
      </CardActionArea>
    </Card>
    {isOver && (
        <div
          style={{
            position: 'absolute',
            top: 0,
            left: 0,
            height: '100%',
            width: '100%',
            zIndex: 1,
            opacity: 0.5,
            backgroundColor: 'yellow',
          }}
        />
      )}
      </div>
  );
}
