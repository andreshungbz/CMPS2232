import express from 'express';
import path from 'path';
import logger from './middleware/logger.js';
import getLocalIP from './utils/getLocalIP.js';
import mainRouter from './routers/mainRouter.js';

const app = express();
const PORT = 3000;

app.use(express.static(path.join(process.cwd(), 'public')));
app.set('view engine', 'ejs');
app.set('views', path.join(process.cwd(), 'views'));

app.use(express.urlencoded({ extended: true }));
app.use(logger);

app.use('/', mainRouter);

app.listen(PORT, () => {
  console.log(`Server started at http://${getLocalIP()}:${PORT}`);
});
