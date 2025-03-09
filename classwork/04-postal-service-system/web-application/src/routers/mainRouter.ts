import express from 'express';
import {
  getHomePage,
  getLoginPage,
  getPackagesPage,
  getPackagePage,
  getAddPackagePage,
} from '../controllers/main-controller.js';

const mainRouter = express.Router();

mainRouter.get('/', getHomePage);
mainRouter.get('/login', getLoginPage);
mainRouter.get('/packages', getPackagesPage);
mainRouter.get('/package/add', getAddPackagePage);
mainRouter.get('/package/:id', getPackagePage);

export default mainRouter;
