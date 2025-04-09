// Filename: main-controller.ts

import { Request, Response } from 'express';

import {
  deletePackage,
  readNextTrackingNumber,
  readPackage,
  readPackages,
} from '../models/package-model.js';

import { ShippingMethod } from '../lib/enums/ShippingMethod.js';
import { OneDayPackage } from '../models/classes/OneDayPackage.js';
import { TwoDayPackage } from '../models/classes/TwoDayPackage.js';

export const getIndex = async (_req: Request, res: Response) => {
  try {
    const packages = await readPackages();
    res.render('index', { packages });
  } catch (error) {
    res.render('error', { error });
  }
};

export const getAddPackage = (_req: Request, res: Response) => {
  res.render('add-package');
};

export const postPackage = async (req: Request, res: Response) => {
  try {
    const {
      shippingMethod,
      senderName,
      senderAddress,
      receiverName,
      receiverAddress,
      weight,
      costPerUnitWeight,
      flatFee,
    } = req.body;

    const trackingNumber = await readNextTrackingNumber();

    let pkg;
    switch (shippingMethod) {
      case ShippingMethod.OneDay:
        pkg = new OneDayPackage(
          trackingNumber,
          senderName,
          senderAddress,
          receiverName,
          receiverAddress,
          weight,
          costPerUnitWeight,
          flatFee
        );
        break;
      case ShippingMethod.TwoDay:
        pkg = new TwoDayPackage(
          trackingNumber,
          senderName,
          senderAddress,
          receiverName,
          receiverAddress,
          weight,
          costPerUnitWeight,
          flatFee
        );
        break;
      default:
        throw new Error('Invalid Shipping Method');
    }

    await pkg.createRecord();

    res.redirect('/');
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
      pkg,
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

    res.redirect(`/package/${trackingNumber}`);
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
