const path = require('path')
const {spawn} = require('child_process')
const express = require('express')
const app = express()

// Run me with "node linkpython.js"

// This hosts all of the pictures of cards
app.use(express.static('public'))
/**
 * Run python script, pass in `-u` to not buffer console output
 * @return {ChildProcess}
 */
function runScript(){
  return spawn('python', [
    "-u",
    path.join('../backend', 'UnoClient.py'),
    "2",
  ]);
}

const io = require('socket.io')();

io.on('connection', (client) => {

  console.log('YES.')

  const subprocess = runScript()
  // print output of script
  subprocess.stdout.on('data', (data) => {
    data = data.toString();
    data = data.replace(/\\n/g, "\\n")
               .replace(/\\'/g, "\\'")
               .replace(/\\"/g, '\\"')
               .replace(/\\&/g, "\\&")
               .replace(/\\r/g, "\\r")
               .replace(/\\t/g, "\\t")
               .replace(/\\b/g, "\\b")
               .replace(/\\f/g, "\\f");
    data = data.replace(/[\u0000-\u0019]+/g,"");
    data = data.replace(/'/g, "\"")
    data = data.replace(/True/g,  "true")
              .replace(/False/g, "false")

    console.log(`${data}`)
    console.log(`data:${data}`);

    client.emit(`data`, data)

  });
  subprocess.stderr.on('data', (data) => {

    console.log(`error:${data}`);
  });
  subprocess.on('close', () => {
    console.log("Closed");
    client.emit('disconnection', "GOODBYE")
  });

  client.on('play-card', (data) => {
    console.log(data)
    subprocess.stdin.write(JSON.stringify(data) + '\r\n')
  })

  client.on('disconnect', () => {
    console.log("KILLING")
    subprocess.stdin.pause();
    subprocess.kill('SIGKILL');
  });
});
io.listen(1022);
app.listen(3030, () => console.log('Listening on port 3030'))
console.log("CAN YOU HEAR ME")
