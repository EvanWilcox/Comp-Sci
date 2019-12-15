import React from "react"
import Typography from '@material-ui/core/Typography';
import AppBar from '@material-ui/core/AppBar';
import Toolbar from '@material-ui/core/Toolbar';

export default props =>
  <Toolbar display="flex" alignItems="center" justify="center" borderBottom='1px solid ${theme.palette.grey[300]}'>
    <Typography style={{
                    float       : 'none',
                    width       : '700px',
                    marginLeft  : 'auto',
                    marginRight : 'auto'
                }} flex="1" component="h2" variant="h5" color="inherit" align="center" nowrap>
      Amp! it up Stats
    </Typography>
  </Toolbar>
