// Package Class

import { PackageStatus } from './enums/packageStatus';
import { ShippingMethod } from './enums/shippingMethod';
import { PackageImpl } from './implementations/PackageImpl';

export class Package extends PackageImpl {
  constructor(
    trackingNumber: number,
    senderName: string,
    senderAddress: string,
    receiverName: string,
    receiverAddress: string,
    weight: number,
    costPerUnitWeight: number,
    shippingMethod: ShippingMethod = ShippingMethod.Standard,
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
      shippingMethod,
      status
    );
  }
}
