// Two Day Package Class Implementation

import { Package } from './Package.js';
import { ITwoDayPackage } from '../interfaces/ITwoDayPackage.js';

import { ShippingMethod } from '../../lib/enums/ShippingMethod.js';
import { PackageStatus } from '../../lib/enums/PackageStatus.js';

export class TwoDayPackage extends Package implements ITwoDayPackage {
  // constructor

  constructor(
    protected trackingNumber: number,
    protected senderName: string,
    protected senderAddress: string,
    protected receiverName: string,
    protected receiverAddress: string,
    protected weight: number,
    protected costPerUnitWeight: number,
    protected flatFee: number, // extra flat fee data member
    protected shippingMethod: ShippingMethod = ShippingMethod.TwoDay,
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

  // overridden methods

  calculateCost(): number {
    // add flat fee and 10%
    return (super.calculateCost() + this.getFlatFee()) * 1.1;
  }

  printLabel(): void {
    console.log(`[Two Day Package Details]`);
    super.printLabel();
    console.log(`Flat Fee: $${this.getFlatFee()}`);
    console.log(`Two Day Package Extra % Fee: 10%`);
    console.log(`Total Cost: $${this.calculateCost()}`);
  }

  // extra methods

  getFlatFee(): number {
    return this.flatFee;
  }

  setFlatFee(flatFee: number): void {
    this.flatFee = flatFee;
  }
}
