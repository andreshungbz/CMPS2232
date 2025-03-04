import express from 'express';
import path from 'path';
const app = express();
const PORT = 3000;
app.use(express.static(path.join(process.cwd(), 'public')));
app.set('view engine', 'ejs');
app.set('views', path.join(process.cwd(), 'views'));
app.get('/', (_req, res) => {
    res.send('Postal Service');
});
app.get('/login', (_req, res) => {
    res.render('login');
});
app.get('/packages', (_req, res) => {
    res.render('packages');
});
app.get('/package/1', (_req, res) => {
    res.render('package');
});
app.get('/add', (_req, res) => {
    res.render('add-package');
});
app.listen(PORT, () => {
    console.log(`Server started at http://localhost:${PORT}`);
});
