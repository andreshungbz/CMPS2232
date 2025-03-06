import { IOneDayPackage } from './interfaces/IOneDayPackage';
import { OneDayPackageImpl } from './implementations/OneDayPackageImpl';

export class OneDayPackage extends OneDayPackageImpl implements IOneDayPackage {
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
