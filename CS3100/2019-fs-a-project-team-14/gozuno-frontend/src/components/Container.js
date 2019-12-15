import React, { useState, useEffect, useCallback } from 'react'
import Pile from './Pile'
import PlayerCard from './Box'
import ItemTypes from './ItemTypes'
import update from 'immutability-helper'
import { Card } from './Game'
import WildDialogue from './wild-dialogue'
import Carousel from 'react-multi-carousel';
import 'react-multi-carousel/lib/styles.css';

function drawClick(socket, myTurn) {
  if (myTurn) {
    socket.emit('play-card', {"action": 0,
                                    "card": null,
                                    "pile": null })
  }
}

const responsive = {
  superLargeDesktop: {
    // the naming can be any, depends on you.
    breakpoint: { max: 4000, min: 3000 },
    items: 5,
  },
  desktop: {
    breakpoint: { max: 2000, min: 1024 },
    items: 8,
  },
  tablet: {
    breakpoint: { max: 1024, min: 464 },
    items: 2,
  },
  mobile: {
    breakpoint: { max: 464, min: 0 },
    items: 1,
  },
};

// Container classunction (class/function) for the piles to play and the player's hand
// Only 1 should be created at a time (most likely)
const Container = (props) => {
  // Array of piles, accepts is required for the Drag and Drop library.
  // setPiles is used to set the topCard variable once the Pile object has actually been added to the Dom
  console.log(props)

  if (props.pilez !== undefined) {
    var pls = props.pilez;
  }
  else {
    var pls = [null, null, null, null];
  }

  let [piles, setPiles] = useState([
    { accepts: [ItemTypes.CARD], topCard: pls[0] },
    { accepts: [ItemTypes.CARD], topCard: pls[1] },
    { accepts: [ItemTypes.CARD], topCard: pls[2] },
    { accepts: [ItemTypes.CARD], topCard: pls[3] },
  ])

  let [wildDialogueOpen, setWildDialogueOpen] = useState(false);
  let [wildCurrentCard, setWildCurrentCard] = useState(null);
  let [wildCurrentIndex, setWildCurrentIndex] = useState(null);

  // List of Cards in Player's hand.
  // type is used for the Drag and Drop Library.
  // name is most likely not needed anymore after I added the Card class.
  // Card class is also probably not 'needed' as it will already be a JS object
  //       when we receive it from the python backend but is useful for faking some cards before a connection has been made.
  const [pCards, setHand] = useState([
    { name: 'Two-Red', type: ItemTypes.CARD, card: new Card("red", 2) },
    { name: 'Three-Blue', type: ItemTypes.CARD, card: new Card("blue", 3) },
    { name: 'Wild', type: ItemTypes.CARD, card: new Card("Any", "NO", true, "wild") },
    { name: 'new-pile', type: ItemTypes.CARD, card: new Card("N/A", "NO", true, "new-pile") },
  ])

  // Helps with a card being dropped
  const [droppedCardNames, setDroppedCardNames] = useState([])
  function isDropped(cardName) {
    return droppedCardNames.indexOf(cardName) > -1
  }
  useEffect(
    () => {
      console.log("AFFECTED")
      console.log(props.pilez)
      console.log("EFFECT IS DONE")
      setPiles([
        { accepts: [ItemTypes.CARD], topCard: props.pilez[0] },
        { accepts: [ItemTypes.CARD], topCard: props.pilez[1] },
        { accepts: [ItemTypes.CARD], topCard: props.pilez[2] },
        { accepts: [ItemTypes.CARD], topCard: props.pilez[3] }])
    },
    [props])

  useEffect(
    () => {
      console.log(props.hand)
      if (props.hand !== undefined) {
        setHand(props.hand)
      }

    },
    [props])

  // Handles the dropping of a card.
  const handleDrop = useCallback(
    (index, item) => {
      setWildDialogueOpen(false);
      // This will need to be changed but it will communicate to the
      //       python backend what the player wants to do with their turn,
      //       in this case it is playing a card
      console.log(props.myTurn)
      if (item["card"]["details"] === "wild" || item["card"]["details"] === "draw4" || item["card"]["details"] === "drawUntil") {
        if (props.myTurn) {
          setWildCurrentCard(item["card"]);
          setWildCurrentIndex(index);
          setWildDialogueOpen(true);
        }
      }
      else {
        if (props.myTurn) {
          props.socket.emit('play-card', {"action": 1,
                                          "card": item["card"],
                                          "pile": index })
          }
      }

      // Here is where we actually update the topCard of the Pile.
      /*
      const { name } = item
        setDroppedCardNames(
          update(droppedCardNames, name ? { $push: [name] } : { $push: [] }),
        )
        setPiles(
          update(piles, {
            [index]: {
              topCard: {
                $set: item.card,
              },
            },
          }),

        )
        */
      },
      [droppedCardNames, piles],

    )
  return (
    <div>
      <div style={{ overflow: 'hidden', clear: 'both', alignItems: 'center', justifyContent: 'center', display: 'flex', height: '50vh' }}>
        <div style = {{
          height: '10rem',
          width: '8rem',
          border: '1px dashed gray',
          marginRight: '1.5rem',
          marginBottom: '1.5rem',
          padding: '1rem',
          textAlign: 'center',
          fontSize: '1rem',
          lineHeight: 'normal',
          float: 'left',
        }}
>
          <button onClick={() => drawClick(props.socket, props.myTurn)}><img height="157" width="108" src="http://localhost:3030/imgs/back.png"/></button>
        </div>
        {piles.map(({ accepts, topCard }, index) => (
          <Pile
            accept={accepts}
            topCard={topCard}
            onDrop={item => handleDrop(index, item)}
            key={index}
          />
        ))}
      </div>
        <div overflowX= "scroll" overflowY="hidden" maxHeight="300px" height="300px" backgroundColor="#076324" width = "100%">
        {pCards.map(({ name, type, card }, index) => (
          <PlayerCard
            name={name}
            type={type}
            isDropped={isDropped(name)}
            key={index}
            card={ card}
          />
        ))}
        </div>
      <WildDialogue should_be_open={wildDialogueOpen} socket={props.socket} card={wildCurrentCard} index={wildCurrentIndex}/>
    </div>
  )
}
export default Container
