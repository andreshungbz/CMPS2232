import { ITwoDayPackage } from './interfaces/ITwoDayPackage';
import { TwoDayPackageImpl } from './implementations/TwoDayPackageImpl';

export class TwoDayPackage extends TwoDayPackageImpl implements ITwoDayPackage {
  constructor(
    trackingNumber: number,
    senderName: string,
    senderAddress: string,
    receiverName: string,
    receiverAddress: string,
    weight: number,
    costPerUnitWeight: number,
    flatFee: number,
    shippingMethod: string = '',
    status: string = ''
  ) {
    super(
      trackingNumber,
      senderName,
      senderAddress,
      receiverName,
      receiverAddress,
      weight,
      costPerUnitWeight,
      flatFee,
      shippingMethod,
      status
    );
  }
}
