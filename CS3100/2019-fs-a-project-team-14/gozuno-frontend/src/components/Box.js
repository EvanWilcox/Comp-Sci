import React from 'react'
import { useDrag } from 'react-dnd'

// Styles for the player's cards.
const style = {
  border: '1px dashed gray',
  padding: '0.5rem 1rem',
  marginRight: '0.5rem',
  marginBottom: '0.5rem',
  cursor: 'move',
  float: 'left',
  display: 'table-row',
}


// This function is declared twice but it shouldn't be, see Pile.js
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
      if (card['details'] === "wild")
        ending = "wild"
      else if (card['details'] === "new-pile") {
        ending = "+Deck"
      }
      else if (card['details'] === "draw4") {
        ending = "+4"
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
        ending = "DrawColor"
      }
      else if (card['details'] == "draw4") {
        ending = "+4"
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

// PlayerCard classunction (class/function)
const PlayerCard = ({ card, name, type, isDropped }) => {
  // Stuff for Drag and Drop
  const [{ opacity }, drag] = useDrag({
    item: { card, name, type },
    collect: monitor => ({
      opacity: monitor.isDragging() ? 0.4 : 1,
    }),
  })
  // Helps with card 'deletion'

  return (
   (<div ref={drag} style={{ ...style, opacity }}><img width="108" height="157" src={getIMG(card)}></img> </div>)
 )

}
export default PlayerCard
