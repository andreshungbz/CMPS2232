// One Day Package Class

import { PackageStatus } from './enums/packageStatus';
import { ShippingMethod } from './enums/shippingMethod';
import { OneDayPackageImpl } from './implementations/OneDayPackageImpl';

export class OneDayPackage extends OneDayPackageImpl {
  constructor(
    trackingNumber: number,
    senderName: string,
    senderAddress: string,
    receiverName: string,
    receiverAddress: string,
    weight: number,
    costPerUnitWeight: number,
    flatFee: number,
    shippingMethod: ShippingMethod = ShippingMethod.OneDay,
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
