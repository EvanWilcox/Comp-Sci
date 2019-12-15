import React, { Component, Fragment } from "react"
import Header from "./Layouts/Header"
import NavTabs from "./Layouts/NavTabs"
import Footer from "./Layouts/Footer"
import CssBaseline from '@material-ui/core/CssBaseline';

export default props => 
    <Fragment align="center">        
        <Header />
        <NavTabs />
        <footer>
        <Footer align="center" />
        </footer>
    </Fragment>
