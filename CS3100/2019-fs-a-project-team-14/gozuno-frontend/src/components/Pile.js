import React from 'react'
import { useDrop } from 'react-dnd'
import { checkCardCompatibility } from './Game'

// Style for each of the piles.
const style = {
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
}

// Finds the image associated with the card.
function getIMG(card) {
  let ending = "";
  if (card !== null) {
    console.log(card)
    // Parse through colors
    if (card['isSpecial'] === false) {
      if (card['color'] === 'red')
        ending = ending + "R"
      else if (card['color'] === 'blue')
          ending = ending + "B"
      else if (card['color'] === 'green')
          ending = ending + "G"
      else if (card['color'] === 'yellow')
          ending = ending + "Y"
      // Parse through numbers
      if (card['num'] === 1) {
        ending = ending + "1";
      }
      else if (card['num'] === 0) {
        ending = ending + '0';
      }
      else if (card['num'] === 2) {
        ending = ending + "2";
      }
      else if (card['num'] === 3) {
        ending = ending + "3";
      }
      else if (card['num'] === 4) {
        ending = ending + "4";
      }
      else if (card['num'] === 5) {
        ending = ending + "5";
      }
      else if (card['num'] === 6) {
        ending = ending + "6";
      }
      else if (card['num'] === 7) {
        ending = ending + "7";
      }
      else if (card['num'] === 8) {
        ending = ending + "8";
      }
      else if (card['num'] === 9) {
        ending = ending + "9";
      }
    }
    else {
      if (card['details'] === "wild") {
        if (card['color'] === null) {
          ending = "wild"
        }
        else if (card['color'] === "red") {
          ending="wildR"
        }
        else if (card['color'] === "blue") {
          ending = "wildB"
        }
        else if (card['color'] === "green") {
          ending = "wildG"
        }
        else if (card['color'] === "yellow") {
          ending = "wildY"
        }
      }
      else if (card['details'] === "new-pile") {
        ending = "+Deck"
      }
      else if (card['details'] === "draw4") {
        if (card['color'] === null) {
          ending = "+4"
        }
        else if (card['color'] === "red") {
          ending="+4R"
        }
        else if (card['color'] === "blue") {
          ending = "+4B"
        }
        else if (card['color'] === "green") {
          ending = "+4G"
        }
        else if (card['color'] === "yellow") {
          ending = "+4Y"
        }
      }
      else if (card['details'] === "reverse") {
        if (card['color'] === "red") {
          ending = "Rr"
        }
        else if (card['color'] === "blue") {
          ending = "Br"
        }
        else if (card['color'] === "green") {
          ending = "Gr"
        }
        else if (card['color'] === "yellow") {
          ending = "Yr"
        }
      }
      else if (card['details'] === 'skip') {
        if (card['color'] === "red") {
          ending = "RSkip"
        }
        else if (card['color'] === "blue") {
          ending = "BSkip"
        }
        else if (card['color'] === "green") {
          ending = "GSkip"
        }
        else if (card['color'] === "yellow") {
          ending = "YSkip"
        }
      }
      else if (card['details'] === "draw2") {
        if (card['color'] === "red") {
          ending = "R+2"
        }
        else if (card['color'] === "blue") {
          ending = "B+2"
        }
        else if (card['color'] === "green") {
          ending = "G+2"
        }
        else if (card['color'] === "yellow") {
          ending = "Y+2"
        }
      }
      else if (card['details'] === "drawUntil") {
        if (card['color'] === null) {
          ending = "DrawColor"
        }
        else if (card['color'] === "red") {
          ending="DrawColorR"
        }
        else if (card['color'] === "blue") {
          ending = "DrawColorB"
        }
        else if (card['color'] === "green") {
          ending = "DrawColorG"
        }
        else if (card['color'] === "yellow") {
          ending = "DrawColorY"
        }

      }
      else if (card['details'] == "draw4") {
        if (card['details'] === null)
          ending = "+4"
        else if (card['color'] === "red")
          ending="+4R"
        else if (card['color'] === "blue")
          ending = "+4B"
        else if (card['color'] === "green")
          ending = "+4G"
        else if (card['color'] === "yellow")
          ending = "+4Y"
      }
      else if (card['details'] == "swapDirection") {
        if (card['color'] === "red") {
          ending = "RSwap"
        }
        else if (card['color'] === "blue") {
          ending = "BSwap"
        }
        else if (card['color'] === "green") {
          ending = "GSwap"
        }
        else if (card['color'] === "yellow") {
          ending = "YSwap"
        }
      }
      else if (card['details'] == "allDraw+-2") {
        if (card['color'] === "red") {
          ending = "R+-"
        }
        else if (card['color'] === "blue") {
          ending = "B+-"
        }
        else if (card['color'] === "green") {
          ending = "G+-"
        }
        else if (card['color'] === "yellow") {
          ending = "Y+-"
        }
      }
    }
    let url = "http://localhost:3030/imgs/" + ending + ".png";
    console.log(url)
    return url
  }

}

// Pile classunction (class/function)
const Pile = ({ accept, topCard, onDrop, card }) => {
  // Variables for Drag and Drop, only important thing is the canDrop function which uses the checkCardCompatibility function in Game.js
  const [{ isOver, canDrop, item }, drop] = useDrop({
    accept,
    drop: onDrop,
    canDrop: () => checkCardCompatibility(topCard, item),
    collect: monitor => ({
      isOver: monitor.isOver(),
      canDrop: monitor.canDrop(),
      item: monitor.getItem(),
    }),
  })
  // Used to change backend on hover and if dropable
  const isActive = isOver && canDrop
  let backgroundColor = 'transparent'
  if (isActive) {
    backgroundColor = 'darkgreen'
  } else if (canDrop) {
    backgroundColor = 'darkkhaki'
  }
  // Pretty self explanatory but shows the information for debugging purposes. Should be removed
  if (isActive) {
    return (
      <div ref={drop} style={{ ...style, backgroundColor }}>
      </div>
    )
  }

  return (
    <div ref={drop} style={{ ...style, backgroundColor }}>
       <img height="157" width="108" alt="" src={getIMG(topCard)}></img>
    </div>
  )
}
export default Pile
