import React from 'react';
import Button from '@material-ui/core/Button';
import Dialog from '@material-ui/core/Dialog';
import DialogActions from '@material-ui/core/DialogActions';
import DialogContent from '@material-ui/core/DialogContent';
import DialogContentText from '@material-ui/core/DialogContentText';
import DialogTitle from '@material-ui/core/DialogTitle';
import Slide from '@material-ui/core/Slide';
import { useEffect } from 'react'

const Transition = React.forwardRef(function Transition(props, ref) {
  return <Slide direction="up" ref={ref} {...props} />;
});

export default function WildDialogue(props) {
  const [open, setOpen] = React.useState(false);
  console.log("WILD THANG")
  const handleClickOpen = () => {
    setOpen(true);
  };

  const handleClose = () => {
    setOpen(false);
  };
  const handleCloseRed = () => {
    props.socket.emit('play-card', {"action": 1,
                                    "card": props.card,
                                    "pile": props.index,
                                    "color": "red"})
    setOpen(false);
  };
  const handleCloseBlue = () => {
    props.socket.emit('play-card', {"action": 1,
                                    "card": props.card,
                                    "pile": props.index,
                                    "color": "blue"})
    setOpen(false);
  };
  const handleCloseYellow = () => {
    props.socket.emit('play-card', {"action": 1,
                                    "card": props.card,
                                    "pile": props.index,
                                    "color": "yellow"})
    setOpen(false);
  };
  const handleCloseGreen = () => {
    props.socket.emit('play-card', {"action": 1,
                                    "card": props.card,
                                    "pile": props.index,
                                    "color": "green"})
    setOpen(false);
  };

  useEffect(() => {
    setOpen(props.should_be_open);
  }, [props.should_be_open])

  return (
    <div>
      <Dialog
        open={open}
        TransitionComponent={Transition}
        keepMounted
        onClose={handleClose}
        aria-labelledby="alert-dialog-slide-title"
        aria-describedby="alert-dialog-slide-description"
      >
        <DialogTitle id="alert-dialog-slide-title">{"Use Google's location service?"}</DialogTitle>
        <DialogContent>
          <DialogContentText id="alert-dialog-slide-description">
            Let Google help sell your information. This means sending valuable personal data to
            Google, even when turned off.
          </DialogContentText>
        </DialogContent>
        <DialogActions>
        <Button onClick={handleCloseRed} color="primary">
          Red
        </Button>
          <Button onClick={handleCloseBlue} color="primary">
            Blue
          </Button>
          <Button onClick={handleCloseGreen} color="primary">
            Green
          </Button>
          <Button onClick={handleCloseYellow} color="primary">
            Yellow
          </Button>
          <Button onClick={handleClose} color="primary">
            No Thanks
          </Button>
        </DialogActions>
      </Dialog>
    </div>
  );
}
