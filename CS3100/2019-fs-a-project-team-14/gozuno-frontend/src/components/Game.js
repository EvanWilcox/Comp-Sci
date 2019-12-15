// This is where I copied over some of the python functions into javascript
//     that will need to be run quite often.


// This will most likely need to be updated often but see the python file
export function checkCardCompatibility(pileCard, playerCard) {
  console.log(pileCard);
  console.log(playerCard);
  if (playerCard === null) {
    return false;
  }
  if (playerCard.card.details === "new-pile" && pileCard == null) {
    return true;
  }
  if (pileCard === null) {
    return false;
  }
  playerCard = playerCard.card
  console.log(playerCard)
  if(!playerCard.isSpecial) {
      if (playerCard.color == pileCard.color ){
        return true
      }
      else if (playerCard.num == pileCard.num) {
          return true
      }
      else {
          return false
      }
  }
  else if (playerCard.details === "draw2" || playerCard.details === "skip" || playerCard.details === "reverse" || playerCard.details === "allDraw+-2" || playerCard.details === "swapDirection") {
      if (playerCard.color == pileCard.color)
          return true
      else if (playerCard.details === pileCard.details)
          return true
  }
  else {
      if (playerCard.details === "wild" || playerCard.details === "draw4" || playerCard.details === "drawUntil")
          return true
      else if (playerCard.details == "new-pile") {
          if (pileCard === null)
              return true
          else
              return playerCard.color === pileCard.color
      }
      else
          return playerCard.color === pileCard.color
  }

}


// Card class serving no useful purpose besides making cards before connection to backend.
export class Card{
  constructor(color, num, special=false, details = "notspecial"){
    this.color = color
    this.num = num
    this.isSpecial = special
    this.details = details
  }
}
