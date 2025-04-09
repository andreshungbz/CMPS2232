// Filename: main-route.ts

import express from 'express';
import {
  getIndex,
  getAddPackage,
  getPackage,
  patchStatus,
  postPackage,
  removePackage,
} from '../controllers/main-controller.js';

const mainRoute = express.Router();

mainRoute.get('/', getIndex);
mainRoute.get('/package/add', getAddPackage);
mainRoute.post('/package/add', postPackage);
mainRoute.get('/package/:tracking', getPackage);
mainRoute.post('/package/:tracking/update', patchStatus);
mainRoute.post('/package/:tracking/delete', removePackage);

export default mainRoute;
