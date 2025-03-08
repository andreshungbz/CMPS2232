// Two Day Package Class Implementation

import { PackageStatus } from '../enums/packageStatus';
import { ShippingMethod } from '../enums/shippingMethod';
import { ITwoDayPackage } from '../interfaces/ITwoDayPackage';

import { PackageImpl } from './PackageImpl';

export class TwoDayPackageImpl extends PackageImpl implements ITwoDayPackage {
  // constructor

  constructor(
    protected trackingNumber: number,
    protected senderName: string,
    protected senderAddress: string,
    protected receiverName: string,
    protected receiverAddress: string,
    protected weight: number,
    protected costPerUnitWeight: number,
    protected flatFee: number, // extra flat fee data member is declared here and set in constructor
    protected shippingMethod: ShippingMethod,
    protected status: PackageStatus
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

  // extra methods

  getFlatFee(): number {
    return this.flatFee;
  }

  setFlatFee(flatFee: number): void {
    this.flatFee = flatFee;
  }

  // overridden methods

  calculateCost(): number {
    return (super.calculateCost() + this.flatFee) * 1.1;
  }

  printLabel(): void {
    console.log(`[Two Day Package Details]`);
    console.log(`Shipping Method: ${this.shippingMethod}`);
    console.log(`Status: ${this.status}`);
    console.log(
      `From ${this.senderName} (${this.senderAddress}) to ${this.receiverName} (${this.senderAddress})`
    );
    console.log(`Weight (lbs): ${this.weight}`);
    console.log(`Cost Per Unit Weight: $${this.costPerUnitWeight}`);
    console.log(`Flat Fee: $${this.flatFee}`);
    console.log(`Two Day Package Extra % Fee: 10%`);

    console.log(`Total Cost: $${this.calculateCost()}`);
  }
}
