// Two Day Package Class

import { PackageStatus } from './enums/packageStatus';
import { ShippingMethod } from './enums/shippingMethod';
import { TwoDayPackageImpl } from './implementations/TwoDayPackageImpl';

export class TwoDayPackage extends TwoDayPackageImpl {
  constructor(
    trackingNumber: number,
    senderName: string,
    senderAddress: string,
    receiverName: string,
    receiverAddress: string,
    weight: number,
    costPerUnitWeight: number,
    flatFee: number,
    shippingMethod: ShippingMethod = ShippingMethod.TwoDay,
    status: PackageStatus = PackageStatus.Created
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
