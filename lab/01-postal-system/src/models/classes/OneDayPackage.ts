// One Day Package Class Implementation

import { Package } from './Package.js';
import { IOneDayPackage } from '../interfaces/IOneDayPackage.js';

import { ShippingMethod } from '../../lib/enums/ShippingMethod.js';
import { PackageStatus } from '../../lib/enums/PackageStatus.js';

export class OneDayPackage extends Package implements IOneDayPackage {
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
    protected shippingMethod: ShippingMethod = ShippingMethod.OneDay,
    protected status: PackageStatus = PackageStatus.Created
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
    return (super.calculateCost() + this.flatFee) * 1.2;
  }

  printLabel(): void {
    console.log(`[One Day Package Details]`);
    console.log(`Shipping Method: ${this.shippingMethod}`);
    console.log(`Status: ${this.status}`);
    console.log(
      `From ${this.senderName} (${this.senderAddress}) to ${this.receiverName} (${this.senderAddress})`
    );
    console.log(`Weight (lbs): ${this.weight}`);
    console.log(`Cost Per Unit Weight: $${this.costPerUnitWeight}`);
    console.log(`Flat Fee: $${this.flatFee}`);
    console.log(`One Day Package Extra % Fee: 20%`);

    console.log(`Total Cost: $${this.calculateCost()}`);
  }
}
