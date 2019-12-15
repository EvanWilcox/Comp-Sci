import React from 'react'
import { useDrag } from 'react-dnd'
import Card from '@material-ui/core/Card';
import CardActionArea from '@material-ui/core/CardActionArea';
import CardMedia from '@material-ui/core/CardMedia';
import onered from './onered.png'

export const DragTypes = {
  CARD: 'card',
}
export const styles = {
  card: {
    height: 295,
    width: 198,
  },
  media: {
    width: 200,
    height: 200,
  },
};

function UnoCard() {
  const [{isDragging}, drag] = useDrag({
    item: { type: DragTypes.CARD },
		collect: monitor => ({
			isDragging: !!monitor.isDragging(),
		}),
  })

  return (
    <div
      ref={drag}
      style={{
        opacity: isDragging ? 0.5 : 1,
        fontSize: 25,
        fontWeight: 'bold',
        cursor: 'move',
      }}
    >
    <img src={onered}/>
    </div>
  )
}

export default UnoCard;
