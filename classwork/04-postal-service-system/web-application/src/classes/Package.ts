import { IPackage } from './interfaces/IPackage';
import { PackageImpl } from './implementations/PackageImpl';

export class Package extends PackageImpl implements IPackage {
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
