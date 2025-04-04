// Filename: mainRoute.ts

import express from 'express';
import {
  getIndex,
  addEmployee,
  getEmployee,
} from '../controllers/mainController.js';

const mainRoute = express.Router();

mainRoute.get('/', getIndex);
mainRoute.post('/add-employee', addEmployee);
mainRoute.get('/employee/:id', getEmployee);

export default mainRoute;
