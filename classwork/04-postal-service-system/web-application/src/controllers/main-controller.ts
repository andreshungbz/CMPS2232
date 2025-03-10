import { Request, Response } from 'express';
import { OneDayPackage } from '../classes/package-one-day/OneDayPackage';
import { data } from '../utils/data';

export const getHomePage = (_req: Request, res: Response) => {
  res.render('index');
};

export const getLoginPage = (_req: Request, res: Response) => {
  res.render('login');
};

export const getPackagesPage = (_req: Request, res: Response) => {
  res.render('packages', { packages: data });
};

export const getPackagePage = (req: Request, res: Response) => {
  const packageID = Number(req.params.id);

  if (isNaN(packageID)) {
    res.status(400).send('Faulty Package ID');
    return;
  }

  // Find the package in the test data
  const pkg = data.find((p) => p.getTrackingNumber() === packageID);

  if (!pkg) {
    res.status(404).send('Package not found');
    return;
  }

  res.render('package', {
    id: pkg.getTrackingNumber(),
    type: pkg.constructor.name,
    status: pkg.getStatus(),
    senderName: pkg.getSenderName(),
    senderAddress: pkg.getSenderAddress(),
    receiverName: pkg.getReceiverName(),
    receiverAddress: pkg.getReceiverAddress(),
    weight: pkg.getWeight(),
    costPerUnitWeight: pkg.getCostPerUnitWeight(),
    flatFee: pkg instanceof OneDayPackage ? pkg.getFlatFee() : undefined,
  });
};

export const getAddPackagePage = (_req: Request, res: Response) => {
  res.render('package-add');
};
