// Filename: main-controller.ts

import { Request, Response } from 'express';
import {
  deletePackage,
  readPackage,
  readPackages,
} from '../models/package-model.js';

export const getIndex = async (_req: Request, res: Response) => {
  try {
    const packages = await readPackages();
    res.render('index', { packages });
  } catch (error) {
    res.render('error', { error });
  }
};

export const postPackage = async (_req: Request, res: Response) => {
  try {
  } catch (error) {
    res.render('error', { error });
  }
};

export const getPackage = async (req: Request, res: Response) => {
  try {
    const trackingNumber = Number(req.params.tracking);
    if (isNaN(trackingNumber)) throw new Error('Invalid Tracking Number');

    const pkg = await readPackage(trackingNumber);

    res.render('package', {
      package: pkg,
      shippingMethod: pkg.getShippingMethod(),
    });
  } catch (error) {
    res.render('error', { error });
  }
};

export const patchStatus = async (req: Request, res: Response) => {
  try {
    const trackingNumber = Number(req.params.tracking);
    if (isNaN(trackingNumber)) throw new Error('Invalid Tracking Number');

    const pkg = await readPackage(trackingNumber);
    await pkg.updateStatus();

    res.redirect(req.originalUrl);
  } catch (error) {
    res.render('error', { error });
  }
};

export const removePackage = async (req: Request, res: Response) => {
  try {
    const trackingNumber = Number(req.params.tracking);
    if (isNaN(trackingNumber)) throw new Error('Invalid Tracking Number');

    await deletePackage(trackingNumber);

    res.redirect('/');
  } catch (error) {
    res.render('error', { error });
  }
};
