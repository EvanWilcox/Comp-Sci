import React from "react"
import Typography from '@material-ui/core/Typography';
import Toolbar from '@material-ui/core/Toolbar';


export default props =>
  <div backgroundColor="#000000">
  <Toolbar backgroundColor="#000000" display="flex" alignItems="center" justify="center">
    <Typography style={{
                    fontFamily : "Comic Sans MS",
                    float       : 'none',
                    width       : '700px',
                    marginLeft  : 'auto',
                    marginRight : 'auto',
                    color       : "white"
                }} flex="1" component="h2" variant="h2" color="inherit" align="center" nowrap>
      GUNO
    </Typography>
    <Typography style={{
                    fontFamily : "Comic Sans MS",
                    float       : 'none',
                    width       : '700px',
                    marginLeft  : 'auto',
                    marginRight : 'auto',
                    color       : "white"
                }} flex="1" component="h5" variant="h5" color="inherit" align="center" nowrap>
      An offical game from Michael Gosnell's CS3100 Fall 2019 Section A Computer Science Course
    </Typography>
  </Toolbar>
  </div>
