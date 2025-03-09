import { Request, Response } from 'express';
import { OneDayPackage } from '../classes/OneDayPackage';
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

  // create dummy package
  const testPackage = new OneDayPackage(
    654321,
    'Alice Johnson',
    '789 Oak St',
    'Bob Brown',
    '101 Pine St',
    2.0,
    4.0,
    2.0
  );

  testPackage.updateStatus();

  res.render('package', {
    id: testPackage.getTrackingNumber(),
    type: testPackage.getShippingMethod(),
    status: testPackage.getStatus(),
    senderName: testPackage.getSenderName(),
    senderAddress: testPackage.getSenderAddress(),
    receiverName: testPackage.getReceiverName(),
    receiverAddress: testPackage.getReceiverAddress(),
    weight: testPackage.getWeight(),
    costPerUnitWeight: testPackage.getCostPerUnitWeight(),
    flatFee: testPackage.getFlatFee(),
  });
};

export const getAddPackagePage = (_req: Request, res: Response) => {
  res.render('package-add');
};
