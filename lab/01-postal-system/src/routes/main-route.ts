// Filename: main-route.ts

import express from 'express';
import { getIndex, getPackage } from '../controllers/main-controller.js';

const mainRoute = express.Router();

mainRoute.get('/', getIndex);
mainRoute.get('/package/:tracking', getPackage);

export default mainRoute;
