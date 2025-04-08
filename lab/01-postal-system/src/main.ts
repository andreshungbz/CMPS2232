import express from 'express';
import path from 'path';

import logger from './middleware/logger.js';
import missingRoute from './middleware/missingRoute.js';
import getLocalIPAddress from './utils/getLocalIPAddress.js';
import mainRoute from './routes/main-route.js';

const app = express();
const PORT = 3000;

// EJS templating
app.set('view engine', 'ejs');
app.set('views', path.join(process.cwd(), 'views'));

// static folder
app.use(express.static(path.join(process.cwd(), 'public')));

app.use(express.urlencoded({ extended: true })); // required to parse HTML form data
app.use(logger); // log time and route of every request

app.use(mainRoute);

// handle non-existent routes
app.use(missingRoute);

// start server
app.listen(PORT, () => {
  console.log(
    `[PS] Postal System running at http://${getLocalIPAddress()}:${PORT}`
  );
});
