import React from 'react';
import './App.css';
import Container from './Container'
import { DndProvider } from 'react-dnd'
import HTML5Backend from 'react-dnd-html5-backend'
import openSocket from 'socket.io-client'
import { Card } from './Game'
import decode from 'jsonpickle'
import ItemTypes from './ItemTypes'
import OpponentHand from './OpponentHand'
import Header from './Header'
import Typography from '@material-ui/core/Typography';
import AdSense from 'react-adsense'

function YouTubeVID (youtubeId) {
  return (
    <div
      className="video"
      style={{
        position: "relative",
        paddingBottom: "56.25%" /* 16:9 */,
        paddingTop: 25,
        height: 0
      }}
    >
      <iframe
        style={{
          position: "absolute",
          top: 0,
          left: 0,
          width: "100%",
          height: "100%"
        }}
        src={`https://www.youtube.com/embed/${youtubeId.ID}?rel=0;&autoplay=1&mute=1`}
        frameBorder="0"
      />
    </div>
  );
};

// App class that actually does the connection to backend
class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      // Hard coded but connects to the link python node server.
      socket: openSocket('localhost:1022'),
      piles: [null,null,null,null],// These will need to be passed to the apropriate functions but not used currently
      hand: [],       // These will need to be passed to the apropriate functions but not used currently
      myID: -1,
      myTurn: false,
      amWinner: false,
      currentPlayer: -3
    }

    console.log(decode)
    this.state.piles = [new Card("red", 2),new Card("red", 2),new Card("red", 2),new Card("red", 2)]

    console.log("CONSTRUCTED")

    // This might not be used, its not implemented on the linkpython node server so wont ever be called
    this.state.socket.on('init', () => {
      console.log("RECEIVED INITIAL GAME STATE INFO")
    });
    // this is where all data will be received from the backend.

  }
  componentDidMount() {
      // TODO: remove this if not needed by anything else.
      this.state.socket.on('connect', () => {
        console.log("CONNECTED!!!!!!")
        this.setState({ piles: [new Card("red", 2),new Card("red", 2),new Card("red", 2),new Card("red", 2)] },
                        () => {console.log(this.state.piles)})
        // LETS DO SOME STUFF HERE
      });
      this.state.socket.on(`data`, (data) => {
        console.log(data);
        console.log("HERE WE GO BB")
        let parseddata = null;

        // TODO: implement all the possibilities.
        try {
          console.log("JUST RECEIVED SOME IMPORTANT INFORMATION")
          console.log(data);
          if ((data) === "\"game\"" || data === "Error: \"game\"") {
            console.log("GAME END!")
            this.setState({ amWinner: false, myID: -2})
          }
          data = JSON.parse(data)
          // Check to make sure messageType is in the data before checking it.
          if (data["messageType"]) {
            // Do all game-state related updates

            if (data['messageType'] === "whois") {
              this.setState({ myID: data['data']['id']})
              console.log("MY ID IS")
              console.log(data['data']['id'])
            }

          }
          else if (data["gameWinner"]) {
            console.log("Game is over");
            console.log(data['gameWinner'])
            this.setState({ amWinner: true, myID: -1})
          }
          else if (data["currentPlayer"]) {
            console.log("Received Game State Update.")
            console.log(this.state.myID)
            this.setState({currentPlayer: data["currentPlayer"]["PlayerID"]})
            var myHand = []
            var player
            var my_turn = false
            if (data["currentPlayer"]["PlayerID"] == this.state.myID) {
              my_turn = true;
              console.log(data["currentPlayer"]["hand"])
              for (var card in data["currentPlayer"]["hand"]) {
                console.log(data["currentPlayer"]["hand"][card])
                var cardObj = {name: "card", type:ItemTypes.CARD }
                cardObj.card = data["currentPlayer"]["hand"][card]
                myHand.push(cardObj)
              }
            }
            for (player in data["players"]) {
              console.log(data["players"][player]["PlayerID"]);
              if (data["players"][player]["PlayerID"] === this.state.myID) {
                console.log("FOUND MYSELF")
                console.log(data["players"][player]["hand"])
                for (var card in data["players"][player]["hand"]) {
                  var cardObj = {name: "card", type:ItemTypes.CARD }
                  cardObj.card = data["players"][player]["hand"][card]
                  myHand.push(cardObj)
                }
              }
            }
            console.log("HERES MY NEW HAND")
            console.log(myHand)
            var updatedPiles = []
            for ( var pile in data["piles"]) {
              updatedPiles.push(data["piles"][pile]["topCard"])
            }
            this.setState({ piles: updatedPiles, hand: myHand, myTurn: my_turn},
                            () => {console.log(this.state.piles)})
            console.log("DONE : )")
          }

        }
        catch(error) {
          console.error("Was expecting JSON, received," + data);
          console.error(error);
        }
      });
  }
  render() {
    return (
      <div className="App" style={{height: "15vh", backgroundColor: "#000000"}}>
        <Header />
        <div style={{minHeight: "91vh", backgroundColor: "#076324"}}>
          <script data-ad-client="ca-pub-1803462285841732" async src="https://pagead2.googlesyndication.com/pagead/js/adsbygoogle.js%22%3E"/>
          <AdSense.Google
            client='ca-pub-1803462285841732'
            slot='7806394673'
          />

          <div style={{height:"10vh"}}> </div>
        <Typography style={{
                        fontFamily : "Comic Sans MS",
                        float       : 'none',
                        width       : '700px',
                        marginLeft  : 'auto',
                        marginRight : 'auto',
                        color       : "white"
                    }} flex="1" component="h5" variant="h5" color="inherit" align="center" nowrap>
          {this.state.myID !== -1 && !this.state.amWinner && this.state.myID !== -2 && (this.state.myTurn ? "Gosnell say: Hurry up, we have an Office Space clip to watch" : `Gosnell say: Let Player: ${this.state.currentPlayer} answer this one`)}
          {this.state.myID === -1 && !this.state.amWinner && ("While the game server is getting ready, here is an Office Space clip:")}
          {this.state.myID === -1 && !this.state.amWinner && (<YouTubeVID ID="_iiOEQOtBlQ"/>)}

        </Typography>
        {this.state.amWinner && (<img src="http://localhost:3030/imgs/Winner.png"/>)}
        {!this.state.amWinner && this.state.myID === -2 && (<img src="http://localhost:3030/imgs/Loser.png"/>)}
          <DndProvider backend={HTML5Backend}>
            {this.state.myID !== -1 && this.state.myID !== -2 && (<Container pilez={this.state.piles} hand={this.state.hand} myTurn={this.state.myTurn} socket={this.state.socket}/>)}
          </DndProvider>
        </div>
        <script async src="//pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
      </div>
    );
  }
}

export default App;
